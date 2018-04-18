#include "Corporate.h"

Corporate::Corporate(){//Default Constructor
    set_number("0");
    set_firstname("none");
    set_lastname("none");
    set_type("none"); 
    set_balance(0);
    set_total(0);
    set_overdrawn(false);
}

Corporate::Corporate(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance){//Overloaded Constructor
    set_number(Cnumber);
    set_firstname(Cfirstname);
    set_lastname(Clastname);
    set_type(Ctype);
    set_balance(Cbalance);
    set_total(0);
    set_overdrawn(false);
}

Corporate::~Corporate(){//Destructor
    
}
//Member Functions
void Corporate::Rebate(){
    double addrebate = 0;
    addrebate = (get_total() * .05);
    set_total(get_total() + addrebate);
    set_rebate(addrebate);
}

void Corporate::RunTrans(){
    //Declare Variables
    stringstream ss, TMPss;
    string tmp, tmp1, tmptrans;
    int cost = 0;
    //Count new line characters to determin iterations
    int count = 0;
    for(int i = 0;i < get_transactions().size();i++){
        char c = '\n';
        if(get_transactions().at(i) == c){
            count++;
        }
    }
    int itcount = 0;
    //Loop through transactions and apply them to each card
    while(count != itcount){
        //Store current transaction for later
        TMPss << get_transactions();
        getline(TMPss, tmptrans, '\n');
        TMPss.clear();
        TMPss.str("");
        //Get cost from transaction
        TMPss << tmptrans;
        getline(TMPss, tmp, ':');
        getline(TMPss, tmp1, ':');
        TMPss.clear();
        TMPss.str("");
        //store cost as int
        ss << tmp1;
        ss >> cost;
        //Determine if the transaction will go through and apply the cost to the balance.
        //If there are not enough funds in the account, send to bad trans and set reason to insufficient funds.
        if(get_type() == "Corporate"){
            if((get_balance() - cost) >= -5000){
                set_balance(get_balance() - cost);
                set_total(get_total() + cost);
                if(get_balance() < 0){
                    set_overdrawn(true);
                }
            }
            else{
            string tmpreason;
            tmpreason = "Insufficient Funds\n";
            set_badtrans(tmptrans, tmpreason);
            }
        }
        itcount++;
        ss.clear();
        ss.str("");
    }
}