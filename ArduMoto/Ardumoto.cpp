// Ardumoto.cpp - Arduino library to control DC motors using the Ardumoto Shield
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

#include <Ardumoto.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

/// Constructor
Ardumoto::Ardumoto()
{
  _motoSpeedA=0;
  _motoSpeedB=0;
}

/// Destructor
Ardumoto::~Ardumoto()
{
//do something here? (free(), delete()?)
}

/// Begin Function: begin with default values (pin selection)
void Ardumoto::begin()
{
  beginMotoA(DIRECTION_PIN_A, PWM_PIN_A);
  beginMotoB(DIRECTION_PIN_B, PWM_PIN_B);
}

/// Begin Function for moto A (pin selection)
void Ardumoto::beginMotoA(int directionPin, int pwmPin)
{
  pinMode(PWM_PIN_A, OUTPUT);                     //Set control pins to be outputs
  pinMode(DIRECTION_PIN_A, OUTPUT);
  analogWrite(PWM_PIN_A, 0);                      //set moto A to run at (0/255 = 0)% duty cycle (stopped)
}

/// Begin Function for moto B
void Ardumoto::beginMotoB(int directionPin, int pwmPin)
{
  pinMode(PWM_PIN_B, OUTPUT);                     //Set control pins to be outputs
  pinMode(DIRECTION_PIN_B, OUTPUT);
  analogWrite(PWM_PIN_B, 0);                      //set moto B to run at (0/255 = 0)% duty cycle (stopped)
}

/// setSpeed: from -100 to + 100
void Ardumoto::setSpeed(char moto, int speed)
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
void Ardumoto::slowChange(char moto, int desiredSpeed)
{
  if(moto == 'A')
  {
#ifdef DEBUG_MOTORS
    int difference;
    difference = desiredSpeed - _motoSpeedA;
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
#ifdef DEBUG_MOTORS
    difference = desiredSpeed - _motoSpeedB;
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
void Ardumoto::stop(char moto)
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
void Ardumoto::brakeAgressive(char moto)
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

/// brake: really braking the motor electronically is not possible (because of the 74HC1G04 inverter)
void Ardumoto::brake(char moto)
{
  if(moto == 'A')
  {
#ifdef DEBUG_MOTORS
    Serial.print("Braking Motor A");
    Serial.println(speed);
#endif
    setSpeed(moto, 0);
  }

  if(moto == 'B')
  {
#ifdef DEBUG_MOTORS
    Serial.print("Braking Motor B");
    Serial.println(speed);
#endif
    setSpeed(moto, 0);
  }
}
