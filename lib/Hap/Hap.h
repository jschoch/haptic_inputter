#pragma once
#define __min(a,b) ((a)<(b)?(a):(b))
#include <cstdint>

#ifdef UNIT_TEST
#include "fake_serial.h"
#include "fake_motor.h"
#else
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#endif

// A haptic device

enum class Htype:int{
    ThreeP,
    DETENT,
    FiveP
};

enum class Evt:int{
    PONG,
    ACK,
    CHANGE2
};

struct Msg{
    int id;
    int device_id;
    Evt e;
    int iState;
    Htype htype;
};

void printMsg(Msg m);

class Hap {

    public: 
        int id = 0;
        int foo;
        int iState = 0;
        Htype myhtype;
        FOCMotor motor;
        void pong();
        void ack();
        void send(Evt e);
        void receive(Evt e);
        void receive(Msg m);
        void print();
        Hap(int _id,FOCMotor _motor){
            id = _id;
            motor = _motor;
        };
};
