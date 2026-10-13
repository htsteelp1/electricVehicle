#pragma once
#include <cmath>


namespace config {
    constexpr double targetPosition = 10;
    constexpr double linePosition = 13;
    constexpr double circumference = 6;
    constexpr double bottleSpeed = 1;
    constexpr double accelSpeed = 300;
    constexpr int microStep = 16;
    constexpr int steps = 200;
    constexpr int targetTime = 10;
}

namespace derived {
    constexpr double stepSize = config::circumference / ((config::steps) * config::microStep);


    constexpr int toSteps(const double distance) {
        const double steps = distance / stepSize;
        return static_cast<int>(steps >= 0 ? steps + 0.5 : steps - 0.5);
    }

    constexpr int lineStepPosition = toSteps(config::linePosition);
    constexpr int targetStepPosition = toSteps(config::targetPosition);
    constexpr int stepAccel = toSteps(config::accelSpeed);
    constexpr int stepBottleSpeed = toSteps(config::bottleSpeed);
    constexpr int accelV = config::accelSpeed*config::circumference;
    const double lineToTargetTime = config::targetTime -
        (accelV*config::linePosition+std::pow(config::bottleSpeed,2))/(accelV*config::bottleSpeed);
    const int targetSpeed = toSteps(-(accelV*lineToTargetTime -
        std::sqrt(pow(accelV*lineToTargetTime,2)-4*(config::linePosition-config::targetPosition)*accelV)/2));
}
