package server

import (
	"github.com/paypal/gatt"
	"github.com/paypal/gatt/examples/option"
	"github.com/paypal/gatt/examples/service"
	"github.com/prometheus/common/log"
)

func gattInit() {
	d, err := gatt.NewDevice(option.DefaultServerOptions...)
	if err != nil {
		errCh <- err
		return
	}
	d.Handle(gatt.CentralConnected(centralConnected), gatt.CentralDisconnected(centralDisconnected))
	d.Init(stateChange)
	log.Info("BLE server initialized.")
}

func centralConnected(c gatt.Central) {
	log.Debug("Connected")
}

func centralDisconnected(c gatt.Central) {
	log.Debug("Disconnected")
}

func stateChange(d gatt.Device, s gatt.State) {
	log.Debugf("State: %s", s)
	switch s {
	case gatt.StatePoweredOn:
		if err := d.AddService(service.NewGapService("MagneticChess")); err != nil {
			errCh <- err
		}
		if err := d.AddService(service.NewGattService()); err != nil {
			errCh <- err
		}
		s := gatt.NewService(gatt.MustParseUUID(serviceUUID))
		s.AddCharacteristic(gatt.MustParseUUID(stateUUID)).HandleReadFunc(handleState)
		s.AddCharacteristic(gatt.MustParseUUID(moveUUID)).HandleWriteFunc(handleMove)
		if err := d.AddService(s); err != nil {
			errCh <- err
		}
		if err := d.AdvertiseNameAndServices("MagneticChess", []gatt.UUID{s.UUID()}); err != nil {
			errCh <- err
		}
	}
}
