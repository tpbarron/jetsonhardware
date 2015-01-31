# jetsontk1_sensor_interface
Library interface for sensor access on the NVidia Jetson TK1 via I2C and SPI

SPI Interface
  * Basic mode where only receive data and no transmission
  * Advanced mode where sending and receiving data
  * Designate slave pins and MOSI / MISO pins
  * I suspect the devices will be returning little-endian binary data. Create structure to add device handlers for difference devices that permit processing that binary data into a nicer form before passing it off to the user of the library
  * For a good SPI tutorial - https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi
  * https://learn.sparkfun.com/tutorials/programming-the-pcduino/spi-communications


I2C Interface
  * Tutorials https://learn.sparkfun.com/tutorials/i2c#introduction, http://www.robot-electronics.co.uk/acatalog/I2C_Tutorial.html
  * Library example https://www.kernel.org/doc/Documentation/i2c/dev-interface
  * https://learn.sparkfun.com/tutorials/programming-the-pcduino/i2c-communications

