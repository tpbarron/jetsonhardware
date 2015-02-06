/*
 * SPI.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: trevor
 */

#include "SPI.h"

SPI::SPI() : op_result(0),
			 spi_dev(0) {

}

SPI::~SPI() {

}

void SPI::spi_open(std::string name) {
	spi_dev = open(name.c_str(), O_RDWR);
}
