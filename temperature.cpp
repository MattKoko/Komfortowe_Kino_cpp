#include "temperature.h"
#include "condition.h"

void Temperature::calcualteValue(double tempIn, double tempOut, double tempConst, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && tempIn > 25.0) {
        newValue = tempIn - tempConst * (tempIn - tempOut) + tempConst/1000 * peopleInside - tempConst*10;
    } else {
        newValue = tempIn - tempConst * (tempIn - tempOut) + tempConst/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}

