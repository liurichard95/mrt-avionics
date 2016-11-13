/* The radio transmission module
 * this accepts data in whatever format and sends it through the 
 * SX1272 radio
 */

//Include global packages
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdint.h>
#include <vector>
#include <queue>

//Include the packages necessary for the SX1272
#include <Wire.h>
//#include "../libraries/arduino_api/arduinoUtils.h"
//#include "../libraries/arduinoLoRa/arduinoLoRa.h"
#include <SPI.h>

using namespace std;

//various utilities for dealing with binary/nonASCII data

//creates a c++ byte vector from a c++ string
vector<uint8_t> create_vector_from_string(string str)
{
	int len = str.length();
	vector<uint8_t> v;
	for (int i=0; i<len; i++) {
		v.push_back((uint8_t) str[i]);
	}
	return v;
}

/*
 * PACKETING SUBSYSTEM
*/

struct packet {
	uint8_t type;
	uint8_t port;
	uint8_t sys;
	uint8_t payload_length;
	uint8_t error; //bitfield created by radio
	uint8_t info; //bitfield user-defined
	vector<uint8_t> payload; //max 180 bytes?
	vector<uint8_t> repr;
	uint8_t continuity; //if the data is split between packets (do not implement right now...)
};

struct packet initialize_packet(uint8_t type, uint8_t port, uint8_t sys, uint8_t payload_length, uint8_t error, uint8_t info, vector<uint8_t> payload)
{
	packet pack;
	pack.type = type;
	pack.port = port;
	pack.sys = sys;
	pack.payload_length = payload_length;
	pack.error = error;
	pack.info = info;
	pack.payload = payload;
	pack.continuity = 0xFF; //not implemented right now
	return pack;
}

//creates a C++ byte vector that will be sent to the transmitter
vector<uint8_t> format_packet(struct packet p)
{
	vector<uint8_t> repr;
	repr.push_back(p.type);
	repr.push_back(p.port);
	repr.push_back(p.sys);
	repr.push_back(p.payload_length);
	repr.push_back(p.error);
	repr.push_back(p.info);
	repr.push_back(' ');
	for (int i=0; i<p.payload_length; i++) {
		repr.push_back(p.payload[i]);
	}
	repr.push_back(p.continuity);
	repr.push_back(0);
	return repr;
}

/*
 * MANAGES THE PACKETS TO BE SEND
 * two queues: one basic (the one first implemented) the other priority (with ACK?)
*/

queue<vector<uint8_t>> pqueue;

void send_packet()
{
	//code to send the packet
	//NEED TO REPURPOSE THE LIBRARY TO SEND VECTORS...
}

void packet_enqueue(vector<uint8_t> v)
{
	pqueue.push_back(v);
	
}

vector<uint8_t> packet_dequeue()
{
	return pqueue.pop_front();
}

/*
 * FUNCTIONS FOR THIS MODULE TO INTERFACE WITH THE RADIO
*/

//initialises the radio
int radio_init()
{

}

//checks the status of the radio
int radio_check()
{

}

//checks if the FIFO is empty
int radio_FIFO_status()
{

}

void radio_tx_vector(vector<uint8_t> vec)
{

}

void radio_tx_string(string str)
{

}

/*
 * FUNCTIONS FOR THE OUTSIDE WORLD TO INTERFACE WITH THE RADIO
 */

int radio_cycle()
{
	//check if FIFO is empty
	//if it is, check if there are packets in the queue
	//if there are, tx one and yield
	return 0;
}

//the "main" function, used by the outside world to register their byte vectors and place them on the queue.
//it does not specify length
int radio_send_vector(uint8_t port, uint8_t sys, uint8_t info, vector<uint8_t> payload)
{
	uint8_t len = payload.size();
	//do something here if it is too long...
	struct packet p = initialize_packet((uint8_t) 'P', port, sys, len, 0, info, payload);
	packet_enqueue(format_packet(p));
	return 1; //SUCCESS
}



void setup() {
	Serial.begin(115200);
	Serial.println("hello, test");
	string test("hello this is a string containing null : \0. If you see this, then it skips the null, hyrray!",100);
	Serial.print("String is of size ");
	Serial.println(test.length());
	  int a = millis();
	vector<uint8_t> v = create_vector_from_string(test);
	Serial.print("Length of vector is ");
	Serial.println(v.size());
	packet pack;
	pack = initialize_packet(1, 2, 1, test.length(), 0, 0, v);
	Serial.println("Packet initialized!");
	vector<uint8_t> p= format_packet(pack);
	  Serial.println(millis()-a);
	for (int i=0; i<p.size(); i++) {
		Serial.print((char) p[i]);
	}
	Serial.println();
	Serial.println("Completed");
}

void loop() {

}
