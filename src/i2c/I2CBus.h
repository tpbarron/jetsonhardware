/*
 * I2CBus.h
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#ifndef I2C_I2CBUS_H_
#define I2C_I2CBUS_H_

#include <string>
#include <vector>

#include "I2C.h"

/**
 *
 * Manage a set of slate I2C devices from a single
 * master source.
 *
 */
class I2CBus {

public:

	I2CBus();
	~I2CBus();

	const I2C& get_bus_i2c();

private:

	int bus_id;
	std::string bus_file;

	I2C _i2c;

};

#endif /* I2C_I2CBUS_H_ */
