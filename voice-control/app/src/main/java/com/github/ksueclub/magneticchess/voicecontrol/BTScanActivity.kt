package com.github.ksueclub.magneticchess.voicecontrol

import android.Manifest
import android.app.Activity
import android.bluetooth.BluetoothAdapter
import android.bluetooth.BluetoothManager
import android.bluetooth.le.*
import android.content.Context
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Bundle
import android.os.ParcelUuid
import android.util.Log
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

public const val RESULT_MAC_ADDRESS = "mac"
private const val BLUETOOTH_ENABLE_REQUEST_CODE = 0
private const val PERMISSION_REQUEST_CODE = 1

class BTScanActivity : AppCompatActivity() {
    private val adapter: BluetoothAdapter by lazy(LazyThreadSafetyMode.NONE) {
        val manager = getSystemService(Context.BLUETOOTH_SERVICE) as BluetoothManager
        manager.adapter
    }
    private lateinit var list: BluetoothDeviceAdapter
    private lateinit var scanner: BluetoothLeScanner
    private val scanCallback = object : ScanCallback(){
        override fun onScanResult(callbackType: Int, result: ScanResult?) {
            if (result != null) {
                Log.d("BTScanActivity", String.format("Scan result: %s", result.device))
                list.add(BluetoothDevice(result.device.name, result.device.address, result.rssi))
            }
        }

        override fun onScanFailed(errorCode: Int) {
            Toast.makeText(this@BTScanActivity, String.format("Unable to run Bluetooth scan: %d", errorCode), Toast.LENGTH_LONG).show()
        }

        override fun onBatchScanResults(results: MutableList<ScanResult>?) {
            results?.forEach {
                onScanResult(ScanSettings.CALLBACK_TYPE_ALL_MATCHES, it)
            }
        }
    }

    private fun onSelect(dev: BluetoothDevice) {
        scanner.stopScan(scanCallback)
        val data = Intent()
        data.putExtra(RESULT_MAC_ADDRESS, dev.MACAddress)
        setResult(Activity.RESULT_OK, data)
        finish()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_bt_scan)
        val recycler = findViewById<RecyclerView>(R.id.device_list)
        list = BluetoothDeviceAdapter(recycler, this::onSelect)
        recycler.apply {
            layoutManager = LinearLayoutManager(this@BTScanActivity)
            adapter = list
        }
        bleInit()
    }

    private fun bleInit() {
        val missingPerms = arrayOf(
            Manifest.permission.BLUETOOTH,
            Manifest.permission.BLUETOOTH_ADMIN,
            Manifest.permission.ACCESS_FINE_LOCATION
        ).filter {
            ContextCompat.checkSelfPermission(this, it) != PackageManager.PERMISSION_GRANTED
        }.toTypedArray()
        when {
            missingPerms.isNotEmpty() -> {
                Log.d("BTScanActivity", "Requesting missing permissions from user")
                ActivityCompat.requestPermissions(this, missingPerms, PERMISSION_REQUEST_CODE)
            }
            adapter.isEnabled -> {
                scanner = adapter.bluetoothLeScanner
                val filters = listOf(ScanFilter.Builder().setServiceUuid(ParcelUuid(ABI.ServiceUUID)).build())
                //val filters = listOf<ScanFilter>()
                val settings = ScanSettings.Builder().setCallbackType(ScanSettings.CALLBACK_TYPE_ALL_MATCHES).build()
                scanner.startScan(filters, settings, scanCallback)
            }
            else -> {
                val intent = Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE)
                startActivityForResult(intent, BLUETOOTH_ENABLE_REQUEST_CODE)
            }
        }
    }

    private fun cancel() {
        setResult(Activity.RESULT_CANCELED)
        finish()
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        if (permissions.size != grantResults.size || grantResults.any { it != PackageManager.PERMISSION_GRANTED }) {
            cancel()
        } else {
            bleInit()
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        if (resultCode == Activity.RESULT_OK) {
            when (requestCode) {
                BLUETOOTH_ENABLE_REQUEST_CODE -> {
                    bleInit()
                }
            }
        } else {
            cancel()
        }
        super.onActivityResult(requestCode, resultCode, data)
    }
}
