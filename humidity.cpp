#include "humidity.h"

void Humidity::calcualteValue(double tempIn, double humIn, double tempOut, double humOut, double humConst1, bool ventStatus, double peopleInside) {
    double newValue;

    if(ventStatus && tempIn > 25.0) {
        newValue = humIn - (humIn - humOut) * (tempOut / tempIn) * humConst1 + humConst1/1000 * peopleInside - humConst1*10;
    } else {
        newValue = humIn - (humIn - humOut) * (tempOut / tempIn) * humConst1 + humConst1/1000 * peopleInside;
    }

    Condition::setConditionValue(newValue);
}
