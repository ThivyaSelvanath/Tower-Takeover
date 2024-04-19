/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\thivy                                            */
/*    Created:      Mon Sep 9 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

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

void autonomous(void) {
  // no auton
}

void usercontrol(void) {

  while (1) {
    baseFLeft.spin(directionType::fwd, (Controller1.Axis3.value()),velocityUnits::pct);
    baseBLeft.spin(directionType::fwd, (Controller1.Axis3.value()),velocityUnits::pct);

    baseFRight.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);
    baseBRight.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);

    if (Controller1.ButtonL1.pressing()) {
      Holder.spin(directionType::fwd, 40, velocityUnits::pct);
    }

    else if (Controller1.ButtonL2.pressing()) {
      Holder.spin(directionType::fwd, -40, velocityUnits::pct);
    }

    else if (Controller1.ButtonR1.pressing()) {
      intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()) {
      intakeL.spin(directionType::fwd, -75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, -75, velocityUnits::pct);
    }

    else {
      Holder.stop(brakeType::hold);
      intakeL.stop(brakeType::hold);
      intakeR.stop(brakeType::hold);
    }

    vex::task::sleep(20);
  }
}

int main() {
  vexcodeInit();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
}

