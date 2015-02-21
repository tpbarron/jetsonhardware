/*
 * SPIBus.h
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#ifndef SPI_SPIBUS_H_
#define SPI_SPIBUS_H_

#include <string>

namespace jetsonhardware {
namespace spi {

class SPIBus {

public:

	/**
	 * Never instantiate this class directly. Instead use
	 * the I2CDeviceFactory to ensure that duplicate bus
	 * objects are not created.
	 */
	SPIBus();
	SPIBus(std::string file);
	~SPIBus();


private:

	std::string _bus_file;

};

} /* namespace spi */
} /* namespace jetsonhardware */

#endif /* SPI_SPIBUS_H_ */
