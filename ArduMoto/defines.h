/// DEBUG
// Enable or disable serial debugging of motor speed (comment next line to disable)
//#define DEBUG_MOTORS

/// OUTPUT
#define DIRECTION_PIN_A  12
#define DIRECTION_PIN_B  13
#define PWM_PIN_A  3
#define PWM_PIN_B  11

/// ADJUST BRAKING AND FADING SPEED
#define SLOWCHANGEDELAY 10                        // higher number: slower fading: 1=no fading
#define BRAKESPEED 3                              // smaller number less abrupt braking (braking reuses FADESPEED)
