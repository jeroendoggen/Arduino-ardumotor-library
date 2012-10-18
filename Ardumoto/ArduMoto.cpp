// ArduMoto.cpp - Arduino library to control DC motors using the ArduMoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <ArduMoto.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

/// Constructor
ArduMoto::ArduMoto()
{
}

/// Destructor
ArduMoto::~ArduMoto()
{
//do something here? (free(), delete()?)
}

/// Begin Function: begin with default values (pin selection)
void ArduMoto::begin()
{
  beginMotoA(DIRECTION_PIN_A, PWM_PIN_A);
  beginMotoB(DIRECTION_PIN_B, PWM_PIN_B);
}

/// Begin Function for moto A (pin selection)
void ArduMoto::beginMotoA(int directionPin, int pwmPin)
{
  pinMode(PWM_PIN_A, OUTPUT);                     //Set control pins to be outputs
  pinMode(DIRECTION_PIN_A, OUTPUT);
  analogWrite(PWM_PIN_A, 0);                      //set moto A to run at (0/255 = 0)% duty cycle (stopped)
}

/// Begin Function for moto A
void ArduMoto::beginMotoB(int directionPin, int pwmPin)
{
  pinMode(PWM_PIN_B, OUTPUT);
  pinMode(DIRECTION_PIN_B, OUTPUT);
  analogWrite(PWM_PIN_B, 0);                      //set moto B to run at (0/255 = 0)% duty cycle (stopped)
}

/// setSpeed: from -100 to + 100
void ArduMoto::setSpeed(char moto, int speed)
{
  int throttle = map(abs(speed),0,100,0,255);

  if(moto == 'A')
  {
    _motoSpeedA = speed;
    if(speed >= 0)
    {
      digitalWrite(DIRECTION_PIN_A, HIGH);
    }
    if(speed < 0)
    {
      digitalWrite(DIRECTION_PIN_A, LOW);
    }
#ifdef DEBUG_MOTORS
    Serial.print("Setting Motor A to ");
    Serial.println(speed);
#endif
    analogWrite(PWM_PIN_A, throttle);
  }
  else if (moto == 'B')
  {
    _motoSpeedB = speed;
    if(speed >= 0)
    {
      digitalWrite(DIRECTION_PIN_B, HIGH);
    }
    if(speed < 0)
    {
      digitalWrite(DIRECTION_PIN_B, LOW);
    }
#ifdef DEBUG_MOTORS
    Serial.print("Setting Motor B to ");
    Serial.println(speed);
#endif
    analogWrite(PWM_PIN_B, throttle);
  }
}

/// slowChange: set the speed to desiredSpeed, adjusting slowly towards the desired value
void ArduMoto::slowChange(char moto, int desiredSpeed)
{
  int difference;

  if(moto == 'A')
  {
    difference = desiredSpeed - _motoSpeedA;
#ifdef DEBUG_MOTORS
    Serial.print("Difference: ");
    Serial.println(difference);
#endif
    while( _motoSpeedA != desiredSpeed)
    {
     if( _motoSpeedA < desiredSpeed )
     {
      _motoSpeedA++;
      setSpeed(moto, _motoSpeedA);
     }
    if( _motoSpeedA > desiredSpeed )
     {
      _motoSpeedA--;
      setSpeed(moto, _motoSpeedA);
     } 
   delay(SLOWCHANGEDELAY);
   } 
  }
  if(moto == 'B')
  {
    difference = desiredSpeed - _motoSpeedB;
#ifdef DEBUG_MOTORS
    Serial.print("Difference: ");
    Serial.println(difference);
#endif
    while( _motoSpeedB != desiredSpeed)
    {
     if( _motoSpeedB < desiredSpeed )
     {
      _motoSpeedB++;
      setSpeed(moto, _motoSpeedB);
     }
    if( _motoSpeedB > desiredSpeed )
     {
      _motoSpeedB--;
      setSpeed(moto, _motoSpeedB);
     } 
   delay(SLOWCHANGEDELAY);
   } 
  }
}

/// stop the motor
void ArduMoto::stop(char moto)
{
  setSpeed(moto, 0);
#ifdef DEBUG_MOTORS
  if(moto == 'A')
  {
    Serial.println("Stopping Motor A");
  }
  else if (moto == 'B')
  {
    Serial.println("Stopping Motor B");
  }
#endif
}

/// brake: brake the motor, using a temporary negative value (uses slowChange)
void ArduMoto::brake(char moto)
{
  if(moto == 'A')
  {
#ifdef DEBUG_MOTORS
    Serial.println("Braking Motor A");
#endif
    setSpeed(moto, - _motoSpeedA/BRAKESPEED);
    slowChange(moto,0);

  }
  else if (moto == 'B')
  {
#ifdef DEBUG_MOTORS
    Serial.println("Braking Motor B");
#endif
    setSpeed(moto, - _motoSpeedB/BRAKESPEED);
    slowChange(moto,0);
  }
}
