#include "magic_item.h"
#include "item.h"
#include <sstream>
MagicItem::MagicItem(string MIname, unsigned int MIvalue, string MIdescription, unsigned int MImana_required)
{
    set_description(MIdescription);
    set_mana_required(MImana_required);
    set_name(MIname);
    set_value(MIvalue);
}

MagicItem::~MagicItem()
{
    //dtor
}

string MagicItem::description(){
    return description_;
}

unsigned int MagicItem::mana_required(){
    return mana_required_;
}

void MagicItem::set_description(string description){
    description_ = description;
}

void MagicItem::set_mana_required(unsigned int mana_required){
    mana_required_ = mana_required;
}

string MagicItem::ToString(){
    stringstream TSss;
    string TS, tmp, tmp2, tmp3, tmp4, tmp5, tmp6;
    tmp3 = description();
    TSss << name() << ", $" << value() << ", " << "requires " << mana_required() << " mana";
    TSss >> tmp >> tmp2>> tmp4 >> tmp5 >> tmp6;
    TS = tmp + " " + tmp2 + " " + tmp3 + ", " + tmp4 + " " + tmp5 + " " + tmp6;
    return TS;
}
