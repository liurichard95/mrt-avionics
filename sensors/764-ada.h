
/* 
 Header file for Adafruit Ultimate GPS Breakout (764-ada)
 
 Required Libraries:
 	TinyGPS++: https://github.com/mikalhart/TinyGPSPlus

 Description:
 	764-ada.ino initially establishes a Serial connection with the GPS module. Following this
 	connection period, the sketch is designed to remain idle until a return function is called.
 	This function returns a struct containing key data like latitude, longitude, altitude etc.
*/


/* -- guard -- */
#ifndef 746-ADA_H
#define 746-ADA_H

/* --- includes --- */
#include <stdio.h>
#include <stdlib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


/* --- init variables --- */

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);


typedef struct data {
	unsigned short satCount;
	float lat;
	float lng;
	float altitude;
	float course;
	float speed;
} GPSData;

/* --- function prototypes --- */

/* buildGPSstruct: builds a new GPS structure
accepts: 
- data: pointer to GPS structure [NOTE: must already be allocated by calling allocate() {for C implementation}]
- latitude, longitude, altitude
returns: none
*/
void buildGPSstruct(GPSData* data, float lat, float lng, float altitude, float course, float speed, unsigned short satCount);

/* init: initializes the GPS sensor for use 
accepts: none
returns: none
*/
void initGPS(void);

/* getGPSData: returns a pointer to a GPSData structure holding the Rocket's current GPS information
accepts: none
returns: pointer to GPSData structure
*/
GPSData* getGPSData(void);

#endif