
#ifndef chasis4Wheel_h
#define chasis4Wheel_h

#include "Arduino.h" 
#include "dcMotor.h" 

#include "RP2040_PWM.h"

class chasis4Wheel{
    protected:
      dcMotor frontLeft,frontRight,rearLeft,rearRight;
     // uint8_t steereddTurningRation;
      uint8_t mode;
      uint8_t duty;


    public:

      chasis4Wheel(dcMotor _leftFrontWheel, dcMotor _rightFrontWheel, dcMotor _leftRearWheel, dcMotor _rightRearWheel);
      void (* onStop)(void); //0
      void (* onForward)(void); //1 
      void (* onReverse)(void); //2
      void (* onTurnLeft)(void); // 3
      void (* onTurnRight)(void); //4
      void (* onAllLeft)(void); // 4 wheel turns  #index num# 5
      void (* onAllRight)(void); //5
      void (* onFrontTurnLeft)(void); //5
      void (* onFrontTurnRight)(void); //6
      void (* onRearTurnLeft)(void); //7
      void (* onRearTurnRight)(void); //8
      void (* onConcernLeftFront)(void); //9
      void (* onConcernRightFront)(void); //10
      void (* onConcernLeftRear)(void); //11
      void (* onConcernRightRear)(void); //12
      void (* onConcernCCWLeftFront)(void); //13
      void (* onConcernCCWRightFront)(void); //14
      void (* onConcernCCWLeftRear)(void); //15
      void (* onConcernCCWRightRear)(void); //16


      void stop(); //0
      void forward(); //1 
      void reverse(); //2
      void allLeft(); // 3 wheel turns  #index num# 5
      void allRight(); //4
      void frontTurnLeft();//5
      void frontTurnRight();//6
      void rearTurnLeft();//7
      void rearTurnRight();//8
      void concernLeftFront(); //9
      void concernRightFront(); //10
      void concernLeftRear(); //11
      void concernRightRear(); //12
      void concernCCWLeftFront(); //13
      void concernCCWRightFront(); //14
      void concernCCWLeftRear(); //15
      void concernCCWRightRear(); //16

      void setDuty(uint8_t duty);
};


#endif