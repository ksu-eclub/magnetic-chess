package server

import (
	"github.com/paypal/gatt"
)

var state = stateUnknown

func handleState(rsp gatt.ResponseWriter, req *gatt.ReadRequest) {
	rsp.Write([]byte{byte(state)})
	if (state & stateInvalid) != 0 {
		state &^= stateInvalid
	}
}
