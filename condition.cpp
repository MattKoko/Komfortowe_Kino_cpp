/** @file condition.cpp
 *  @brief implementation of Condition class and its method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "condition.h"

Condition::Condition(double value, std::string unit){
    conditionValue = value;
    conditionUnit = unit;
}

double Condition::getConditionValue() {
    return conditionValue;
}

void Condition::setConditionValue(double newValue) {
    conditionValue = newValue;
}

std::string Condition::getConditionUnit() {
    return conditionUnit;
}

void Condition::setConditionUnit(std::string newUnit) {
    conditionUnit = newUnit;
}

void Condition::calcualteValue() {}
