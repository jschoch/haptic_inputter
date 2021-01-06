#pragma once


#ifdef UNIT_TEST
    #include "ArduinoFake.h"
#else
    #include "Arduino.h"
    #include <ArduinoJson.h>
    #include <SimpleFOC.h>
#endif

#include <Hap.h>
#include "lib/"
#include "threePosLever.h"