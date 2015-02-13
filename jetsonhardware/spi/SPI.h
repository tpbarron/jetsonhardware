/*
 * SPI.h
 *
 *  Created on: Jan 31, 2015
 *      Author: trevor
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>


namespace jetsonhardware {
namespace spi {

class SPI {

public:

	SPI();
	~SPI();

	void spi_open(std::string name);


private:

	int op_result;

	int spi_dev;
};

} /* namespace spi */
} /* namespace jetsonhardware */

#endif /* SPI_SPI_H_ */
