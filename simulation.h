#ifndef SIMULATION_H
#define SIMULATION_H

#include <QListWidget>

class Simulation{
    public:
        Simulation(double tIN,
                   double cIN,
                   double hIN,
                   double tOUT,
                   double cOUT,
                   double hOUT,
                   bool ventOnOff,
                   double pplInside);
        void recalculateConditions(int timeOfSimulationInSeconds, QListWidget *outputList);
    private:
        double tempIN;
        double concCO2IN;
        double humiIN;
        double tempOUT;
        double concCO2OUT;
        double humiOUT;
        bool ventStatus;
        double peopleInside;
        double tempConst = 0.033;
        double humConst1 = 0.04;
        double co2Const1 = 0.0004;
        double co2Const2 = 0.00067;

};

#endif // SIMULATION_H
