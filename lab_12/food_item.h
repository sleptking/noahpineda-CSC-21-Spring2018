#ifndef FOODITEM_H
#define FOODITEM_H
#include <iostream>
#include "item.h"
using namespace std;

class FoodItem: public Item
{
    public:
        FoodItem(string FIname = "fooditem",unsigned int FIvalue = 0, unsigned int FIcalories = 0, string FIunit_of_measure = "nounits", double FIunits = 0);
        virtual ~FoodItem();
        unsigned int calories();
        string unit_of_measure();
        double units();
        void set_calories(unsigned int calories);
        void set_unit_of_measure(string unit_of_measure);
        void set_units(double units);
        string ToString();
    private:
        unsigned int calories_;//holds a calorie count
        string unit_of_measure_;//Holds type of unit measurement
        double units_;//Hold count of how many units we have
};

#endif // FOODITEM_H
