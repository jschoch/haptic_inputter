#include "fake_motor.h"
#include <iostream>

#ifdef UNIT_TEST

void FOCMotor::move(float target){
    std::cout << "FOCMove " << target << "\n";

};

#endif
