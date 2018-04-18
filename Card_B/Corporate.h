#ifndef CORPORATE_H
#define CORPORATE_H
#include <iostream>
#include "Card.h"
using namespace std;
class Corporate: public Card{//Class for corporate cards
    public:
         //Constructors
        Corporate();
        Corporate(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        //Destructor
        ~Corporate();
        //Member Functions
        void Rebate();
        void RunTrans();
};

#endif // CORPORATE_H