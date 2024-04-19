/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\thivy                                            */
/*    Created:      Fri Jan 17 2020                                           */
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
  baseFRight.startRotateFor(-450,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(-450,rotationUnits::deg,70,velocityUnits::pct);

  baseFRight.startRotateFor(250,rotationUnits::deg,70,velocityUnits::pct);
  baseBRight.rotateFor(250,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFLeft.rotateFor(250,rotationUnits::deg,70,velocityUnits::pct,false);
  baseBLeft.rotateFor(250,rotationUnits::deg,70,velocityUnits::pct);

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