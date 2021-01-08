#pragma once

#ifdef UNIT_TEST
#ifndef FOCMOTOR_H
#define FOCMOTOR_H



#include "fake_serial.h"
class FOCMotor{
    public:
        void move(float target);
        FOCMotor(){};
};
#endif

class PIDController
{
public:
    PIDController(float P, float I, float D, float ramp, float limit){};
    ~PIDController() = default;


    float P; //!< Proportional gain 
    float I; //!< Integral gain 
    float D; //!< Derivative gain 
    float output_ramp; //!< Maximum speed of change of the output value
    float limit; //!< Maximum output value
};
#endif