# McGill Rocket Team - Avionics
This is the code repository for the Avionics sub team on the McGill Rocket Team.

## General Instructions
* If you don't have access, please message me on slack and give me your username
* Create a new branch for your sensor and push all your changes to the branch
* If you feel like your done, then create a pull request to merge to master

I'll merge to master after our team code review sessions. Timeline to be posted soon.

## Sensors
Under the sensors folder, you'll find each sensor has it's own file. You are free to write the code for the sensor as you please and create any file you need. The only requirement is that you make a function available to produce the formatted string data from the sensors. The function will be called several times, in a polling fashion.

```C
while(someTestCondition) {
    // Execute some arbitrary code
    sensorOutput = yourFunction();
    // Execute other code
}
```

Everytime `yourFunction()` is called it should return a struct containing sensor data for that moment in time. Please indicate the average runtime of your functons in microseconds.

#### Some useful libraries
1. [Easy Transfer](http://www.billporter.info/2011/05/30/easytransfer-arduino-library/)
2. [Tiny GPS](http://arduiniana.org/libraries/tinygps/)
3. [Sensor Libs](https://learn.adafruit.com/adafruit-10-dof-imu-breakout-lsm303-l3gd20-bmp180/software/)

## Data Scripts
The data collection scripts are to offload the data from the edison as quickly as possible.
What the scripts have to do:

1. Read the CSV files
2. Load up the data into memory
3. Create annotated graphs to analyze the data
4. Find critical flight values. Such as the height the rocket reaches Mach 1 at

## CAD Models
Create the CAD models using [this](https://drive.google.com/open?id=0BzpGM0km5hh2N3dQbWIySmU0RWs) as your reference design. You can look up the Intel Edison Arduino Breakout for the pins.
