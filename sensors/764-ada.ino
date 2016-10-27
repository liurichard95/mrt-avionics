
// include header
#include "764-ada.h"


GPS * allocate(void){
	return (GPS *) malloc(sizeof(GPS));
}

void buildGPSstruct(GPS * data, char * latitude, char * longitude, char * altitude){
	data->latitude = latitude;
	data->longitude = longitude;
	data->altitude = altitude;
}

GPS * getGPSData() {
	GPS * data = allocate();
}

void init(void){
	// create new serial connection
	Serial.begin(115200);

	// 9600 NMEA is the default baud rate for MTK - some use 4800
  	GPS.begin(9600);

  	// tell GPS to turn on RMC and GGA
  	GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  	// set the GPS update rate to 5HZ
  	GPS.sendCommand(PMTK_SET_NMEA_UPDATE_5HZ);
  	GPS.sendCommand(PMTK_API_SET_FIX_CTL_5HZ);

}

/* --- temporary setup function for testing GPS sketch individually --- */
void setup(){

	



	GPS * test = allocate();
	buildGPSstruct(test, "32.342234", "-52.432414", "122m");
	Serial.write(test->latitude);

}


void loop(){
	//Serial.write("hello world!\n");
}