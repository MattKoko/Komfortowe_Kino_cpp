/** @file condition.h
 *  @brief Interface and function prototypes for the conditions.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef CONDITION_H
#define CONDITION_H

/**
 * @brief Condition class used as base class for all other more detailed condition classes.
 */
class Condition {
    public:
        /**
         * @brief set condition value.
         * @param newValue is a value to be set as new value of condition.
         */
        void setConditionValue(double newValue);

        /**
         * @brief get condition value.
         * @return value of condtion.
         */
        double getConditionValue();

        /**
         * @brief calculate value of condtion based on different input values of other internal and external weather conditions.
         */
        virtual void calcualteValue();;
    private:
        /**
         * value of condition.
         */
        double value;
};

#endif // CONDITION_H
