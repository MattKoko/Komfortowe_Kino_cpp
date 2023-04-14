/** @file controlpanel.cpp
 *  @brief implementation of ControlPanel class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "controlpanel.h"

ControlPanel::ControlPanel(double peopleInside, bool ventilationSystemStatus){
    numberOfPeopleInside = peopleInside;
    ventilationSystemOnOff = ventilationSystemStatus;
}

double ControlPanel::getNumberOfPeopleInside() {
    return numberOfPeopleInside;
}

bool ControlPanel::getVentilationStatus() {
    return ventilationSystemOnOff;
}
