package com.github.ksueclub.magneticchess.voicecontrol

import android.app.Activity
import android.bluetooth.*
import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.speech.RecognizerIntent
import android.util.Log
import android.view.View
import android.widget.ProgressBar
import android.widget.Toast
import androidx.constraintlayout.widget.ConstraintLayout
import kotlin.experimental.and

private const val SPEECH_REQUEST_CODE = 0
private const val BLUETOOTH_REQUEST_CODE = 1

class MainActivity : AppCompatActivity() {
    private val gattCallback = object : BluetoothGattCallback() {
        var tries = 0

        override fun onConnectionStateChange(gatt: BluetoothGatt?, status: Int, newState: Int) {
            when (newState) {
                BluetoothProfile.STATE_CONNECTED -> {
                    Log.i("MainActivity", "Connected to GATT server.")
                    gatt?.discoverServices()
                }
                BluetoothProfile.STATE_DISCONNECTED -> {
                    Log.i("MainActivity", "Disconnected from GATT server.")
                    tries = 0
                    gatt?.connect()
                    runOnUiThread {
                        findViewById<ProgressBar>(R.id.progress).visibility = View.VISIBLE
                    }
                }
            }
        }

        override fun onServicesDiscovered(gatt: BluetoothGatt?, status: Int) {
            Log.d("MainActivity", "Services discovered.")
            findViewById<ProgressBar>(R.id.progress).visibility = View.INVISIBLE
            val service = gatt?.getService(ABI.ServiceUUID)
            stateChar = service?.getCharacteristic(ABI.StateUUID)
            moveChar = service?.getCharacteristic(ABI.MoveUUID)
            if (stateChar == null || moveChar == null) {
                if (tries < 10) {
                    ++tries
                    runOnUiThread {
                        Handler().postDelayed({
                            gatt?.javaClass?.getMethod("refresh")?.invoke(gatt)
                            gatt?.discoverServices()
                        }, 100)
                    }
                } else {
                    startActivityForResult(Intent(this@MainActivity, BTScanActivity::class.java), BLUETOOTH_REQUEST_CODE)
                }
            } else {
                gatt?.readCharacteristic(stateChar)
            }
        }

        override fun onCharacteristicRead(gatt: BluetoothGatt?, characteristic: BluetoothGattCharacteristic?, status: Int) {
            Log.d("MainActivity", "onCharacteristicRead")
            if (status != BluetoothGatt.GATT_SUCCESS) {
                Log.w("MainActivity", "Failure in characteristic read")
                return
            }
            val state = characteristic?.value?.first()
            if (state != null) {
                white = (state and ABI.StateWhite) != 0.toByte()
                purple = (state and ABI.StatePurple) != 0.toByte()
                when {
                    white == purple -> {
                        findViewById<ConstraintLayout>(R.id.layout).background = getDrawable(R.drawable.turn_unknown)
                    }
                    white -> {
                        findViewById<ConstraintLayout>(R.id.layout).background = getDrawable(R.drawable.turn_white)
                    }
                    else -> {
                        findViewById<ConstraintLayout>(R.id.layout).background = getDrawable(R.drawable.turn_purple)
                    }
                }
                when {
                    (state and ABI.StateInvalid) != 0.toByte() -> {
                        runOnUiThread {
                            Toast.makeText(this@MainActivity, R.string.invalid_move, Toast.LENGTH_LONG).show()
                        }
                        gatt?.readCharacteristic(stateChar)
                    }
                    (state and ABI.StateTurn) != 0.toByte() -> {
                        val intent = Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH).apply {
                            putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM)
                        }
                        startActivityForResult(intent, SPEECH_REQUEST_CODE)
                    }
                }
            }
        }

        override fun onCharacteristicWrite(gatt: BluetoothGatt?, characteristic: BluetoothGattCharacteristic?, status: Int) {
            Log.d("MainActivity", "onCharacteristicWrite")
            if (status != BluetoothGatt.GATT_SUCCESS) {
                Log.w("MainActivity", "Failure in characteristic write")
                return
            }
            gatt?.readCharacteristic(stateChar)
        }
    }

    private val adapter: BluetoothAdapter by lazy(LazyThreadSafetyMode.NONE) {
        val manager = getSystemService(Context.BLUETOOTH_SERVICE) as BluetoothManager
        manager.adapter
    }

    private lateinit var gatt: BluetoothGatt
    private var stateChar: BluetoothGattCharacteristic? = null
    private var moveChar: BluetoothGattCharacteristic? = null
    private var white = false
    private var purple = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        startActivityForResult(Intent(this, BTScanActivity::class.java), BLUETOOTH_REQUEST_CODE)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        if (resultCode == Activity.RESULT_OK) {
            when (requestCode) {
                SPEECH_REQUEST_CODE -> {
                    val str: String? = data?.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS)?.let {
                        it[0]
                    }
                    if (str != null) {
                        Log.d("MainActivity", str)
                        val arr = ByteArray(3)
                        if (MoveTranscoder.transcode(this, str, white, purple, arr)) {
                            moveChar?.value = arr
                            gatt.writeCharacteristic(moveChar)
                            return
                        } else {
                            Toast.makeText(this, R.string.unable_to_understand_move, Toast.LENGTH_LONG).show()
                        }
                    }
                    val intent = Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH).apply {
                        putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM)
                    }
                    startActivityForResult(intent, SPEECH_REQUEST_CODE)
                }
                BLUETOOTH_REQUEST_CODE -> {
                    val mac = data?.getStringExtra(RESULT_MAC_ADDRESS)
                    if (mac != null) {
                        val device = adapter.getRemoteDevice(mac)
                        gatt = device.connectGatt(this, false, gattCallback)
                    } else {
                        finish()
                    }
                }
            }
        } else {
            finish()
        }
        super.onActivityResult(requestCode, resultCode, data)
    }
}
