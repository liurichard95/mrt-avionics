
/* 
 Header file for Adafruit Ultimate GPS Breakout (764-ada)
 
 Required Libraries:
 	Adafruit_GPS: github.com/adafruit/Adafruit_GPS

 Description:
 	764-ada.ino initially establishes a Serial connection with the GPS module. Following this
 	connection period, the sketch is designed to remain idle until a return function is called.
 	This function returns a struct containing key data like latitude, longitude, altitude etc.
*/


/* -- guard -- */
#ifndef gps_h
#define gps_h

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
	char * latitude; 
	char * longitude;
	char * altitude;
} GPSData;

/* --- function prototypes --- */

/* allocate: create space in memory for a new GPS struct
accepts: none
return: pointer to GPS struct
*/
GPSData * allocate(void);

/* buildGPSstruct: builds a new GPS structure
accepts: 
- data: pointer to GPS structure [NOTE: must already be allocated by calling allocate()]
- latitude, longitude, altitude
returns: none
*/
void buildGPSstruct(GPSData * data, char * latitude, char * longitude, char * altitude);

/* init: initializes the GPS sensor for use 
accepts: none
returns: none
*/
void init(void);

#endif