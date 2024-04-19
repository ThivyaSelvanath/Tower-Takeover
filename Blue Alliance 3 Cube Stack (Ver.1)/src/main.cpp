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

  //intakes move inwards whilst the base moves forwards simultaneously, to pick up 3 cubes
  intakeL.startRotateFor(2100,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(2100,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(1380,rotationUnits::deg,55,velocityUnits::pct);

  //the robot stops for 1 second (1000 milliseconds)
  task::sleep(1000);

  //intakes move inwards to keep the cubes in the holder while the base moves backwards
  intakeL.startRotateFor(500,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(500,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(-700,rotationUnits::deg,55,velocityUnits::pct);

  //0.5 second rest
  task::sleep(500);

  //intakes move inwards whilst the base turns 135 degrees clockwise
  intakeL.startRotateFor(450,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(450,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBRight.rotateFor(500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFLeft.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBLeft.rotateFor(-500,rotationUnits::deg,60,velocityUnits::pct);

  //0.8 second rest
  task::sleep(800);

  //intakes move inwards while moving forwards and towards the red scoring zone
  intakeL.startRotateFor(400,rotationUnits::deg,70,velocityUnits::pct);
  intakeR.rotateFor(400,rotationUnits::deg,70,velocityUnits::pct,false);
  baseFRight.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBRight.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFLeft.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct,false);
  baseBLeft.rotateFor(650,rotationUnits::deg,60,velocityUnits::pct); 

  //0.8 second rest
  task::sleep(800);

  //the holder moves upright in order to stack the 3 cubes into the scoring zone
  Holder.startRotateFor(-340,rotationUnits::deg,40,velocityUnits::pct);

  //0.6 second rest
  task::sleep(600);

  //intakes move outwards to stack the cubes on the ground
  intakeL.startRotateFor(-200,rotationUnits::deg,60,velocityUnits::pct);
  intakeR.rotateFor(-200,rotationUnits::deg,60,velocityUnits::pct);

  //0.7 second rest
  task::sleep(700);

  //intakes move outwards while the robot moves backwards and away from the scoring zone
  intakeL.startRotateFor(-350,rotationUnits::deg,60,velocityUnits::pct);
  intakeR.rotateFor(-350,rotationUnits::deg,60,velocityUnits::pct,false);
  baseFRight.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBRight.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct,false);
  baseFLeft.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct,false);
  baseBLeft.rotateFor(-300,rotationUnits::deg,55,velocityUnits::pct);

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



