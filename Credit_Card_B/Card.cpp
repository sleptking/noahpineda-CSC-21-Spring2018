#include "Card.h"

Card::Card(int Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance){
    set_number(Cnumber);
    set_firstname(Cfirstname);
    set_lastname(Clastname);
    set_type(Ctype);
    set_balance(Cbalance);
}

virtual Card::~Card(){
    
}

string Card::get_type(){
    return type_;
}

double Card::get_balance(){
    return balance_;
}

bool Card::get_overdrawn(){
    return overdrawn_;
}

string Card::get_firstname(){
    return firstname_;
}

string Card::get_lastname(){
    return lastname_;
}

int Card::get_number(){
    return number_;
}

bool Card::get_valid(){
    return valid_;
}

double Card::get_total(){
    return total_;
}

void Card::set_type(string type){
    type_ = type;
}

void Card::set_balance(double balance){
    balance_ = balance;
}

void Card::set_overdrawn(bool overdrawn){
    overdrawn_ = overdrawn;
}

void Card::set_firstname(string firstname){
    firstname_ = firstname;
}

void Card::set_lastname(string lastname){
    lastname_ = lastname;
}

void Card::set_number(int number){
    number_ = number;
}

void Card::set_valid(bool valid){
    valid_ = valid;
}

void Card::set_total(double total){
    total_ = total;
}

void Card::CardType(string card){
   //Function reads each credit card number and determines which card it is based on the BIN. If card isn't on the list outputs "Unknown Card Type"
   stringstream ss;
   int prefix;
   string type("Unknown Card Type");
   ss.clear();
   ss.str("");
   ss << card.at(0) << card.at(1);
   ss >> prefix;
   //Compares the card number to the lengths and prefixes determined in the BIN.
        if(card.length() == 15 && (prefix == 34 || prefix == 37)){
                type = "Gold";
        }
        else if(card.length() == 16){
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3) << card.at(4) << card.at(5);
            ss.clear();
            ss.str("");
            ss >> prefix;
            if(622126 <= prefix && prefix <= 622925){
               type = "Corporate";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3);
            ss >> prefix;
            if(prefix == 6011){
               type = "Corporate";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1) << card.at(2);
            ss >> prefix;
            if(644 <= prefix && prefix <= 649){
               type = "Corporate";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(prefix == 65){
               type = "Corporate";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(51 <= prefix && prefix <= 55){
               type = "Platinum";
            }
         }
   //Sets the card type
    set_type(type);
}

void Card::LuhnCheck(string card){
    //Function recieves a card number then checks if the card is valid using the Luhn Algorithm
   stringstream luhnss;
   stringstream ss;
   //Flips the card number into a strinstream
   for(int i = 1;i < card.length();i++){
         if(i > 0)
         luhnss << card.at((card.length() - 1) - i) << " ";
         else
         luhnss << card.at((card.length() - 1) - i);
   }
   //Runs card number through Luhn Algorithm
   int temp;
   int other(1), dub(0), sum(0);
   for(int i = 1;i < card.length();i++){
        luhnss >> temp;
        if(other == 1){
            dub = temp * 2;
            if(dub <= 9 && dub >= 0)
                sum = sum + dub;
            else
                sum = sum + (dub - 9);
            other = 2;
            }
        else{
            sum = sum + temp;
            other = 1;
        }
      
   }
   //Compares the check number from Luhn Algorithm to the check number from the card
   bool valid;
   ss << card.back();
   int back;
   int checkdigit;
   ss >> back;
   checkdigit = ((sum * 9)%10);
   if(checkdigit == back)
      valid = true;
   else
      valid = false;
   //Returns true for valid cards and false for invalid cards
   set_valid(valid);
}

void Card::Rebate(double balance){
     
 }