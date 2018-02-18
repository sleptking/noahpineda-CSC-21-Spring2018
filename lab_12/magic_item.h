#ifndef MAGICITEM_H
#define MAGICITEM_H
#include "item.h"
#include <iostream>
using namespace std;

class MagicItem: public Item
{
    public:
        MagicItem(string MIname = "magicitem", unsigned int MIvalue = 0, string MIdescription = "no description", unsigned int MImana_required = 0);
        virtual ~MagicItem();
        string description();
        unsigned int mana_required();
        void set_description(string description);
        void set_mana_required(unsigned int mana_required);
        string ToString();
    private:
        string description_;//Holds a description of the magic item
        unsigned int mana_required_;//Holds the amount of mana required to use the magic item
};

#endif // MAGICITEM_H
