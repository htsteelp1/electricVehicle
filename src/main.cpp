#include <Arduino.h>
#include <FastAccelStepper.h>
#include "pins.h"
#include "config.h"
FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;


void setup() {
    engine.init();
    stepper = engine.stepperConnectToPin(pins::STEPPER);
}

void loop() {
    
}
