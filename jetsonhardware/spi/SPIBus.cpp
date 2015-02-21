/*
 * SPIBus.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#include "SPIBus.h"

namespace jetsonhardware {
namespace spi {

SPIBus::SPIBus() {
	// TODO Auto-generated constructor stub
}

SPIBus::SPIBus(std::string file) : _bus_file(file) {
	// TODO: initialize SPI object from file
}

SPIBus::~SPIBus() {
	// TODO Auto-generated destructor stub
}

} /* namespace spi */
} /* namespace jetsonhardware */
