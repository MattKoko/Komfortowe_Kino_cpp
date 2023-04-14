/** @file temperature.cpp
 *  @brief implementation of Temperature class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "temperature.h"
#include "condition.h"

Temperature::Temperature(double value, std::string unit) : Condition(value, unit){
}

void Temperature::calcualteValue(double tempOut, double tempConst, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && getConditionValue() > 25.0) {
        newValue = getConditionValue() - tempConst * (getConditionValue() - tempOut) + tempConst/1000 * peopleInside - tempConst*10;
    } else {
        newValue = getConditionValue() - tempConst * (getConditionValue() - tempOut) + tempConst/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}

