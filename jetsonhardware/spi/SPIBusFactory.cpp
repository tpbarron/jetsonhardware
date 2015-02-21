/*
 * SPIBusFactory.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#include "SPIBusFactory.h"

namespace jetsonhardware {
namespace spi {

SPIBusFactory::SPIBusFactory() {
	// TODO Auto-generated constructor stub

}

SPIBusFactory::~SPIBusFactory() {
	// TODO Auto-generated destructor stub
}

const SPIBus& SPIBusFactory::get_spi_bus(std::string file) {
	// Check if I2CBus already exists, if not create it
	if (_spi_bus_map.find(file) != _spi_bus_map.end()) {
		return _spi_bus_map[file];
	}

	// create new i2c bus for file
	SPIBus spi_bus(file);
	_spi_bus_map[file] = spi_bus;
	return _spi_bus_map[file];
}

} /* namespace spi */
} /* namespace jetsonhardware */
