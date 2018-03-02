#include "Bad_Card.h"
#include "Card.h"
BadCard::BadCard(){//Default Constructor
    set_number("0");
    set_firstname("none");
    set_lastname("none");
    set_type("none"); 
    set_balance(0);
    set_total(0);
    set_overdrawn(false);
    set_isbadcard();
}

BadCard::BadCard(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance){//Overloaded Constructor
    set_number(Cnumber);
    set_firstname(Cfirstname);
    set_lastname(Clastname);
    set_type(Ctype);
    set_balance(Cbalance);
    set_total(0);
    set_overdrawn(false);
    set_isbadcard();
}

BadCard::~BadCard(){//Destructor
    
}
//Mutator
void BadCard::set_isbadcard(){
    //Just someting to let you know that I know how to use inheritance even though I found it easier to do without
    set_type("Bad");
    isbadcard_ = "Grrr I'm a Bad Card";
}
//Accessor
string BadCard::get_isbadcard(){
    return isbadcard_;
}
//Member Function
void BadCard::BOutput(){
    cout << get_isbadcard() << endl;
}