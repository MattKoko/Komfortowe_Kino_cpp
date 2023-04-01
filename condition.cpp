/** @file condition.cpp
 *  @brief implementation of Condition class and its method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "condition.h"

double Condition::getConditionValue() {
    return value;
}

void Condition::calcualteValue() {}

void Condition::setConditionValue(double newValue) {
    value = newValue;
}
