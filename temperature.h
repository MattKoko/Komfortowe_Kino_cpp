/** @file temperature.h
 *  @brief Interface and function prototypes for the temperature.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "condition.h"

/**
 * @brief Temperature is a subclass to Condition class.
 * It is used to perform calculation of temperature value based on different internal and external condition variables.
 */
class Temperature : public Condition {
    public:
        /**
         * @brief calculate temperature condition value inside the room.
         * Calculation done based on simplified sorption model of temperature propagation.
         *
         * @param tempIn is a double value of internal temperatoru inside the room.
         * @param tempOut is a double value of external temperature outsidethe room.
         * @param tempConst is a constant value which describes temperature propagation.
         * @param ventStatus is boolean value which represents ON/OFF operating status of ventilation system.
         * @param peopleInside is a double value representing number of poeple inside the room for which calculation is being done.
         */
        void calcualteValue(double tempIn, double tempOut, double tempConst, bool ventStatus, double peopleInside);
};

#endif // TEMPERATURE_H
