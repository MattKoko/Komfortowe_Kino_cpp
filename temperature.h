#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "condition.h"

class Temperature : public Condition {
    public:
    void calcualteValue(double tempIn, double tempOut, double tempConst, bool ventStatus, double peopleInside);
};

#endif // TEMPERATURE_H
