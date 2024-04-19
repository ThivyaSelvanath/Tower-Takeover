// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// baseFLeft            motor         1               
// baseFRight           motor         2               
// baseBLeft            motor         4               
// baseBRight           motor         5               
// intakeR              motor         6               
// intakeL              motor         7               
// Holder               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


vex::competition Competition;

using namespace vex;

void autonomous (void) {
  intakeL.startRotateFor(300,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(300,rotationUnits::deg,70,velocityUnits::pct);

  vex::task::sleep(500);

  baseFRight.startRotateFor(450,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct);

  vex::task::sleep(500);

  intakeL.startRotateFor(-300,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(-300,rotationUnits::deg,70,velocityUnits::pct);  

  vex::task::sleep(500);

  baseFRight.startRotateFor(-100,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(-100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(-100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(-100,rotationUnits::deg,70,velocityUnits::pct);

}




void usercontrol( void ) {

  while (1) {
    baseFLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);
    baseBLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);

    baseFRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);
    baseBRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);

    if (Controller1.ButtonL1.pressing()){
      Holder.spin(directionType::fwd,40,velocityUnits::pct);
    }

    else if(Controller1.ButtonL2.pressing()){
      Holder.spin(directionType::rev,40,velocityUnits::pct);
    }

    else if (Controller1.ButtonR1.pressing()){
      intakeL.spin(directionType::fwd,75,velocityUnits::pct);
      intakeR.spin(directionType::fwd,75,velocityUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()){
      intakeL.spin(directionType::rev,75,velocityUnits::pct);
      intakeR.spin(directionType::rev,75,velocityUnits::pct);
    }


    else{
      Holder.stop(brakeType::hold);
      intakeL.stop(brakeType::hold);
      intakeR.stop(brakeType::hold);
    }

    vex::task::sleep(20);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.autonomous( autonomous );
  Competition.drivercontrol (usercontrol);
}

/////robot settings





// /*----------------------------------------------------------------------------*/
// /*                                                                            */
// /*    Module:       main.cpp                                                  */
// /*    Author:       C:\Users\thivy                                            */
// /*    Created:      Sat Sep 21 2019                                           */
// /*    Description:  V5 project                                                */
// /*                                                                            */
// /*----------------------------------------------------------------------------*/
// #include "vex.h"
// 
// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// 