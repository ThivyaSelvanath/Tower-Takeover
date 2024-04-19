/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\thivy                                            */
/*    Created:      Sun Aug 25 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen

vex::brain       Brain;
vex::controller   Controller1;
vex::motor baseFLeft (vex::PORT1,vex::gearSetting::ratio18_1,false);
vex::motor baseFRight (vex::PORT2,vex::gearSetting::ratio18_1,true);
vex::motor baseBLeft (vex::PORT4,vex::gearSetting::ratio18_1,false);
vex::motor baseBRight (vex::PORT5,vex::gearSetting::ratio18_1,true);
vex::motor holderL (vex::PORT6,vex::gearSetting::ratio36_1,true);
vex::motor holderR (vex::PORT7,vex::gearSetting::ratio36_1,true);
vex::motor intakeR (vex::PORT8,vex::gearSetting::ratio18_1,true);
vex::motor intakeL (vex::PORT9,vex::gearSetting::ratio18_1,false);

// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  baseFRight.startRotateFor(-450,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct);

  baseFRight.startRotateFor(100,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(100,rotationUnits::deg,70,velocityUnits::pct);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  
  while (1) {
    baseFLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);
    baseBLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);
    
    baseFRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);
    baseBRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);

    if (Controller1.ButtonL1.pressing()){
      holderL.spin(directionType::fwd,70,velocityUnits::pct);
      holderR.spin(directionType::fwd,70,velocityUnits::pct);
    }  

    else if (Controller1.ButtonL2.pressing()){
      holderL.spin(directionType::fwd,-70,velocityUnits::pct);
      holderR.spin(directionType::fwd,-70,velocityUnits::pct);
    }

    else if (Controller1.ButtonR1.pressing()){
      intakeL.spin(directionType::fwd,80,velocityUnits::pct);                         
      intakeR.spin(directionType::fwd,80,velocityUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()){
      intakeL.spin(directionType::fwd,-80,velocityUnits::pct);
      intakeR.spin(directionType::fwd,-80,velocityUnits::pct);
    }
    else{
      holderL.stop(brakeType::hold);
      holderR.stop(brakeType::hold);
      intakeL.stop(brakeType::hold);
      intakeR.stop(brakeType::hold);
    }
    vex::task::sleep(20); 
  }
}

int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}