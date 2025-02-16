
#include "Arduino.h" 
#include "dcMotor.h" 

#include "RP2040_PWM.h"
#include "chasis4Wheel.h"

chasis4Wheel::chasis4Wheel(dcMotor _leftFrontWheel, dcMotor _rightFrontWheel, dcMotor _leftRearWheel, dcMotor _rightRearWheel){
  frontLeft = _leftFrontWheel;
  frontRight = _rightFrontWheel;
  rearLeft = _leftRearWheel;
  rearRight = _rightRearWheel;
}




 void chasis4Wheel::stop(){
    frontLeft.stop();
    frontRight.stop();
    rearLeft.stop();
    rearRight.stop();

    if(onStop){
      onStop();
    }

    mode = 0;
}

  void chasis4Wheel::forward(){
    frontLeft.cw();
    frontRight.cw();
    rearLeft.cw();
    rearRight.cw();


    if(onForward){
      onForward();
    }
    
    mode = 1;
 }

   void chasis4Wheel::reverse(){
    frontLeft.ccw();
    frontRight.ccw();
    rearLeft.ccw();
    rearRight.ccw();


    if(onReverse){
      onReverse();
    }
    
    mode = 2;
 }


 //4 wheel turns

   void chasis4Wheel::allLeft(){
    frontLeft.cw();
    frontRight.ccw();
    rearLeft.cw();
    rearRight.ccw();

      if(onAllLeft){
      onAllLeft();
    }
    mode = 3;
 }

    void chasis4Wheel::allRight(){
    frontLeft.ccw();
    frontRight.cw();
    rearLeft.ccw();
    rearRight.cw();

    if(onAllRight){
    onAllRight();
    }

    mode = 4;
 }

 //2wheel turns

    void chasis4Wheel::frontTurnLeft(){
    frontLeft.cw();
    frontRight.ccw();
    rearLeft.stop();
    rearRight.stop();
    
    if(onFrontTurnLeft){
      onFrontTurnLeft();
    }
    mode = 5;
 }

  void chasis4Wheel::frontTurnRight(){
    frontLeft.ccw();
    frontRight.cw();
    rearLeft.stop();
    rearRight.stop();

    if(onFrontTurnRight){
      onFrontTurnRight();
    }

    mode = 6;
 }

   void chasis4Wheel::rearTurnLeft(){
    frontLeft.stop();
    frontRight.stop();
    rearLeft.cw();
    rearRight.ccw();
    
    if(onRearTurnLeft){
      onRearTurnLeft();
    }
    mode = 7;
 }

   void chasis4Wheel::rearTurnRight(){
    frontLeft.stop();
    frontRight.stop();
    rearLeft.ccw();
    rearRight.cw();

      if(onRearTurnRight){
      onRearTurnRight();
    }

    mode = 9;
 }

    void chasis4Wheel::concernRightFront(){
    frontLeft.stop();
    frontRight.cw();
    rearLeft.stop();
    rearRight.stop();

    if(onConcernRightFront){
      onConcernRightFront();
    }

    mode = 10;
 }

     void chasis4Wheel::concernLeftRear(){
    frontLeft.stop();
    frontRight.stop();      onConcernLeftFront();
    rearLeft.cw();
    rearRight.stop();

    if(onConcernLeftRear){
      onConcernLeftRear();
    }

    mode = 11;
 }

    void chasis4Wheel::concernRightRear(){      onConcernLeftFront();
    frontLeft.stop();
    frontRight.stop();
    rearLeft.stop();
    rearRight.cw();

    if(onConcernRightRear){
      onConcernRightRear();
    }

    mode = 12;
 }

    void chasis4Wheel::concernCCWLeftFront(){
    frontLeft.ccw();
    frontRight.stop();
    rearLeft.stop();
    rearRight.stop();

        if(onConcernCCWLeftFront){
      onConcernCCWLeftFront();
    }

    mode = 13;
 }

    void chasis4Wheel::concernCCWRightFront(){
    frontLeft.stop();
    frontRight.ccw();
    rearLeft.stop();
    rearRight.stop();

        if(onConcernCCWRightFront){
      onConcernCCWRightFront();
    }

    mode = 14;
 }

     void chasis4Wheel::concernCCWLeftRear(){
    frontLeft.stop();
    frontRight.stop();
    rearLeft.ccw();
    rearRight.stop();

        if(onConcernCCWLeftRear){
      onConcernCCWLeftRear();
    }

    mode = 15;
 }

    void chasis4Wheel::concernCCWRightRear(){
    frontLeft.stop();
    frontRight.stop();
    rearLeft.stop();
    rearRight.ccw();
    mode = 16;

        if(onConcernCCWRightRear){
      onConcernCCWRightRear();
    }
  }

    void chasis4Wheel::setDuty(uint8_t _duty){
      frontLeft.setDuty(_duty);
      frontRight.setDuty(_duty);
      rearLeft.setDuty(_duty);
      rearRight.setDuty(_duty);
      duty = _duty;
    
 }
