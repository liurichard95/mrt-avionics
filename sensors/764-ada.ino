
// include header
#include "764-ada.h"

GPS * allocate(void){
	return (GPS *) malloc(sizeof(GPS));
}

GPS * buildGPSstruct(char * latitude, char * longitude, char * altitude){
	GPS * data = allocate();

	data->latitude = latitude;
	data->longitude = longitude;
	data->altitude = altitude;

	return data;
}

/* --- temporary setup function for testing GPS sketch individually --- */
void setup(){
	Serial.begin(9600);

	GPS * test = buildGPSstruct("32.342234", "-52.432414", "122m");
	Serial.write(test->latitude);

}


void loop(){
	//Serial.write("hello world!\n");
}