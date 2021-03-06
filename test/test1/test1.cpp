
#ifdef UNIT_TEST

#include <unity.h>
#include <iostream>
#include <Hap.h>
#include <fake_motor.h>
#include <threePosLever.h>


int main( int argc, char **argv) {
    UNITY_BEGIN();
    
    FOCMotor motor = FOCMotor();
    TPL tpl;
    Hap hap = Hap(0,&motor);



    std::cout  << "Hap id " << hap.id << "\n";

    //TEST_ASSERT_EQUAL_INT(1,hap.id);

    Hap hap2 = Hap(100,&motor);

    std::cout  << "Hap id " << hap2.id << "\n";
    
    TEST_ASSERT_EQUAL_INT(100,hap2.id);

    hap.receive(Evt::CHANGE2);


    // initialize the Hap

    //hap.init();

    // Mock ELS send ping

    // ack ping with pong
    hap.pong();

    // Mock ELS send mode

    Msg m = {11,hap.id,Evt::CHANGE2,100,Htype::FiveP};

    hap.receive(m);

    // Mock ELS set state

    m = {11,hap.id,Evt::CHANGE2,0,Htype::FiveP};
    hap.receive(m);
    // Change state, send msg

    hap.iState = -1;
    hap.ack();

    // waiting for ack

    // ack received, do something with it
    m = {11,hap.id,Evt::CHANGE2,-2,Htype::FiveP};
    hap.receive(m);
    hap.ack();

    // Mock ELS sends done state change event msg
    m = {11,hap.id,Evt::CHANGE2,0,Htype::FiveP};
    hap.receive(m);
    hap.ack();




    return 0;
    UNITY_END();
}

#endif