#I2C

##Overview
I2C is an easy way to connect many devices to an embedded system.
Individual I2C devices have separate addresses which distinguishes which device receives the programmed command and which device supplied the appropriate signal.
I2C (read I-two-see or I-squared-see), is short for Inter-Integrated Circuit.
I2C works via a two-wire interface hence gaining the appelation "Two-wire interface"

##Electrical Overview
I2C has a typical wiring setup up consisting of 4 wires (Power, Ground, Data, and Clock).
I2C devices are typically wired in parallel with all of the I2C devices working on the same bus.
I2C devices typically have a pair of resistors between the power rail and data and clock buses, however, in most circuits this is not required or already handled by the internal circuits of the microprocessor.
The following diagram is an example of a simple I2C circuit

		GND---------------------GND


		SDA---------------------SDA
			/
Microcomputer		\ 4.7 kOhm		I2C Device
			/
		3V3---------------------3V3
				\
				/ 4.7 kOhm
				\
		SCL---------------------SCL

##Good Practice
It is typically good practice to keep track of I2C device addresses before purchasing and using multiple devices for and in a circuit. It is unlikely that addresses will overlap, but it is still a possibility which could produce undesired results.

It is also a good idea to check the addresses which appear on the I2C bus when devices are acquired.

It is also important to realize the maximum communications speed when interfacing with devices. This is essential so that information is not lost and that commands are updated frequently enough.

When acquiring data from I2C devices, it is also important to organize multi-byte data in the correct order for your microprocessor or software-layer.

##Fun Facts
I2C follows after an older type of interface called SMBus. SMBus is also a two-wire interface, but is slightly different than I2C. Devices that are sold as using two-wire interface may not necessarily be compatible with some systems. 

I2C is available in many microprocessors and computers such as the Arduino and Raspberry Pi.
