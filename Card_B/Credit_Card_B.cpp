/*
 * Name        : Credit_Card_B.cpp
 * Author      : Noah Pineda
 * Description :
 * Sources     :
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Card.h"
using namespace std;

stringstream ss;
//Transaction info string stream
stringstream Tss;
//Global Variables to be altered in Functions and main without losi8ng information due to scope
double balance;
string number, firstname, lastname, type, tmp = " ";
ifstream fin;
//Creates a vector of card objects
vector<Card> cards(7);
//Function declarations
void GetInfo();
void ClearVar();
void SetTransaction(string Tcard);

int main(){
    //Opens CardInfo File
    fin.open("CardInfo.txt");
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test(number, firstname, lastname, type, balance);
    ClearVar();
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test1(number, firstname, lastname, type, balance);
    ClearVar();
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test2(number, firstname, lastname, type, balance);
    ClearVar();
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test3(number, firstname, lastname, type, balance);
    ClearVar();
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test4(number, firstname, lastname, type, balance);
    ClearVar();
    //Creates a Card item with the information taken from the file
    GetInfo();
    Card test5(number, firstname, lastname, type, balance);
    ClearVar();
    //Invalid Card object
    Card error;
    //Closes CardInfo File
    fin.close();
    //Put the cards into the vector
    cards.at(0) = test;
    cards.at(1) = test1;
    cards.at(2) = test2;
    cards.at(3) = test3;
    cards.at(4) = test4;
    cards.at(5) = test5;
    cards.at(6) = error;
    //Opens TransactionInfo File
    fin.open("TransactionInfo.txt");
    //Strings to hold transaction card number adn transactions
    string Tcard;
    //Loop through the file to sort through all of the transactions
    while(!fin.eof()){
    getline(fin, Tcard, ':');
    SetTransaction(Tcard);
    }
    //Closes TransactionInfo file
    fin.close();
    cards.at(5).RunTrans();
    cout << cards.at(5).get_balance() << endl;
    return 0;
}

void GetInfo(){
    //Gets info from Card File and stores them in global variables
    for(int i = 0; i < 5; i++){
        //Gets Card number from file
        if(i == 0){
            fin >> tmp;
            ss << tmp;
            ss >> number;
            ss.clear();
            ss.str("");
        }
        //Gets first name from file
        else if(i == 1){
            fin >> tmp;
            ss << tmp;
            ss >> firstname;
            ss.clear();
            ss.str("");
        }
        //Gets last name from file
        else if(i == 2){
            fin >> tmp;
            ss << tmp;
            ss >> lastname;
            ss.clear();
            ss.str("");
        }
        //Gets type from file
        else if(i == 3){
            fin >> tmp;
            ss << tmp;
            ss >> type;
            ss.clear();
            ss.str("");
        }
        //Gets balance from file
        else if(i == 4){
            fin >> tmp;
            ss << tmp;
            ss >> balance;
            ss.clear();
            ss.str("");
        }
    }
}

void ClearVar(){
    //Clears Global Variables
    balance = 0;
    number = "";
    firstname = "";
    lastname = "";
    type = "";
    tmp = "";
}

void SetTransaction(string Tcard){
    //Compare Transaction card number to card object numbers to group transactions to cards
    string Tstring;
    if(cards.at(0).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(0).set_transactions(Tstring);
    }
    else if(cards.at(1).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(1).set_transactions(Tstring);
    }
    else if(cards.at(2).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(2).set_transactions(Tstring);
    }
    else if(cards.at(3).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(3).set_transactions(Tstring);
    }
    else if(cards.at(4).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(4).set_transactions(Tstring);
    }
    else if(cards.at(5).get_number() == Tcard){
        getline(fin, Tstring);
        cards.at(5).set_transactions(Tstring);
    }
    else{
        getline(fin, Tstring);
        cards.at(6).set_transactions(Tstring);
    }
        
}