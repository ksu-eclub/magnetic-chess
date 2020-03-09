package com.github.ksueclub.magneticchess.voicecontrol

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import kotlin.reflect.KFunction1

class BluetoothDeviceAdapter(recycler: RecyclerView, callback: KFunction1<BluetoothDevice, Unit>) : RecyclerView.Adapter<BluetoothDeviceAdapter.ViewHolder>() {
    class ViewHolder(val view: View) : RecyclerView.ViewHolder(view)

    private val list = mutableListOf<BluetoothDevice>()
    private val listener = View.OnClickListener { v ->
        if (v != null) {
            val dev = list[recycler.getChildAdapterPosition(v)]
            callback(dev)
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.bluetooth_device, parent, false)
        view.setOnClickListener(listener)
        return ViewHolder(view)
}

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val dev = list[position]
        holder.view.apply {
            if (dev.deviceName == null) {
                findViewById<TextView>(R.id.device_name).text = context.getString(R.string.unknown_device_name)
            } else {
                findViewById<TextView>(R.id.device_name).text = dev.deviceName
            }
            findViewById<TextView>(R.id.mac_address).text = dev.macAddress
            findViewById<TextView>(R.id.rssi).text = String.format(holder.view.context.getString(R.string.dBm), dev.rssi)
        }
    }

    override fun getItemCount(): Int {
        return list.size
    }

    fun add(dev: BluetoothDevice) {
        val old = list.firstOrNull { it.macAddress == dev.macAddress }
        if (old == null) {
            list.add(dev)
        } else {
            old.rssi = dev.rssi
        }
        notifyDataSetChanged()
    }
}
