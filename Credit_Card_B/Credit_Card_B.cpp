/*
 * Name        : Credit_Card_B.cpp
 * Author      : Noah Pineda
 * Description : 
 * Sources     : 
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Card.h"
using namespace std;

int main(){
    ifstream fin;
    fin.open("CardInfo.txt");
    stringstream ss;
    int number;
    double balance;
    string firstname, lastname, type, tmp = " ";
    for(int i = 0; i < 5; i++){
        if(i == 0){
            getline(fin,tmp);
            ss << tmp;
            ss >> number; 
        }
        else if(i == 1){
            getline(fin,tmp);
            ss << tmp;
            ss >> firstname; 
        }
        else if(i == 2){
            getline(fin,tmp);
            ss << tmp;
            ss >> lastname; 
        }
        else if(i == 3){
            getline(fin,tmp);
            ss << tmp;
            ss >> type; 
        }
        else if(i == 4){
            getline(fin,tmp);
            ss << tmp;
            ss >> balance; 
        }
    }
    cout << ss.str();
    fin.close();
}

