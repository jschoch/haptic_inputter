#pragma once

#include <math.h>

#ifdef UNIT_TEST
#include "fake_serial.h"
#include "fake_motor.h"
#define _PI 3.1415926535
#define _round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#else
#include <SimpleFOC.h>
#endif

struct pidStuff{
    int p = 30;
    int i = 0;
    int limit = 6;
    PIDController cont = {.P=30,.I=0,.D=0,.output_ramp=100000,.limit=6};
};


class TPL{

    public:
        int detents;
        pidStuff zeroPID;
        pidStuff onePID;
        pidStuff twoPID;
        float detent_angle;
        float detent_radians;
        void run();
        void handlePos();

        float findAttractor(float current_angle);
        TPL();
        void init();
};