#include "Hap.h"
#include <cstdio>
#include <ArduinoJson.h>

DynamicJsonDocument msgDoc(100);
char outBuffer[100];

void initMsgDoc(){
    msgDoc["e"] = 0;
    msgDoc["id"] = 0;
    msgDoc["mid"] = 0;
    msgDoc["s"] = 0;
    msgDoc["t"] = 0; 
}



// send() always emits a change event and the current state
void Hap::ack(){
    initMsgDoc();
    printf("Sending ACK\n\n");
    this->print();
    Msg m = {12,this->id,Evt::CHANGE2,this->iState,this->myhtype};
    printMsg(m);
}

void Hap::send(Evt e){
    //msgDoc["e"] = static_cast<int>(e);
    msgDoc["e"] = 0;
    //size_t len = serializeMsgPack(msgDoc,outBuffer);
    size_t len = serializeJson(msgDoc, outBuffer);
    printf(" sending event: %d len: %d\n%s",e,len,outBuffer);
    Serial.print(outBuffer);
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
        case Evt::CHANGE2 :
            if (iState != m.iState){
                printf("updateing iState to: %d",m.iState);
                iState = m.iState;
                motor.move(iState);
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