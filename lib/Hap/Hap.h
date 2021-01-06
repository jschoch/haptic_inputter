#pragma once
#include <cstdint>

// A haptic device

enum class Htype{
    ThreeP,
    DETENT,
    FiveP,
};

enum class Evt{
    PONG,
    ACK,
    CHANGE
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
        int iState =0;
        //char name[];
        Htype myhtype;
        void pong();
        void ack();
        void send(Evt e);
        void receive(Evt e);
        void receive(Msg m);
        void print();
        Hap();
        Hap(int inid){
            id = inid;
        };
};
