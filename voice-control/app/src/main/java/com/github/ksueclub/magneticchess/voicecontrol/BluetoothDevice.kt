package com.github.ksueclub.magneticchess.voicecontrol

class BluetoothDevice constructor(deviceName: String?, macAddress: String, rssi: Int) {
    val DeviceName = deviceName;
    val MACAddress = macAddress;
    var RSSI = rssi;
}