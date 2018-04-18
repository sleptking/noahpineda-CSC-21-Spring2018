#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include "Card.h"
using namespace std;
class Gold: public Card{//Class for gold cards
    public:
        //Constructors
        Gold();
        Gold(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        //Destructor
        ~Gold();
        //Member Functions
        void Rebate();
        void RunTrans();
};

#endif // GOLD_H