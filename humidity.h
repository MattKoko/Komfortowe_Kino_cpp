/** @file humidity.h
 *  @brief Interface and function prototypes for the humidity.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "condition.h"

/**
 * @brief Humidity is a subclass to Condition class.
 * It is used to perform calculation of humidity value based on different internal and external condition variables.
 */
class Humidity : public Condition {
    public:
        /**
         * @brief calculate humidity condition value inside the room.
         * Calculation done based on simplified sorption model of humidity propagation.
         *
         * @param tempIn is a double value of internal temperatoru inside the room.
         * @param humIn is a double value of internal humidity inside the room.
         * @param humOut is a double value of external humidity outside the room.
         * @param tempOut is a double value of external temperature outsidethe room.
         * @param humConst1 is a constant value which describes humidity propagation.
         * @param ventStatus is boolean value which represents ON/OFF operating status of ventilation system.
         * @param peopleInside is a double value representing number of poeple inside the room for which calculation is being done.
         */
        void calcualteValue(double tempIn, double humIn, double humOut, double tempOut, double humConst1, bool ventStatus, double peopleInside);
};

#endif // HUMIDITY_H
