# McGill Rocket Team - Avionics
This is the code repository for the Avionics sub team on the McGill Rocket Team.

## Sensors
Under the sensors folder, you'll find each sensor has it's own file. You are free to write the code for the sensor as you please and create any file you need. The only requirement is that you make a function available to produce the formatted string data from the sensors. The function will be called several times, in a polling fashion.

```C
while(someTestCondition) {
    // Execute some arbitrary code
    sensorOutput = yourFunction();
    // Execute other code
}
```

Everytime `yourFunction()` is called it should return a formatted string containing the sensors measure value at that moment in time. Please indicate the average runtime of your functons in microseconds.

The format string will have to store the data in CSV format like so

| Time   | Sensor Value 1 | Sensor Value 2 |
|--------|----------------|----------------|
| 1.50ms | 1820562        | 29             |
| 2.00ms | 1250721        | 34             |

**Note**: that `Time` should be the elapsed time since arduino start up.

## Data Scripts
The data collection scripts are to offload the data from the edison as quickly as possible.
What the scripts have to do:
1. Read the CSV files
2. Load up the data into memory
3. Create annotated graphs to analyze the data
4. Find critical flight values such as the height the rocket passes Mach 1 at

## CAD Models
Create the CAD models using [this](https://drive.google.com/open?id=0BzpGM0km5hh2N3dQbWIySmU0RWs) as your reference design. You can look up the Intel Edison Arduino Breakout for the pins.