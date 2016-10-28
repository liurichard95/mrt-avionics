/* ITG 3200 Gyroscope
 *
 */

#include <stdio.h>
#include <Wire.h>

//Default device address (check the module to make sure...)
char ITG_ADDRESS = 0b110100;

//Confiruration registers addresses

char WHO_AM_I = 0x00;

char SMPL_RATE_DIV = 0x15;
char DLPF = 0x16;
char INT_CONF = 0x17;
char INT_STAT = 0x1A;

//Data registers addresses

char TEMP_M = 0x1B;
char TEMP_L = 0x1C;
char GYRO_X_M = 0x1D;
char GYRO_X_L = 0x1E;
char GYRO_Y_M = 0x1F;
char GYRO_Y_L = 0x20;
char GYRO_Z_M = 0x21;
char GYRO_Z_L = 0x22;

//Initialisation values
char INIT_SMPL = 9; //100Hz sample rate
char INIT_DLPF = 0b00011111; //3lsb : 1kHz 42Hz low-pass

// Device manipulation routines

unsigned char ITG_read(char register_address)
{
	//As the device for the data
	Wire.beginTransmission(ITG_ADDRESS);
	Wire.write(register_address);
	Wire.endTransmission();
	//Read the device
	Wire.beginTransmission(ITG_ADDRESS);
	Wire.requestFrom(ITF_ADDRESS,1);
	//if data are available read it
	if(Wire.available()) {
		data = Wire.read();
	}
	return data;
}

void ITG_write (char register_address, char data)
{
	//Write to register
	Wire.beginTransmission(ITG_ADDRESS);
	Wire.write(register_address);
	Wire.write(data);
	Wire.endTransmission();
}

//device initilisation values

void ITG_init()
{
	ITG_write(SMPL_RATE_DIV, INIT_SMPL);
	ITG_write(DLPF, INIT_DLPF);
}

struct current_raw_values {
	int x;
	int y;
	int x;
};

void get_raw_values (struct current_raw_values * cur)
{
	cur->x = (ITG_read(GYRO_X_H)<<8) + ITG_read(GYRO_X_L);
	cur->y = (ITG_read(GYRO_Y_H)<<8) + ITG_read(GYRO_Y_L);
	cur->z = (ITG_read(GYRO_Z_H)<<8) + ITG_read(GYRO_Z_L);
}

//copies the last updated values into a string

void copy_values_from_struct (char * out_str, struct current_raw_values * cur)
{
	sprintf(out_str, "ITG %6d %6d %6d", cur->x, cur->y, cur->y);
}


void copy_actual_values (char * out_str)
{
	struct current_raw_values val;
	get_raw_values(&val);
	copy_values_from_struct(out_str, current);
}


