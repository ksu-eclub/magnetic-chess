package server

import (
	"github.com/paypal/gatt"
	log "github.com/sirupsen/logrus"
)

var pieceMap = []string{
	"x", "r", "n", "b", "q", "k", "p",
}

func handleMove(req gatt.Request, data []byte) byte {
	if n := len(data); n != 3 {
		log.Warn("Malformed move packet.")
		log.Debugf("Got %d bytes, but expected exactly 3.", n)
		return gatt.StatusUnexpectedError
	}
	if ((data[0] & moveFlagWhite) == 0) == ((data[0] & moveFlagPurple) == 0) {
		log.Warn("Malformed move packet.")
		log.Debugf("Turn flags are invalid (flag byte = 0x%02x).", data[0])
		return gatt.StatusUnexpectedError
	}
	piece := data[0] & (0xFF & ^(0xFF << movePieceBits))
	white := (data[0] & moveFlagWhite) != 0
	from := (data[0] & moveFlagFrom) != 0
	var fromX, fromY byte
	if from {
		fromX = data[1] >> 4
		fromY = data[1] & 0xF
	} else {
		fromX = 0
		fromY = 0
	}
	toX := data[2] >> 4
	toY := data[2] & 0xF
	log.Debugf("Move piece %d (white: %t, from: %t) from (%d, %d) to (%d, %d)", piece, white, from, fromX, fromY, toX, toY)
	pieceStr := pieceMap[piece]
	if white {
		pieceStr = string(pieceStr[0] + 'A' - 'a')
	}
	if !tryMove(pieceStr, int(fromX), int(fromY), int(toX), int(toY)) {
		state |= stateInvalid
	}
	return gatt.StatusSuccess
}
