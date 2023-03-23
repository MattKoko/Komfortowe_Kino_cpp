#ifndef CONDITION_H
#define CONDITION_H

class Condition {
    public:
        void setConditionValue(double newValue);
        double getConditionValue();
        virtual void setConditionValue() {};
        virtual void calcualteValue() {};
    private:
        double value;
};

#endif // CONDITION_H
