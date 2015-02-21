/*
 * SPIBusFactory.h
 *
 *  Created on: Feb 5, 2015
 *      Author: trevor
 */

#ifndef SPI_SPIBUSFACTORY_H_
#define SPI_SPIBUSFACTORY_H_

#include <map>

#include "SPIBus.h"

namespace jetsonhardware {
namespace spi {

class SPIBusFactory {

public:

	SPIBusFactory();
	~SPIBusFactory();

	const SPIBus& get_spi_bus(std::string file);

private:

	std::map<std::string, SPIBus> _spi_bus_map;

};

} /* namespace spi */
} /* namespace jetsonhardware */

#endif /* SPI_SPIBUSFACTORY_H_ */
