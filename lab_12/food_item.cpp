#include "food_item.h"
#include "item.h"
#include <sstream>
#include <iomanip>
FoodItem::FoodItem(string FIname,unsigned int FIvalue, unsigned int FIcalories, string FIunit_of_measure, double FIunits)
{
    set_calories(FIcalories);
    set_unit_of_measure(FIunit_of_measure);
    set_units(FIunits);
    set_name(FIname);
    set_value(FIvalue);
}

FoodItem::~FoodItem()
{
    //dtor
}

unsigned int FoodItem::calories(){
    return calories_;
}

string FoodItem::unit_of_measure(){
    return unit_of_measure_;
}

double FoodItem::units(){
    return units_;
}

void FoodItem::set_calories(unsigned int calories){
    calories_ = calories;
}

void FoodItem::set_unit_of_measure(string unit_of_measure){
    unit_of_measure_ = unit_of_measure;
}

void FoodItem::set_units(double units){
    units_ = units;
}

string FoodItem::ToString(){
    stringstream TSss;
    string TS, tmp, tmp2, tmp3, tmp4, tmp5, tmp6;
    TSss << setprecision(2) << fixed; 
    TSss << name() << ", $" << value() << ", " << units() << " " << unit_of_measure() << ", " << calories() << " calories"  ;
    TSss >> tmp >> tmp2 >> tmp3 >> tmp4 >> tmp5 >> tmp6;
    TS = tmp + " " + tmp2 + " " + tmp3 + " " + tmp4 + " " + tmp5 + " " + tmp6;
    return TS;
}
