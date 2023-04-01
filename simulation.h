/** @file simulation.h
 *  @brief Interface and function prototypes for the simulation.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <QListWidget>

/**
 * @brief Simulation is used to group all condition calucations and perform them over prepared paramters.
 */
class Simulation{
    public:
        /**
         * @brief Simulation constructor which is responsible for setting up all values to correct class attributes.
         *
         * @param tIN is a double value of internal temperatoru inside the room.
         * @param cIN is a double value of internal CO2 copncentration inside the room.
         * @param hIN is a double value of internal humidity inside the room.
         * @param tOUT is a double value of external temperature outsidethe room.
         * @param cOUT is a double value of internal CO2 copncentration inside the room.
         * @param hOUT is a double value of external humidity outside the room.
         * @param ventStatus is boolean value which represents ON/OFF operating status of ventilation system.
         * @param peopleInside is a double value representing number of poeple inside the room for which calculation is being done.
         */
        Simulation(double tIN,
                   double cIN,
                   double hIN,
                   double tOUT,
                   double cOUT,
                   double hOUT,
                   bool ventOnOff,
                   double pplInside);

        /**
         * @brief recalculate conditions value which agregates all caluclations of single conditions in one place
         * and generates output of calulcation in form of text printed to QLiveWidghet object.
         *
         * @param timeOfSimulationInMinutes describes time
         * @param outputList
         */
        void recalculateConditions(int timeOfSimulationInMinutes, QListWidget *outputList);
    private:
        /**
         * Group of condition values which describes internal and external weather conditions.
         */
        double tempIN;
        double concCO2IN;
        double humiIN;
        double tempOUT;
        double concCO2OUT;
        double humiOUT;

        /**
         * Group of condition values which describes additional internal factors.
         */
        double peopleInside;
        bool ventStatus;

        /**
         * Group of constant values which describe temperature, humidity and co2 propagation.
         */
        double tempConst = 0.033;
        double humConst1 = 0.04;
        double co2Const1 = 0.0004;
        double co2Const2 = 0.00067;

};

#endif // SIMULATION_H
