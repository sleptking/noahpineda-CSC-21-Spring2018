#include "item.h"
#include <sstream>
Item::Item(string itemname, unsigned int itemvalue)
{
    set_name(itemname);
    set_value(itemvalue);
}

Item::~Item()
{
    //dtor
}

unsigned int Item::value(){
    return value_;
}

void Item::set_value(unsigned int value){
    value_ = value;
}

string Item::name(){
    return name_;
}

void Item::set_name(string name){
    name_ = name;
}

string Item::ToString(){
    stringstream TSss;
    string TS, tmp, tmp2;
    TSss << name() << ", $" << value();
    TSss >> tmp;
    TSss >> tmp2;
    TS = tmp + " " + tmp2;
    return TS;
}
