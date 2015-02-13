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

	const jetsonhardware::i2c::I2CBus& getI2CBus(const std::string file);

	std::string to_string();

private:

	jetsonhardware::i2c::I2CBusFactory _i2c_bus_factory;
	jetsonhardware::spi::SPIBusFactory _spi_bus_factory;

};

} /* namespace jetsonhardware */

#endif /* JETSONTK1_H_ */
