package com.github.ksueclub.magneticchess.voicecontrol

import android.util.Log
import kotlin.experimental.or

object MoveTranscoder {
    private val fluffWords = arrayOf("please", "move", "my", "um", "uh")
    private val prepositionTo = arrayOf("to", "two", "too", "2")
    private val prepositionFrom = arrayOf("from")
    private val rowWords = arrayOf(
        arrayOf("1", "one", "won", "run"),
        arrayOf("2", "two", "too", "to"),
        arrayOf("3", "three", "tree"),
        arrayOf("4", "four", "for"),
        arrayOf("5", "five"),
        arrayOf("6", "six"),
        arrayOf("7", "seven"),
        arrayOf("8", "eight", "ate")
    )
    private val colWords = arrayOf(
        arrayOf("a", "alpha", "alfa"),
        arrayOf("b", "be", "bee", "bravo"),
        arrayOf("c", "see", "sea", "charlie"),
        arrayOf("d", "dee", "delta"),
        arrayOf("e", "echo"),
        arrayOf("f", "foxtrot"),
        arrayOf("g", "golf")
    )
    private val pieceWords = arrayOf(
        arrayOf("rook"),
        arrayOf("knight", "night"),
        arrayOf("bishop"),
        arrayOf("queen"),
        arrayOf("king"),
        arrayOf("pawn")
    )

    enum class State {
        Initial,
        AfterTo,
        AfterFrom,
    }

    fun transcode(sentence: String, white: Boolean, purple: Boolean, arr: ByteArray): Boolean {
        val words = mutableListOf<String>()
        sentence.splitToSequence(' ').forEach {_it ->
            var part = _it
            while (part.any { it in '0'..'9' }) {
                val first = part.takeWhile { it !in '0'..'9' }
                if (first.isNotEmpty()) {
                    words.add(first.toLowerCase())
                }
                part = part.substring(first.length)
                val num = part.takeWhile { it in '0'..'9' }
                words.add(num)
                part = part.substring(num.length)
            }
            if (part.isNotEmpty()) {
                words.add(part.toLowerCase())
            }
        }
        var state = State.Initial
        var piece = 0
        var fromX = 0
        var fromY = 0
        var toX = 0
        var toY = 0
        words.forEach {
            if (!fluffWords.contains(it)) {
                when (state) {
                    State.Initial -> {
                        val pieceIdx = pieceWords.indexOfFirst { it2 -> it2.contains(it) }
                        when {
                            pieceIdx >= 0 -> {
                                if (piece == 0) {
                                    piece = pieceIdx + 1
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate piece word")
                                    return false
                                }
                            }
                            prepositionFrom.contains(it) -> {
                                if (fromX == 0) {
                                    state = State.AfterFrom
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate from word")
                                    return false
                                }
                            }
                            prepositionTo.contains(it) -> {
                                if (toX == 0) {
                                    state = State.AfterTo
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate to word")
                                    return false
                                }
                            }
                            else -> {
                                Log.e("MoveTranscoder", String.format("Unknown word %s", it))
                                return false
                            }
                        }
                    }
                    State.AfterTo -> {
                        val rowIdx = rowWords.indexOfFirst { it2 -> it2.contains(it) }
                        val colIdx = colWords.indexOfFirst { it2 -> it2.contains(it) }
                        when {
                            rowIdx >= 0 -> {
                                if (toY == 0) {
                                    toY = rowIdx + 1
                                    if (toX != 0) {
                                        state = State.Initial
                                    }
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate to row word")
                                    return false
                                }
                            }
                            colIdx >= 0 -> {
                                if (toX == 0) {
                                    toX = colIdx + 1
                                    if (toY != 0) {
                                        state = State.Initial
                                    }
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate to column word")
                                    return false
                                }
                            }
                            else -> {
                                Log.e("MoveTranscoder", String.format("Unknown word %s", it))
                                return false
                            }
                        }
                    }
                    State.AfterFrom -> {
                        val rowIdx = rowWords.indexOfFirst { it2 -> it2.contains(it) }
                        val colIdx = colWords.indexOfFirst { it2 -> it2.contains(it) }
                        when {
                            rowIdx >= 0 -> {
                                if (fromY == 0) {
                                    fromY = rowIdx + 1
                                    if (fromX != 0) {
                                        state = State.Initial
                                    }
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate from row word")
                                    return false
                                }
                            }
                            colIdx >= 0 -> {
                                if (fromX == 0) {
                                    fromX = colIdx + 1
                                    if (fromY != 0) {
                                        state = State.Initial
                                    }
                                } else {
                                    Log.e("MoveTranscoder", "Duplicate from column word")
                                    return false
                                }
                            }
                            else -> {
                                Log.e("MoveTranscoder", String.format("Unknown word %s", it))
                                return false
                            }
                        }
                    }
                }
            }
        }
        if (piece == 0 || ((fromX == 0) != (fromY == 0)) || toX == 0 || toY == 0) {
            Log.e("MoveTranscoder", "Not enough information was conveyed")
            return false
        }
        arr[0] = piece.toByte()
        if (white) {
            arr[0] = arr[0] or ABI.MoveFlagWhite
        }
        if (purple) {
            arr[0] = arr[0] or ABI.MoveFlagPurple
        }
        if (fromX != 0) {
            arr[0] = arr[0] or ABI.MoveFlagFrom
        }
        arr[1] = ((fromX shl 4) or fromY).toByte()
        arr[2] = ((toX shl 4) or toY).toByte()
        return true
    }
}
