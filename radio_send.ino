/* The radio transmission module
 * this accepts data in whatever format and sends it through the 
 * SX1272 radio
 */

//Include global packages
#include <stdio.h>
#include <stdlib.h>
#include <string>

//Include the packages necessary for the SX1272
#include <Wire.h>
#include <arduinoUtils.h>
#include <arduinoLoRa.h>
#include <SPI.h>

//various utilities for dealing with binary/nonASCII data

//creates a c++ string that can contain null characters
string createstring(string str, int len)
{
	string a(str, len);
	return a;
}

//packeting subsystem

struct packet {
	uint8_t type;
	uint8_t port;
	uint8_t system;
	uint8_t payload_length;
	uint8_t error; //bitfield created by radio
	utin8_t info; //bitfield user-defined
	string payload; //max 180 bytes?
	string repr;
}

struct packet initialize_packet(uint8_t type, uint8_t port, uint8_t system, uint8_t payload_length, uint8_t error, uint8_t info, string payload)
{
	pack = new packet();
	pack.type = type;
	pack.port = port;
	pack.system = system;
	pack.payload_length = payload_length;
	pack.error = error;
	pack.info = info;
	pack.payload = payload;
}
