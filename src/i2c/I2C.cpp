/*
 * I2C.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: trevor
 */

#include "I2C.h"

I2C::I2C() : ten_bit_address(0),
			 op_result(0),
			 i2c_handle(0) {

}

I2C::~I2C() {

}

void I2C::i2c_open(std::string file, int mode) {
	i2c_handle = open(file.c_str(), mode);
}


void I2C::i2c_set_ten_bit(bool is_ten_bit) {
	if (is_ten_bit) {
		ten_bit_address = 1;
	} else {
		ten_bit_address = 0;
	}
	op_result = ioctl(i2c_handle, I2C_TENBIT, ten_bit_address);
}

void I2C::i2c_set_slave(char addr) {
	op_result = ioctl(i2c_handle, I2C_SLAVE, addr);
}

char* I2C::i2c_command(char slave_addr, char tx_addr, size_t write_bytes, size_t read_bytes) {
	i2c_set_slave(slave_addr);
	return i2c_command(tx_addr, write_bytes, read_bytes);
}

char* I2C::i2c_command(char tx_addr, size_t write_bytes, size_t read_bytes) {
	i2c_clear_buffers();
	i2c_set_tx(tx_addr);
	i2c_write(write_bytes);
	i2c_read(read_bytes);
	return rx_buffer;
}

void I2C::i2c_set_tx(char addr) {
	tx_buffer[0] = addr;
}

void I2C::i2c_write(size_t bytes) {
	op_result = write(i2c_handle, tx_buffer, bytes);
}

void I2C::i2c_read(size_t bytes) {
	op_result = read(i2c_handle, rx_buffer, bytes);
}

char* I2C::i2c_get_rx_buffer() {
	return rx_buffer;
}


void I2C::i2c_clear_tx() {
	memset(tx_buffer, 0, sizeof(tx_buffer));
}

void I2C::i2c_clear_rx() {
	memset(rx_buffer, 0, sizeof(rx_buffer));
}

void I2C::i2c_clear_buffers() {
	i2c_clear_tx();
	i2c_clear_rx();
}


