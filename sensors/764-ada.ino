
#include "764-ada.h"

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.write("hello world!\n");
}