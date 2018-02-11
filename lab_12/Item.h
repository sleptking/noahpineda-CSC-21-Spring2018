#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        Item(string itemname(item), unsigned int itemvalue(0));
        virtual ~Item();
        string name;
        unsigned int value;
        string ToString(name_, $value_);
    private:
        string name_;//holds the name of the item
        unsigned int value_;//Holds the value of the item
};

#endif // ITEM_H
