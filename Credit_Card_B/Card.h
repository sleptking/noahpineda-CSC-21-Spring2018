#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Card{
    public:
        Card();
        Card(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance);
        virtual ~Card();
        string get_type();
        double get_balance();
        bool get_overdrawn();
        string get_firstname();
        string get_lastname();
        string get_number();
        bool get_valid();
        double get_total();
        //string get_transactions();
        void set_type(string type);
        void set_balance(double balance);
        void set_overdrawn(bool overdrawn);
        void set_firstname(string firstname);
        void set_lastname(string lastname);
        void set_number(string number);
        void set_valid(bool valid);
        void set_total(double total);
        //void set_transactions(string TSstring);
        void CardType(string card);
        void LuhnCheck(string card);
        void Rebate(double balance);
        void Output();
    private:
        string type_;
        double balance_;
        bool overdrawn_;
        string firstname_;
        string lastname_;
        string number_;
        bool valid_;
        double total_;
        //string transactions_;
};

#endif