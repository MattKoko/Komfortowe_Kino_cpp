#ifndef CONCENTRATIONCO2_H
#define CONCENTRATIONCO2_H

#include "condition.h"

class ConcentrationCO2 : public Condition {
    public:
        void calcualteValue(double tempIn, double concCO2In, double humIn, double co2Const1, double co2Const2, bool ventStatus, double peopleInside);
};

#endif // CONCENTRATIONCO2_H
