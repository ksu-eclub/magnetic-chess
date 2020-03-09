package com.github.ksueclub.magneticchess.voicecontrol

import java.util.*

object ABI {
    val ServiceUUID = UUID.fromString("3b1abb0e-46ce-4c15-b728-a170e6713c10")
    val StateUUID = UUID.fromString("e7a27133-53fd-493e-a972-f4e7bd472f5d")
    val MoveUUID = UUID.fromString("5e832f71-fa61-4032-b35e-4cfa9f410f76")
    val StateUnknown: Byte = 0
    val StateWhite: Byte = 1
    val StatePurple: Byte = 2
    val StateTurn: Byte = 4
    val StateInvalid: Byte = 8
    val MovePieceBits: Byte = 3
    val MoveFlagWhite: Byte = (1 shl 4)
    val MoveFlagPurple: Byte = (1 shl 5)
    val MoveFlagFrom: Byte = (1 shl 6)
}
