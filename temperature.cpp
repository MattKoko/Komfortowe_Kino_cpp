/** @file temperature.cpp
 *  @brief implementation of Temperature class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

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

