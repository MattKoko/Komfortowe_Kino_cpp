/** @file room.cpp
 *  @brief implementation of Room class's method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "room.h"
#include "temperature.h"
#include "humidity.h"
#include "concentrationco2.h"
#include "controlpanel.h"

void Room::recalculateInsideTemperature(double tempConst, bool ventStatus, double peopleInside) {
    tempInside.calcualteValue(tempOutside.getConditionValue(), tempConst, ventStatus, peopleInside);
}
void Room::recalculateInsideConcentrationCO2(double co2Const1, double co2Const2, bool ventStatus, double peopleInside){
    co2Inside.calcualteValue(tempInside.getConditionValue(), humInside.getConditionValue(), co2Const1, co2Const2, ventStatus, peopleInside);
}
void Room::recalculateInsideHumidity(double humConst1, bool ventStatus, double peopleInside){
    humInside.calcualteValue(tempInside.getConditionValue(), tempOutside.getConditionValue(), humOutside.getConditionValue(), humConst1, ventStatus, peopleInside);
}

std::string Room::getRoomName() {
    return roomName;
}
Temperature Room::getTempInside() {
    return tempInside;
}
ConcentrationCO2 Room::getCO2Inside(){
    return co2Inside;
}
Humidity Room::getHumInside(){
    return humInside;
}
Temperature Room::getTempOutside() {
    return tempOutside;
}
ConcentrationCO2 Room::getCO2Outside(){
    return co2Outside;
}
Humidity Room::getHumOutside(){
    return humOutside;
}
ControlPanel Room::getControlPanel(){
    return controlPanel;
}
