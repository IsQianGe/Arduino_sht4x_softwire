# SHT4x for Arduino
A simple Arduino library for the Sensirion SHT4x humidity and temperature sensors (SHT40, SHT41, SHT45). These are tiny sensors with an I2C interface. I've used some for my own projects and thought to clean up and release my code, in case it can save anyone some time. I'm not connected with Sensirion in any manner, so if you'd like technical details about the sensor itself you may want to check the [product page](https://www.sensirion.com/environmental-sensors/humidity-sensors/humidity-sensor-sht4x/) on their site. I can otherwise share my own experience if that helps. I may also have some breakout boards for purchase (contact me if you're interested).

# Installation
Create a SHT4x folder in your Arduino/libraries folder and copy the content of this repository in it. Then, restart the interface.
Alternatively, you can download the latest release [here](https://github.com/vpaeder/sensirion_sht4x/releases/tag/v1.0.1) and unpack it in your Arduino/library folder (and then restart the interface as well).

# How to use it
There's an example in the *examples* folder that can be opened straight from the Arduino interface.
For further details, you may refer to the comments and descriptions in SHT4x.h or ask me.
I've tested it on Arduino (Mega, Nano) and ESP32. I'm interested to know of any return on experience for other platforms compatible with the Arduino toolchain.

# Wiring example: ESP32 with SHT40 breakout board
To illustrate how to connect the sensor with an ESP32, I take my own breakout board (available for sale [here](https://www.ebay.de/sch/cent200/m.html?_nkw=&_armrs=1&_ipg=&_from=)) as an example. What's especially important here is that **the sensor works with 3.3V**. Don't connect VDD with 5V, or you'll likely burn your sensor. The I2C pins, on ESP32, are by default assigned to pins 21 (SDA) and 22 (SCL). They'll be placed elsewhere on other boards (e.g. D20 and D21 on Arduino Mega 2560, A4 and A5 for Arduino Nano, more details [here](https://www.arduino.cc/en/Reference/Wire)). You can see an example for ESP32-Devkit-C below.
![Wiring diagram for ESP32-Devkit-C](https://user-images.githubusercontent.com/6388158/125589786-1f625cb6-cfa0-4525-9944-ddfc16c91341.png)

