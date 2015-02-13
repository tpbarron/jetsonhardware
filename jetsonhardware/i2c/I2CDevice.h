/*
 * I2CDevice.h
 *
 *  Created on: Feb 3, 2015
 *      Author: trevor
 */

#ifndef I2C_I2CDEVICE_H_
#define I2C_I2CDEVICE_H_


#include "I2CBus.h"

namespace jetsonhardware {
namespace i2c {

/**
 * Hold data for a single I2C device
 */
class I2CDevice {

public:

	I2CDevice(unsigned int addr);
	I2CDevice(unsigned int addr, I2CBus &bus);

	~I2CDevice();

	/**
	 * Returns true if the address for this device is 10 bit
	 */
	bool is_ten_bit_addr();

	/**
	 * Send a command to this device
	 */
	char* send_command(char tx_addr, size_t write_bytes, size_t read_bytes);



private:

	/**
	 * This device's address
	 */
	unsigned int _address;

	/**
	 * The bus this device is on
	 */
	I2CBus _bus;

};

} /* namespace i2c */
} /* namespace jetsonhardware */

#endif /* I2C_I2CDEVICE_H_ */
