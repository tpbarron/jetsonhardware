/*
 * I2C.h
 *
 *  Created on: Jan 31, 2015
 *      Author: trevor
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string> // std::string
#include <string.h> // memset
#include <stdio.h>


namespace jetsonhardware {
namespace i2c {

class I2C {

public:

	I2C();
	~I2C();


	/*
	 * Open connection to peripheral
	 */
	void i2c_open(std::string file, int mode);

	/**
	 * Tell the peripheral whether the device is 10 bit
	 */
	void i2c_set_ten_bit(bool is_ten_bit);

	/**
	 * Set the address of the device we want to talk to
	 */
	void i2c_set_slave(char addr);


	/**
	 * Execute a command on the current slave
	 */
	char* i2c_command(char tx_addr, size_t write_bytes, size_t read_bytes);

	/**
	 * Execute a command on the new slave
	 *
	 * The return value is the byte value of the data.
	 */
	char* i2c_command(char slave_addr, char tx_addr, size_t write_bytes, size_t read_bytes);


	/**
	 * Set the tx buffer addr to be read from the device
	 */
	void i2c_set_tx(char addr);

	/**
	 * Send data to slave
	 */
	void i2c_write(size_t bytes);

	/**
	 * Read data from slave
	 */
	void i2c_read(size_t bytes);

	/**
	 * Get the response from the slave
	 *
	 * TODO: check this const usage. Want the
	 * data to be const
	 */
	const char* i2c_get_rx_buffer() const;

	/**
	 * Clear the tx buffer
	 */
	void i2c_clear_tx();

	/**
	 * Clear the rx buffer
	 */
	void i2c_clear_rx();


	/**
	 * Clear both buffers
	 */
	void i2c_clear_buffers();

private:

	char _rx_buffer[32]; // receive buffer
	char _tx_buffer[32]; // transmit buffer

	int _ten_bit_address; // usually the device's address is not 10 bit
	int _op_result;

	int _i2c_handle; // a file handle to the i2c dev

};

} /* namespace i2c */
} /* namespace jetsonhardware */

#endif /* I2C_I2C_H_ */
