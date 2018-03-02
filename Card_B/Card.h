#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Card{//Class to hold and modify card and account information
    public:
        //Constructors
        Card();
        Card(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        //Destructor
        virtual ~Card();
        //Accessors
        string get_type();
        double get_balance();
        string get_overdrawn();
        string get_firstname();
        string get_lastname();
        string get_number();
        bool get_valid();
        double get_total();
        string get_transactions();
        string get_badtrans();
        double get_rebate();
        //Mutators
        void set_type(string type);
        void set_balance(double balance);
        void set_overdrawn(bool overdrawn);
        void set_firstname(string firstname);
        void set_lastname(string lastname);
        void set_number(string number);
        void set_valid(bool valid);
        void set_total(double total);
        void set_transactions(string TSstring);
        void set_badtrans(string badtrans, string reason);
        void set_rebate(double rebate);
        //Member Functions
        void CardType(string card);
        bool LuhnCheck(string card);
        void Rebate();
        void Output();
        void RunTrans();
    private:
        //Member Variables
        string type_;
        double balance_;
        bool overdrawn_;
        string firstname_;
        string lastname_;
        string number_;
        bool valid_;
        double total_;
        string transactions_;
        string badtrans_;
        double rebate_;
};

#endif