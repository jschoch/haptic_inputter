#include "Hap.h"
#include <cstdio>


Hap::Hap(){
    id= 0;
    myhtype = Htype::FiveP;
}

// send() always emits a change event and the current state
void Hap::ack(){
    printf("Sending ACK\n\n");
    this->print();
    Msg m = {12,this->id,Evt::CHANGE,this->iState,this->myhtype};
    printMsg(m);
}

void Hap::send(Evt e){
    printf(" sending event: %d\n",e);
}
void Hap::pong(){
    send(Evt::PONG);
}

void Hap::receive(Evt e){
    printf("got %d\n",e);
}

void Hap::receive(Msg m){
    printf("got msg id %d\n",m.id);
    switch( m.e) {
        case Evt::CHANGE :
            if (iState != m.iState){
                printf("updateing iState to: %d",m.iState);
                iState = m.iState;
            }
            break;
        default: 
            printf("unknown event type");
    }
    send(Evt::ACK);
}

void Hap::print(){
    printf("State: id: %d, iState: %d, htype %d\n", id,iState,myhtype);
}
void printMsg(Msg m){
    printf("Msg: id: %d device_id: %d, Event: %d, iState %d, htype: %d\n",m.id,m.device_id, m.e,m.iState,m.htype);
}