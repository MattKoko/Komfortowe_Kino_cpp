#include "simulation.h"
#include "temperature.h"
#include "humidity.h"
#include "concentrationco2.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
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

void Simulation::recalculateConditions(int timeOfSimulationInSeconds) {
    double newTemp = tempIN;
    double newConcCO2 = concCO2IN;
    double newHumi = humiIN;

    for(int i = 0; i < timeOfSimulationInSeconds; i++) {
        Temperature temp;
        temp.calcualteValue(newTemp, tempOUT, tempConst, ventStatus, peopleInside);
        newTemp = temp.getConditionValue();

        ConcentrationCO2 conc;
        conc.calcualteValue(newTemp, newConcCO2, newHumi, co2Const1, co2Const2, ventStatus, peopleInside);
        newConcCO2 = conc.getConditionValue();

        Humidity humi;
        humi.calcualteValue(newTemp, newHumi, tempOUT, humiOUT, humConst1, ventStatus, peopleInside);
        newHumi = humi.getConditionValue();

        cout << "Temperatura wewnetrzna: " << newTemp << " stopni Celsjusza" << endl;
        cout << "Stezenie CO2 wewnetrzne: " << newConcCO2 << " ppm" << endl;
        cout << "Wilgotnosc wewnetrzna: " << newHumi << " %" << endl;

        time_t now = time(0);
        char* currentTime = ctime(&now);
        cout << "--- Aktualny czas: " << currentTime << std::endl;

        this_thread::sleep_for(std::chrono::milliseconds(timeIterationInMiliseconds));
    }
}


