/** @file humidity.cpp
 *  @brief implementation of Humidity class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "humidity.h"

Humidity::Humidity(double value, std::string unit) : Condition(value, unit){
}

void Humidity::calcualteValue(double tempIn, double tempOut, double humOut, double humConst1, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && tempIn > 25.0) {
        newValue = getConditionValue() - (getConditionValue() - humOut) * (tempOut / tempIn) * humConst1 + humConst1/1000 * peopleInside - humConst1*10;
    } else {
        newValue = getConditionValue() - (getConditionValue() - humOut) * (tempOut / tempIn) * humConst1 + humConst1/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}
