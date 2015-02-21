/*
 * JetsonTK1.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#include "JetsonTK1.h"

namespace jetsonhardware {

JetsonTK1::JetsonTK1() {
	// TODO Auto-generated constructor stub

}

JetsonTK1::~JetsonTK1() {
	// TODO Auto-generated destructor stub
}

const jetsonhardware::i2c::I2CBus& JetsonTK1::getI2CBus(const std::string file) {
	return _i2c_bus_factory.get_i2c_bus(file);
}

const jetsonhardware::spi::SPIBus& JetsonTK1::getSPIBus(const std::string file) {
	return _spi_bus_factory.get_spi_bus(file);
}

std::string JetsonTK1::to_string() {
	std::string s = "";
	s += "JetsonTK1: ";
	//s += _i2c_bus_factory.to_string();
	//s += _spi_bus_factory.to_string();
	return s;
}

} /* namespace jetsonhardware */
