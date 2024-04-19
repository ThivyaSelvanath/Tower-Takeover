/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\thivy                                            */
/*    Created:      Tue Feb 04 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// baseFLeft            motor         1               
// baseFRight           motor         2               
// baseBLeft            motor         4               
// baseBRight           motor         5               
// intakeR              motor         6               
// intakeL              motor         7               
// Holder               motor         8               
// Arms                 motor         9               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
vex::competition Competition;

using namespace vex;

void autonomous (void) {

  intakeL.startRotateFor(2100,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(2100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct);

  task::sleep(1000);

  intakeL.startRotateFor(500,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(500,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct);

  task::sleep(500);

  intakeL.startRotateFor(450,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBRight.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFLeft.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBLeft.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct);

  task::sleep(800);

  intakeL.startRotateFor(400,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(400,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBRight.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFLeft.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBLeft.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct); 

  task::sleep(800);

  Holder.startRotateFor(-340,rotationUnits::deg,40,velocityUnits::pct);

  task::sleep(600);

  intakeL.startRotateFor(-200,rotationUnits::deg,60,velocityUnits::pct);
  intakeR.rotateFor(-200,rotationUnits::deg,60,velocityUnits::pct);

  
  task::sleep(700);

  intakeL.startRotateFor(-350,rotationUnits::deg,60,velocityUnits::pct);
  intakeR.rotateFor(-350,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFRight.rotateFor(-300,rotationUnits::deg,5,velocityUnits::pct,false);
  baseBRight.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct);


  // task::sleep(800);

  //90 degree = 350

  // baseFRight.startRotateFor(-100,rotationUnits::deg,30,velocityUnits::pct);
  // baseBRight.rotateFor(-100,rotationUnits::deg,30,velocityUnits::pct,false);
  // baseFLeft.rotateFor(-100,rotationUnits::deg,30,velocityUnits::pct,false);
  // baseBLeft.rotateFor(-100,rotationUnits::deg,30,velocityUnits::pct); 
}




void usercontrol( void ) {

  while (1) {
    baseFLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);
    baseBLeft.spin(directionType::fwd,(Controller1.Axis3.value()),velocityUnits::pct);

    baseFRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);
    baseBRight.spin(directionType::fwd,(Controller1.Axis2.value()),velocityUnits::pct);

    if (Controller1.ButtonLeft.pressing()){
      Holder.spin(directionType::fwd,65,velocityUnits::pct);
    }

    else if(Controller1.ButtonA.pressing()){
      Holder.spin(directionType::rev,65,velocityUnits::pct);
    }

    else if (Controller1.ButtonR1.pressing()){
      intakeL.spin(directionType::fwd,75,velocityUnits::pct);
      intakeR.spin(directionType::fwd,75,velocityUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()){
      intakeL.spin(directionType::rev,75,velocityUnits::pct);
      intakeR.spin(directionType::rev,75,velocityUnits::pct);
    }

    else if (Controller1.ButtonL1.pressing()) {
      Arms.spin(directionType::fwd, 60, velocityUnits::pct);
    }

    else if (Controller1.ButtonL2.pressing()) {
      Arms.spin(directionType::rev, 60, velocityUnits::pct);
    }


    else{
      Holder.stop(brakeType::hold);
      intakeL.stop(brakeType::hold);
      intakeR.stop(brakeType::hold);
      Arms.stop(brakeType::hold);
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