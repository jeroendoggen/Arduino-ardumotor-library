// Ardumoto.h - Arduino library to control DC motos using the Ardumoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef Ardumotor_h
#define Ardumotor_h

#include "defines.h"

class Ardumoto
{
  public:
    Ardumoto();                                   // Constructor
    ~Ardumoto();                                  // Destructor

    void begin();
    void beginMotoA(int directionPin, int pwmPin);
    void beginMotoB(int directionPin, int pwmPin);

    void setSpeed(char moto, int speed);          // Set the speed of a selected motor, range: -100 to +100
    void slowChange(char moto, int speed);        // Fade the speed of a motor slowly to a specific value: range -100 to 100

    void stop(char moto);
    void brake(char moto);                        // Brake the motor
    void brakeAgressive(char moto);               // Brake the motor

  private:
    int _motoSpeedA;
    int _motoSpeedB;
};
#endif
