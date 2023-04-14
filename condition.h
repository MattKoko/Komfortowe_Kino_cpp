/** @file condition.h
 *  @brief Interface and function prototypes for the conditions.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#ifndef CONDITION_H
#define CONDITION_H

#include <string>

/**
 * @brief Condition class used as base class for all other more detailed condition classes.
 */
class Condition {
    public:
        Condition(double value, std::string unit);

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
         * @brief set condition unit.
         * @param newValue is a value to be set as new value of condition.
         */
        void setConditionUnit(std::string newUnit);

        /**
         * @brief get condition unit.
         * @return unit of condtion.
         */
        std::string getConditionUnit();

        /**
         * @brief calculate value of condtion based on different input values of other internal and external weather conditions.
         */
        virtual void calcualteValue();;
    private:
        /**
         * value of condition.
         */
        double conditionValue;

        /**
         * value of condition.
         */
        std::string conditionUnit;
};

#endif // CONDITION_H
