/*
 * I2CBus.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#include "I2CBus.h"

namespace jetsonhardware {
namespace i2c {

const std::string I2CBus::GEN1_I2C = "GEN1_I2C";
const std::string I2CBus::GEN2_I2C = "GEN2_I2C";
const std::string I2CBus::PWR_I2C = "PWR_I2C";
const std::string I2CBus::CAM_I2C = "CAM_I2C";


I2CBus::I2CBus() {
}

I2CBus::I2CBus(std::string file) : _bus_file(file) {
	// TODO: initialize I2C interface for this bus
}

I2CBus::~I2CBus() {
}

const I2C& I2CBus::get_bus_i2c() const {
	return _i2c;
}

const std::string& I2CBus::get_bus_file() const {
	return _bus_file;
}

std::string I2CBus::to_string() {
	std::string s;
	s += "I2CBus [bus file: " + _bus_file + "]";
	return s;
}

} /* namespace i2c */
} /* namespace jetsonhardware */

