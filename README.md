# Arduino Sorting-Machine
This little machine can separate candys by colors :D, and you will know how it works.

## Getting Started

You need to make a platform like this with whatever material that you like.
https://drive.google.com/open?id=1swnZkbuRCmkgWeHbNkEo6ermeJFShEGG

### Prerequisites

The components that you need to have is:
```
1 Arduino all versions work here, we dont need much cables.
1 RGB Led
2 Servo Motors SG-90
1 RGB Color Sensor Tcs3200
1 Bag of Skittles i dont recommed chocolates like m&ms.
```

### Installing
RGB Led pins: (Check if its common anode)
```
redPin 12
greenPin 11
bluePin 13
```
Servo Motors:
```
Bottom servo in pin 8
Top servo in pin 7
```
RGB Sensor
```
S0 to pin 2
S1 to pin 3
S2 to pin 4
S3 to pin 5
SOut to pin 6
```

## Running the tests
with all connected you can check in the serial console on arduino IDE the RGB values when you pass a candy through the sensor, and then you can adjust the values to separate the skittles.

## Authors

* **Fabian Gaxiola** - *Initial work* - [fabiangax](https://github.com/fabiangax)
