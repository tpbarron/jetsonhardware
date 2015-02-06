/*
 * I2CBus.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#include "I2CBus.h"

I2CBus::I2CBus() {
	// TODO: initialize I2C interface for this bus
}

I2CBus::~I2CBus() {
}

const I2C& I2CBus::get_bus_i2c() {
	return _i2c;
}
