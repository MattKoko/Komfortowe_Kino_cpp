/** @file concentrationco2.cpp
 *  @brief implementation of ConcentrationCO2 class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "concentrationco2.h"

ConcentrationCO2::ConcentrationCO2(double value, std::string unit) : Condition(value, unit){
}

void ConcentrationCO2::calcualteValue(double tempIn, double humIn, double co2Const1, double co2Const2, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && tempIn > 25.0) {
        newValue = getConditionValue() + co2Const1 * (getConditionValue() - 400.0) * (tempIn / 298.0) * (101.3 / 760.0) + co2Const2 * (getConditionValue() - 400.0) * (humIn / 100.0) + co2Const1/1000 * peopleInside - co2Const1*10;
    } else {
        newValue = getConditionValue() + co2Const1 * (getConditionValue() - 400.0) * (tempIn / 298.0) * (101.3 / 760.0) + co2Const2 * (getConditionValue() - 400.0) * (humIn / 100.0) + co2Const1/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}
