/** @file concentrationco2.h
 *  @brief Interface and function prototypes for the concentrationCO2.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef CONCENTRATIONCO2_H
#define CONCENTRATIONCO2_H

#include "condition.h"

/**
 * @brief ConcentrationCO2 is a subclass to Condition class.
 * It is used to perform calculation of CO2 contentration value based on different internal and external condition variables.
 */
class ConcentrationCO2 : public Condition {
    public:
        /**
         * @brief calculate CO2 concentration condition value inside the room.
         * Calculation done based on simplified chemical mechanism of CO2 propagation.
         *
         * @param tempIn is a double value of internal temperatoru inside the room.
         * @param concCO2In is a double value of internal CO2 copncentration inside the room.
         * @param humIn is a double value of internal humidity inside the room.
         * @param co2Const1 is a first constant value which describes CO2 propagation.
         * @param co2Const2 is a second constant value which describes CO2 propagation.
         * @param ventStatus is boolean value which represents ON/OFF operating status of ventilation system.
         * @param peopleInside is a double value representing number of poeple inside the room for which calculation is being done.
         */
        void calcualteValue(double tempIn, double concCO2In, double humIn, double co2Const1, double co2Const2, bool ventStatus, double peopleInside);
};

#endif // CONCENTRATIONCO2_H
