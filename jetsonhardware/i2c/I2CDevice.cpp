/*
 * I2CDevice.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#include "I2CDevice.h"

#include <iostream>
#include <utility>

namespace jetsonhardware {
namespace i2c {


I2CDevice::I2CDevice(unsigned int addr) : _address(addr) {

}

I2CDevice::I2CDevice(unsigned int addr, I2CBus &bus) : _address(addr),
													   _bus(bus) {
}


I2CDevice::~I2CDevice() {

}

void I2CDevice::set_i2c_bus(I2CBus &bus) {
	_bus = bus;
}


bool I2CDevice::is_ten_bit_addr() const {
	unsigned int v = _address; // 32-bit word to find the log base 2 of
	unsigned int r = 0; // r will be lg(v)

	while (v >>= 1) // unroll for more speed...
	{
	  r++;
	}

	return r == 10;
}

const char* I2CDevice::send_command(char tx_addr, size_t write_bytes, size_t read_bytes) const {
	I2C i2c = _bus.get_bus_i2c();
	return i2c.i2c_command(_address, tx_addr, write_bytes, read_bytes);
}

const char* I2CDevice::send_command(std::string name) const {
	if (_command_map.find(name) != _command_map.end()) {
		std::map<std::string, I2CDeviceCommand>::const_iterator itr = _command_map.find(name);
		I2CDeviceCommand command  = itr->second;
		return send_command(command.get_tx_addr(), command.get_write_bytes(), command.get_read_bytes());
	} else {
		std::cerr << "Command by name [" << name << "] does not exist" << std::endl;
		return 0;
	}
}

void I2CDevice::add_command(I2CDeviceCommand &cmd) {
	std::pair<std::string, I2CDeviceCommand> p = std::make_pair(cmd.get_name(), cmd);
	_command_map.insert(p);
}

std::string I2CDevice::to_string() {
	std::string s;
	s += "I2CDevice [addr : ";
	s += _address;
	s += ", bus : " + _bus.get_bus_file() + "]";
	return s;
}


} /* namespace i2c */
} /* namespace jetsonhardware */
