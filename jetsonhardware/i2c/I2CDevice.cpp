/*
 * I2CDevice.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#include "I2CDevice.h"

namespace jetsonhardware {
namespace i2c {


I2CDevice::I2CDevice(unsigned int addr) : _address(addr) {

}

I2CDevice::I2CDevice(unsigned int addr, I2CBus &bus) : _address(addr),
													   _bus(bus) {
}


I2CDevice::~I2CDevice() {

}


bool I2CDevice::is_ten_bit_addr() {
	unsigned int v = _address; // 32-bit word to find the log base 2 of
	unsigned int r = 0; // r will be lg(v)

	while (v >>= 1) // unroll for more speed...
	{
	  r++;
	}

	return r == 10;
}

char* I2CDevice::send_command(char tx_addr, size_t write_bytes, size_t read_bytes) {
	I2C i2c = _bus.get_bus_i2c();
	return i2c.i2c_command(_address, tx_addr, write_bytes, read_bytes);
}

} /* namespace i2c */
} /* namespace jetsonhardware */
