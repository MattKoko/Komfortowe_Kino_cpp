#include "concentrationco2.h"

void ConcentrationCO2::calcualteValue(double tempIn, double concCO2In, double humIn, double co2Const1, double co2Const2, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && tempIn > 25.0) {
        newValue = concCO2In + co2Const1 * (concCO2In - 400.0) * (tempIn / 298.0) * (101.3 / 760.0) + co2Const2 * (concCO2In - 400.0) * (humIn / 100.0) + co2Const1/1000 * peopleInside - co2Const1*10;
    } else {
        newValue = concCO2In + co2Const1 * (concCO2In - 400.0) * (tempIn / 298.0) * (101.3 / 760.0) + co2Const2 * (concCO2In - 400.0) * (humIn / 100.0) + co2Const1/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}
