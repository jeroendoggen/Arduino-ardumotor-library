// ArduMoto.h - Arduino library to control DC motos using the ArduMoto Shield
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Version History:
//  Version 0.1: setSpeed, fadeSpeed, brake
//
// Roadmap:
//  Version 0.2: ??
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

#ifndef ArduMotor_h
#define ArduMotor_h

#include "defines.h"

class ArduMoto
{
  public:
    ArduMoto();                                  // Constructor
    ~ArduMoto();                                 // Destructor

    void begin();

                                                  // Begin all sensors
    void beginMotoA(int directionPin, int pwmPin);
                                                  // Begin all sensors
    void beginMotoB(int directionPin, int pwmPin);

    void setSpeed(char moto, int speed);         // Set the speed of a selected moto, range: -100 to +100
    void fadeSpeed(char moto, int speed);        // Fade the speed of a moto: range -100 to 100

    void stop(char moto);
    void brake(char moto);

  private:
    int _motoSpeedA;
    int _motoSpeedB;
};
#endif
