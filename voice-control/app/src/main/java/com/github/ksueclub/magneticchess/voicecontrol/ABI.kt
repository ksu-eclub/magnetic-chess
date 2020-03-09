package com.github.ksueclub.magneticchess.voicecontrol

import java.util.*

object ABI {
    val ServiceUUID: UUID = UUID.fromString("3b1abb0e-46ce-4c15-b728-a170e6713c10")
    val StateUUID: UUID = UUID.fromString("e7a27133-53fd-493e-a972-f4e7bd472f5d")
    val MoveUUID: UUID = UUID.fromString("5e832f71-fa61-4032-b35e-4cfa9f410f76")
    const val StateWhite: Byte = 1
    const val StatePurple: Byte = 2
    const val StateTurn: Byte = 4
    const val StateInvalid: Byte = 8
    const val MoveFlagWhite: Byte = (1 shl 4)
    const val MoveFlagPurple: Byte = (1 shl 5)
    const val MoveFlagFrom: Byte = (1 shl 6)
}
