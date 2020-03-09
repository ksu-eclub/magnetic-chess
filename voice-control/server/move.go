package server

import (
	"math/rand"

	"github.com/paypal/gatt"
	log "github.com/sirupsen/logrus"
)

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
	fromX := data[1] >> 4
	fromY := data[1] & 0xF
	toX := data[2] >> 4
	toY := data[2] & 0xF
	log.Infof("Move piece %d (white: %t, from: %t) from (%d, %d) to (%d, %d)", piece, white, from, fromX, fromY, toX, toY)
	if rand.Intn(5) == 0 {
		log.Warn("For debugging, the last request was rejected.")
		state |= stateInvalid
	} else {
		state ^= stateWhite | statePurple
	}
	return gatt.StatusSuccess
}
