/** @file simulation.cpp
 *  @brief implementation of Simulation class and its methods.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "simulation.h"
#include "temperature.h"
#include "humidity.h"
#include "concentrationco2.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <string>
#include <sstream>
#include <QLabel>
#include <QListView>
using namespace std;

Simulation::Simulation() {}

void Simulation::recalculateConditions(Room room, int timeOfSimulationInMinutes, QListWidget* outputList) {
    //Clear GUI from previous calucations
    outputList->clear();

    string infoOutpout = "";

    for(int i = 1; i <= timeOfSimulationInMinutes; i++) {
        bool ventilationStatus = room.getControlPanel().getVentilationStatus();
        bool numberOfPeopleInside = room.getControlPanel().getNumberOfPeopleInside();

        //Recalcualte all conditions in the room
        room.recalculateInsideTemperature(tempConst, ventilationStatus, numberOfPeopleInside);
        room.recalculateInsideConcentrationCO2(co2Const1, co2Const2, ventilationStatus, numberOfPeopleInside);
        room.recalculateInsideHumidity(humConst1, ventilationStatus, numberOfPeopleInside);

        //Prepare data to be printed on GUI
        ostringstream oss;
        bool isThisLastIteration = (i == timeOfSimulationInMinutes);
        if(isThisLastIteration) oss << "---Wartości dla ostatniej iteracji symulacji---\n";
        oss << "Warunki wewnetrzne kina dla: " << i << " minuty symulacji: \n";
        oss << "    - temperatura: " << room.getTempInside().getConditionValue() << " " << room.getTempInside().getConditionUnit() << " \n";
        oss << "    - stezenie CO2: " << room.getCO2Inside().getConditionValue() << " " << room.getCO2Inside().getConditionUnit() << " \n";
        oss << "    - wilgotnosc: " << room.getHumInside().getConditionValue() << " " << room.getHumInside().getConditionUnit() << " \n";
        if(isThisLastIteration) {
            oss << "-----------------------------------------------\n";
            oss << " Obliczenia przeprowadzono dla sali kinowej o nazwie: " << room.getRoomName() << " \n";
        } else {
            oss << "\n\n";
        }
        infoOutpout += oss.str();
    }

    //Print output of calculation on GUI
    outputList->addItem(QString::fromStdString(infoOutpout));
    outputList->scrollToBottom();
}
