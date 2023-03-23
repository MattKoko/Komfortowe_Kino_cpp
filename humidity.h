#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "condition.h"

class Humidity : public Condition {
    public:
        void calcualteValue(double tempIn, double humIn, double humOut, double tempOut, double humConst1, bool ventStatus, double peopleInside);
};

#endif // HUMIDITY_H
