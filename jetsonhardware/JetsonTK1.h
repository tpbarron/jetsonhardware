/*
 * JetsonTK1.h
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#ifndef JETSONTK1_H_
#define JETSONTK1_H_

#include <string>

#include "i2c/I2CBus.h"
#include "i2c/I2CBusFactory.h"

#include "spi/SPIBus.h"
#include "spi/SPIBusFactory.h"

namespace jetsonhardware {

class JetsonTK1 {

public:

	JetsonTK1();
	~JetsonTK1();

	/**
	 * Return the I2CBus associated with the file. If an I2CBus instance
	 * with this file handle already exists it will be returned.
	 */
	const jetsonhardware::i2c::I2CBus& getI2CBus(const std::string file);

	/**
	 * Return the SPIBus associated wite the file. If an SPIBus instance
	 * with this file handle already exists it will be returned.
	 */
	const jetsonhardware::spi::SPIBus& getSPIBus(const std::string file);

	std::string to_string();

private:

	jetsonhardware::i2c::I2CBusFactory _i2c_bus_factory;
	jetsonhardware::spi::SPIBusFactory _spi_bus_factory;

};

} /* namespace jetsonhardware */

#endif /* JETSONTK1_H_ */
