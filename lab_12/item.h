#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
    public:
        Item(string itemname = "item", unsigned int itemvalue = 0);
        virtual ~Item();
        unsigned int value();
        void set_value(unsigned int value);
        string name();
        void set_name(string name);
        string ToString();
    private:
        string name_;//holds the name of the item
        unsigned int value_;//Holds the value of the item
};

#endif // ITEM_H
