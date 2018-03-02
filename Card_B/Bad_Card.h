#ifndef BAD_CARD_H
#define BAD_CARD_H
#include <iostream>
#include "Card.h"
using namespace std;

class BadCard: public Card{//Class for bad cards
    public:
        //Constructors
        BadCard();
        BadCard(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        //Destructor
        ~BadCard();
        //Accessor
        string get_isbadcard();
        //Mutator
        void set_isbadcard();
        //Member Function
        void BOutput();
    private:
        //Member Variable
        string isbadcard_;
};

#endif // BAD_CARD_H