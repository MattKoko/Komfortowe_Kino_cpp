/** @file simulation.h
 *  @brief Interface and function prototypes for the simulation.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <QListWidget>
#include "room.h"

/**
 * @brief Simulation is used to group all condition calucations and perform them over prepared paramters.
 */
class Simulation{
    public:
        Simulation();

        /**
         * @brief recalculate conditions value which agregates all caluclations of single conditions in one place
         * and generates output of calulcation in form of text printed to QLiveWidghet object.
         *
         * @param room represents room of cinema for which all calulcation will be done
         * @param timeOfSimulationInMinutes descirbes for how many minutes execution will take place
         * @param outputList UI object which is used to generate output of method execution
         */
        void recalculateConditions(Room room, int timeOfSimulationInMinutes, QListWidget *outputList);
    private:
        /**
         * Group of constant values which describe temperature, humidity and co2 propagation.
         * I have tried to convert them to enum class but because of problems with version of C++, i was unable to create enum class with double values as it works only in C++ 11
         */
        double tempConst = 0.033;
        double humConst1 = 0.04;
        double co2Const1 = 0.0004;
        double co2Const2 = 0.00067;

};

#endif // SIMULATION_H
