#include <Arduino.h>
#include <FastAccelStepper.h>
#include "pins.h"
#include "config.h"
FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;


void setup() {
    engine.init();
    stepper = engine.stepperConnectToPin(pins::STEPPER);
    if (stepper) {
        stepper->setDirectionPin(pins::DIRECTION);
        stepper->setSpeedInHz(config::bottleSpeed);
        stepper->setAcceleration(derived::stepAccel);
        stepper->setCurrentPosition(0);
        stepper->moveTo(derived::lineStepPosition);
        while (stepper->isRunning()) {}
    }
}

void loop() {

}
