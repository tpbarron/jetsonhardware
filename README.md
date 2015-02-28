# jetsonhardware

Library interface for sensor access on the NVidia Jetson TK1 via I2C and SPI


Library todo:
  * Add error handling
    * File already in use

Setting up .so linking from Eclipse CDT:
  * http://linuxtortures.blogspot.com/2012/02/shared-libraries-with-eclipse.html

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


Shared Library notes:
  * Versioning - http://stackoverflow.com/questions/15264693/how-to-version-shared-object-file-created-using-gcc-for-linux


Filter notes:
  * Kalman - http://stackoverflow.com/questions/18152524/kalman-filter-with-acceleration
  
  
Attaching IMU and GPS to JetsonTK1 via I2C and SPI.
  * Ground pins:
    On J3A1 pin 2, 8, 9, 14, 15, 26, 47
  * +12V pins:
    On J3A1 pin 25
  * +5V pins:
    On J3A1 pin 1
  * +3.3V pins:
    On J3A1 pin 16, 22
  * +1.8V pins:
    On J3A1 pin 3, 19
  * IMU via I2C through /dev/i2c-1 
	  VDD -- +3.3V (pin 16 J3A1)
	  GND -- GND (pin 15 J3A1)
	  SDA -- GEN1_I2C_SDA_3.3V (pin 20 J3A1)
	  SCL -- GEN1_I2C_SCL_3.3V (pin 18 J3A1)
  	  See http://elinux.org/Jetson/I2C
  * GPS via SPI
	  Attach each lead to a GPIO pin?	
