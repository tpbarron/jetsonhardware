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

namespace jetsonhardware {
namespace i2c {

class I2CBus {

public:

	enum I2C_DEV_FILE {

	};

	static const std::string GEN1_I2C;
	static const std::string GEN2_I2C;
	static const std::string PWR_I2C;
	static const std::string CAM_I2C;

	I2CBus();
	I2CBus(std::string file);
	~I2CBus();

	const I2C& get_bus_i2c();

	std::string to_string();

private:

	std::string _bus_file;

	I2C _i2c;

};

} /* namespace i2c */
} /* namespace jetsonhardware */

#endif /* I2C_I2CBUS_H_ */
