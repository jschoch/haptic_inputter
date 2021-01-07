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
#endif