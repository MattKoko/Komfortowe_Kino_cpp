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

Simulation::Simulation(double tIN,
                       double cIN,
                       double hIN,
                       double tOUT,
                       double cOUT,
                       double hOUT,
                       bool ventOnOff,\
                       double pplInside) {
    tempIN = tIN;
    concCO2IN = cIN;
    humiIN = hIN;
    tempOUT = tOUT;
    concCO2OUT = cOUT;
    humiOUT = hOUT;
    ventStatus = ventOnOff;
    peopleInside = pplInside;
}

void Simulation::recalculateConditions(int timeOfSimulationInSeconds, QListWidget* outputList) {
    double newTemp = tempIN;
    double newConcCO2 = concCO2IN;
    double newHumi = humiIN;

    outputList->clear();

    string infoOutpout = "";

    for(int i = 1; i <= timeOfSimulationInSeconds; i++) {
        Temperature temp;
        temp.calcualteValue(newTemp, tempOUT, tempConst, ventStatus, peopleInside);
        newTemp = temp.getConditionValue();

        ConcentrationCO2 conc;
        conc.calcualteValue(newTemp, newConcCO2, newHumi, co2Const1, co2Const2, ventStatus, peopleInside);
        newConcCO2 = conc.getConditionValue();

        Humidity humi;
        humi.calcualteValue(newTemp, newHumi, tempOUT, humiOUT, humConst1, ventStatus, peopleInside);
        newHumi = humi.getConditionValue();

        ostringstream oss;
        bool isThisLastIteration = i == timeOfSimulationInSeconds;
        if(isThisLastIteration) oss << "---Wartości dla ostatniej iteracji symulacji---\n";
        oss << "Warunki wewnetrzne kina dla: " << i << " minuty symulacji: \n";
        oss << "    - temperatura: " << newTemp << " C \n";
        oss << "    - stezenie CO2: " << newConcCO2 << " ppm \n";
        oss << "    - wilgotnosc: " << newHumi << " % \n";
        if(isThisLastIteration) {
            oss << "-----------------------------------------------\n";
        } else {
            oss << "\n\n";
        }
        infoOutpout += oss.str();

    }

    outputList->addItem(QString::fromStdString(infoOutpout));
    outputList->scrollToBottom();
}


