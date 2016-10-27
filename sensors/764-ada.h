
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
#include <Adafruit_GPS.h>

// ensures backwards compatibility with older Arduino IDEs
#if ARDUINO >= 100
 #include <SoftwareSerial.h>
#endif

typedef struct data {
	char * latitude; 
	char * longitude;
	char * altitude;
} GPS;

/* --- function prototypes --- */

GPS * allocate(void);

GPS * buildGPSstruct(char * latitude, char * longitude, char * altitude);


#endif