#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Card{
    public:
        Card(int Cnumber = 0, string Cfirstname = "none", string Clastname = "none", string Ctype = "none", double Cbalance = 0);
        virtual ~Card();
        string get_type();
        double get_balance();
        bool get_overdrawn();
        string get_firstname();
        string get_lastname();
        int get_number();
        bool get_valid();
        double get_total();
        void set_type(string type);
        void set_balance(double balance);
        void set_overdrawn(bool overdrawn);
        void set_firstname(string firstname);
        void set_lastname(string lastname);
        void set_number(int number);
        void set_valid(bool valid);
        void set_total(double total);
        void CardType(string card);
        void LuhnCheck(string card);
        void Rebate(double balance);
    private:
        string type_;
        double balance_;
        bool overdrawn_ = false;
        string firstname_;
        string lastname_;
        int number_;
        bool valid_;
        double total_;
};

#endif