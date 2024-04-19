using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor baseFLeft;
extern motor baseFRight;
extern motor baseBLeft;
extern motor baseBRight;
extern motor intakeR;
extern motor intakeL;
extern motor Holder;
extern controller Controller1;
extern motor Arms;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );