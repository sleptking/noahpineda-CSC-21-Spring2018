#include "Card.h"

Card::Card(){
    set_number("0");
    set_firstname("none");
    set_lastname("none");
    set_type("none"); 
    set_balance(0);
}

Card::Card(string Cnumber, string Cfirstname, string Clastname, string Ctype, double Cbalance){
    set_number(Cnumber);
    set_firstname(Cfirstname);
    set_lastname(Clastname);
    set_type(Ctype);
    set_balance(Cbalance);
}

Card::~Card(){
    
}
//Accessors
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

string Card::get_number(){
    return number_;
}

bool Card::get_valid(){
    return valid_;
}

double Card::get_total(){
    return total_;
}

string Card::get_transactions(){
    return transactions_;
}
//Mutators
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

void Card::set_number(string number){
    number_ = number;
}

void Card::set_valid(bool valid){
    valid_ = valid;
}

void Card::set_total(double total){
    total_ = total;
}

void Card::set_transactions(string TSstring){
    transactions_ = transactions_ + number_ + ":" + TSstring + '\n';
}

void set_badtrans(string badtrans, string reason){
    errtrans_ = errtrans_ + badtrans + " " + reason + '\n';
}
//Functions
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
    ss << card.at(card.length() - 1);
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

void Card::Rebate(){
    //Adds the rebate to the balance
    double addrebate;
    if(type_ == "gold"){
        addrebate = (total_ * .01);
    }
    else if(type_ == "corporate"){
        addrebate = (total_ * .03);
    }
    else if(type_ == "platinum"){
        addrebate = (total_ * .05);
    }
    set_total(total_ + addrebate);
 }
 
void Card::Output(){
    cout << number_ << " " << type_ << " " << firstname_ << " " << lastname_ << " " << balance_ << endl;
}

void Card::RunTrans(){
    //Declare Variables
    stringstream ss, TMPss;
    string tmp, tmp1, tmptrans;
    int cost = 0;
    //Count new line characters to determin iterations
    int count = 0;
    for(int i = 0;i < transactions_.size();i++){
        char c = '\n';
        if(transactions_.at(i) == c){
            count++;
        }
    }
    int itcount = 0;
    //Loop through transactions and apply them to each card
    while(count != itcount){
        //Store current transaction for later
        TMPss << transactions_;
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
        //Determine if the transaction will go through and apply the cost to the balance
        if(type_ == "Gold"){
            if((balance_ - cost) >= 0){
                balance_ = balance_ - cost;
            }
            else{
            string tmpreason;
            tmpreason = "Insufficient Funds\n";
            set_badtrans(tmptrans, tmpreason);
            }
        }
        else if(type_ == "Platinum"){
            if((balance_ - cost) >= -1000){
                balance_ = balance_ - cost;
            }
            else{
            string tmpreason;
            tmpreason = "Insufficient Funds\n";
            set_badtrans(tmptrans, tmpreason);
            }    
        }
        else if(type_ == "Corporate"){
            if((balance_ - cost) >= -5000){
                balance_ = balance_ - cost;
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