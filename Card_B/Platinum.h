#ifndef PLATINUM_H
#define PLATINUM_H
#include <iostream>
#include "Card.h"
using namespace std;
class Platinum: public Card{//Class for platinum cards
    public:
        //Constructors
        Platinum();
        Platinum(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        //Destructor
        ~Platinum();
        //Member Functions
        void Rebate();
        void RunTrans();
};

#endif // PLATINUM_H