# Arduino Ardumoto Library

Arduino library for the SparkFun Ardumoto Motor Driver Shield

## Overview:
This library simplifies the usage of the SparkFun Ardumoto shield in Arduino projects.
This motor shield controls two DC motors with a L298 H-bridge that can drive up to 2 amps per channel.

More info: https://www.sparkfun.com/products/9815

## Features:
  * Set the motor at a desired speed: range -100 up to +100
  * Brake the motor
  * Change the motor speed slowly

## Library Usage:
  * Download the source
  * Place the "ArdoMoto" folder in your Arduino1.0+ "libraries" folder
  * Open example sketch: "file", "Examples", "Ardumoto", "SetSpeed" (or "Braking" or "SlowChange")
  * Connect the shield (and connect Vcc and GND on the shield to an extra power supply )
  * Compile & upload code
  * The motor should be running as described in the examples

## Version History:
  * Version 0.2: everything tested on hardware + more useful examples
  * Version 0.1: wrote the code without testing it on actual hardware
