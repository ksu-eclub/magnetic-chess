package server

const (
	serviceUUID    = "3b1abb0e-46ce-4c15-b728-a170e6713c10"
	stateUUID      = "e7a27133-53fd-493e-a972-f4e7bd472f5d"
	moveUUID       = "5e832f71-fa61-4032-b35e-4cfa9f410f76"
	movePieceBits  = 3
	moveFlagWhite  = (1 << 4)
	moveFlagPurple = (1 << 5)
	moveFlagFrom   = (1 << 6)
	stateUnknown   = 0
	stateWhite     = 1
	statePurple    = 2
	stateTurn      = 4
	stateInvalid   = 8
)
