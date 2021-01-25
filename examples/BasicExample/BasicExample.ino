/*
  This is a basic example showing how to use the SHT4x library to communicate with
  the Sensirion SHT4x range of humidity and temperature sensors.
  This example connects to a sensor, does a basic setup and keeps measuring new data
  every second. It then prints out the result over the serial line.
*/
// include SHT4x library header
#include "SHT4x.h"

// define SHT4x instance
SHT4x sht;

void setup() {
  // setup serial port to communicate with computer
  Serial.begin(115200);
  // open I2C connection
  Wire.begin();
  // set SHT4x chip type (see SHT4x.h for details)
  sht.setChipType(SHT4X_CHIPTYPE_A);
  // set SHT4x measurement mode (see SHT4x.h for details)
  sht.setMode(SHT4X_CMD_MEAS_HI_PREC);
  // check that serial number can be read and matches expectations
  if (sht.checkSerial() == SHT4X_STATUS_OK) {
    Serial.print("Device serial number: 0x");
    Serial.print(sht.serial[0], HEX);
    Serial.print(sht.serial[1], HEX);
    Serial.println();
  } else {
    Serial.println("Failed to read serial, or serial checksum incorrect.");
  }
}

void loop() {
  // measure with set measurement mode
  if (sht.measure() != SHT4X_STATUS_OK) {
    Serial.println("Measurement failed!");
  }
  // check that data is correct and, if so, print it out
  if (sht.TcrcOK) {
    Serial.print("Temperature: ");
    // print out temperature in degrees Celsius
    // for degrees Fahrenheit, use function TtoDegF instead
    Serial.print(sht.TtoDegC());
    Serial.println(" °C");
  } else {
    Serial.println("Temperature checksum incorrect!");
  }
  if (sht.RHcrcOK) {
    Serial.print("Relative humidity: ");
    Serial.print(sht.RHtoPercent());
    Serial.println("%");
  } else {
    Serial.println("Relative humidity checksum incorrect!");
  }
  // wait for 1 second till next measurement
  delay(1000);
}
