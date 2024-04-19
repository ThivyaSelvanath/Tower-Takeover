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
  
  //intakes move inwards to pick up the pre-load cube
  intakeL.startRotateFor(400,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(400,rotationUnits::deg,70,velocityUnits::pct);

  //intakes spin inwards to pick up 4 cubes as the robot moves forward
  intakeL.startRotateFor(3000,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(3000,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(1200,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(1200,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(1200,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(1200,rotationUnits::deg,55,velocityUnits::pct);

  //robot stops for 1 second
  task::sleep(1000);

  //intakes spin inwards to keep cubes in the holder while robot moves backwards
  intakeL.startRotateFor(500,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(500,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct);

  //0.5 second rest
  task::sleep(500);

  //intakes spin inwards while the the robot turns 135 degrees clockwise
  intakeL.startRotateFor(450,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBRight.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFLeft.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBLeft.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct);

  //0.6 second rest
  task::sleep(600);

  //intakes spin inwards while the robot moves towards the scoring zone
  intakeL.startRotateFor(400,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(400,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(440,rotationUnits::deg,50,velocityUnits::pct,false);
  baseBRight.rotateFor(440,rotationUnits::deg,50,velocityUnits::pct,false);
  baseFLeft.rotateFor(440,rotationUnits::deg,50,velocityUnits::pct,false);
  baseBLeft.rotateFor(440,rotationUnits::deg,50,velocityUnits::pct); 

  //0.3 second rest
  task::sleep(300);

  //intakes spin outwards to make the cubes move down the holder
  intakeL.startRotateFor(-240,rotationUnits::deg,25,velocityUnits::pct);
  intakeR.rotateFor(-240,rotationUnits::deg,25,velocityUnits::pct);

  //0.6 second rest
  task::sleep(600);

  //holder moves upright so that the holder is 90 degrees to the ground
  Holder.startRotateFor(-330,rotationUnits::deg,15,velocityUnits::pct);

  //2.5 second rest
  task::sleep(2500);

  //intakes spin outwards to set the cubes on the ground
  intakeL.startRotateFor(-250,rotationUnits::deg,30,velocityUnits::pct);
  intakeR.rotateFor(-250,rotationUnits::deg,30,velocityUnits::pct);

  //0.7 second rest
  task::sleep(700);
 
  //intakes spin slowly outwards while the robot moves backwards
  intakeL.startRotateFor(-300,rotationUnits::deg,25,velocityUnits::pct);
  intakeR.rotateFor(-300,rotationUnits::deg,25,velocityUnits::pct,false);
  baseFRight.rotateFor(-600,rotationUnits::deg,50,velocityUnits::pct,false);
  baseBRight.rotateFor(-600,rotationUnits::deg,50,velocityUnits::pct,false);
  baseFLeft.rotateFor(-600,rotationUnits::deg,50,velocityUnits::pct,false);
  baseBLeft.rotateFor(-600,rotationUnits::deg,50,velocityUnits::pct);

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