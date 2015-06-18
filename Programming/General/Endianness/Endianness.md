#Endianness

##Overview
Endianness is the binary equivalent of place value in a decimal system.
	Decimal Example : 1000 (one thousand) > 0010 (ten)
	Binary Example  : 0xff00 > 0x00ff (Assuming this is big endian and uses an unsigned 16 bit integer.

Two important terms when referring to endianness is LSB (least significant byte) and MSB (most significant byte). These refer to the numerical size that that byte represents.

Endianness is often system / processor dependent, but could also be handled in a software layer such as java.

Endianness is often referred to as the NUXI problem given by the fact that if the letters were stored in two integers holding UN and IX, a little endian system would store the data internally as NU and XI hence NUXI.

Endianness is often either little endian or big endian. Some systems, however, can use both.

A common term referred to when referring to endianness is Network Order. Network Order is big endian and is the way data is transferred over networks.

Endianness is essential in converting multi-byte data to a human readable format.

##Sample conversion of multi-byte data

Step 1 : Acquire two or more single bytes that form a single piece of data.

```
	byte lsb = 0xe7;
	byte msb = 0xa4;
```

Step 2 : Place the bytes in a buffer of larger size and mask the bytes to ignore unneccessary data.

```
	short lsb_buffer = ((short) lsb) & 0x00ff;
	short msb_buffer = ((short) msb) & 0x00ff;
```

Step 3 : Shift the bytes into the correct order.

```
	msb_buffer = msb_buffer << 8;	//This assumes shifting for big endian format. 
				     	//For little endian format shift the lsb_buffer variable instead.
```

Step 4 : Combine the bytes into a single multi-byte data

```
	short data = msb_buffer | lsb_buffer
```
