
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Wire.h>
// Cooking API libraries
#include <arduinoUtils.h>
// Include the SX1272 and SPI library:
#include "arduinoLoRa.h"
#include <SPI.h>

//constants
#define GROUND_COLLECTOR 16 // the channel that will be used to communicated with the ground (i.e. collect all data that is not specifically directed to a channel

//global status variables
int e;

//global files
FILE * radiologfile;
FILE * radioerrorlogfile;

void log (char * str)
{
	//writes to logfile
}

void log_error (char * str)
{
	//writes to error file
}


/* INITIAL CONFIGURATION OF THE TRANSMITTER
 * 
 */

//the values here are taken from cookinghacks with modifications
void SX_init()
{
	e = sx1272.ON(); //power on
	e |= sx1272.setMode(4);
	e |= sx1272.setChannel(CH_10_868); //default value given on the cookinghacks website
	e |= sx1272.setCRC_ON(); //set the checksum on
	e |= sx1272.setPower('M'); //set maximum power
	e |= sx1272.setNodeAddress(3);
}

void send_raw_string (char * str)
{
	e = sx1272.sendPacketTimeout(GROUND_COLLECTOR, str);
	/* insert code to catch and log exceptions here */
}

void send_raw_string_to_dest (int dest, char * str)
{
	e = sx1272.sendPacketTimeout(dest, str);
}

char * format_packet (char type, char info1, char * msg)
{
	int len = strlen(msg);
	if (len > MAXPACKETMSGLENGTH) {
		log_error("tried to send packet that exceeded max. length : %s", msg);
		return NULL;
	} else 
		char * s = malloc(sizeof(char) * (len+4));
		s[0] = type;
		s[1] = info1;
		s[3] = 0xFF;
		s[4] = 0xFF;
		if (len > 0) {
			strcpy((s+4),msg);
		}
		return s;
	}		
}

void send_packet (char type, char info1, char * msg)
{
	char * s = format_packet (type, info1, msg);
	if (s == NULL) return; //if string was not accepted, pass through
	send_raw_string(s);
	free(s);
}

void send_important_string (char * str)
{
	e = sx1272.sendPacketTimeoutACK(GROUND_COLLECTOR, str);
	/* verify */
}


int check_sync ()
{
	/* check that ground returns ACK */
}
