/*
 * Name        : Credit_Card_B.cpp
 * Author      : Noah Pineda
 * Description : Hold and modify account information and transaction information then output a monthkly statement.
 * Sources     :
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Card.h"
#include "Gold.h"
#include "Platinum.h"
#include "Corporate.h"
using namespace std;


//Function declarations
string GetNumber();
string GetFirstname();
string GetLastname();
string GetType();
int GetBalance();

int main(){
    ifstream fin;
    double balance;
    string number, firstname, lastname, type;
    //Creates a vector of card objects
    vector<Gold> gold(3);
    //Creates a vector of card objects
    vector<Platinum> platinum(1);
    //Creates a vector of card objects
    vector<Corporate> corporate(2);
    //Opens CardInfo File
    fin.open("CardInfo.txt");
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Gold test(number, firstname, lastname, type, balance);
    gold.at(0) = test;
    cout << type << "\n";
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Gold test1(number, firstname, lastname, type, balance);
    gold.at(1) = test1;
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Gold test2(number, firstname, lastname, type, balance);
    gold.at(2) = test2;
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Platinum test3(number, firstname, lastname, type, balance);
    platinum.at(0) = test3;
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Corporate test4(number, firstname, lastname, type, balance);
    corporate.at(0) = test4;
    //Creates a Card item with the information taken from the file
    number = GetNumber();
    firstname = GetFirstname();
    lastname = GetLastname();
    type = GetType();
    balance = GetBalance();
    Corporate test5(number, firstname, lastname, type, balance);
    corporate.at(1) = test5;
    //Closes CardInfo File
    fin.close();
    //Set Transactions to card objects
    gold.at(0).SetTrans();
    gold.at(1).SetTrans();
    gold.at(2).SetTrans();
    platinum.at(0).SetTrans();
    corporate.at(0).SetTrans();
    corporate.at(1).SetTrans();
    //Run Transactions through each card
    gold.at(0).RunTrans();
    gold.at(1).RunTrans();
    gold.at(2).RunTrans();
    platinum.at(0).RunTrans();
    corporate.at(0).RunTrans();
    corporate.at(1).RunTrans();
    //Apply the rebate to each card
    gold.at(0).Rebate();
    gold.at(1).Rebate();
    gold.at(2).Rebate();
    platinum.at(0).Rebate();
    corporate.at(0).Rebate();
    corporate.at(1).Rebate();
    //Output Account summary for each card
    gold.at(0).Output();
    gold.at(1).Output();
    gold.at(2).Output();
    platinum.at(0).Output();
    corporate.at(0).Output();
    corporate.at(1).Output();
    return 0;
}

string GetNumber(){
    //Gets info from Card File and stores in number
    ifstream fin;
    string number;
    fin >> number;
    return number;
}

string GetFirstname(){
    //Gets first name from file and stores in firstname
    ifstream fin;
    string firstname;
    fin >> firstname;
    return firstname;
}

string GetLastname(){
    //Gets last name from file and stores in lastname
    ifstream fin;
    string lastname;
    fin >> lastname;
    return lastname;
}

string GetType(){
    //Gets type from file and stores in type
    ifstream fin;
    string type;
    fin >> type;
    return type;
}

int GetBalance(){
    //Gets balance from file and stores in balance
    stringstream ss;
    ifstream fin;
    int balance = 0, tmp = 0;
    fin >> tmp;
    ss << tmp;
    ss >> balance;
    ss.clear();
    ss.str("");
    return balance;    
}