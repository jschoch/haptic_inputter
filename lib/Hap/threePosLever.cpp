#include "threePosLever.h"


TPL::TPL(){
    detents = 5;
    struct pidStuff zPs;
    

}

void TPL::init(){
    detent_radians = detent_angle *_PI/180.0;
}

float TPL::findAttractor(float current_angle){
    return round(current_angle/detent_radians)*detent_radians;
}