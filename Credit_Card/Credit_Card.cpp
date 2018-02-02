/*
 * Name        : Credit Card.cpp
 * Author      : Noah Pineda
 * Description : Recieve credit card numbers from a file and compare them to a BIN file to determine credit card type.
 * Sources     : Need to sort through my sources
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int Count();
string CardNumber(int linenumber);
string CardType(string card);
bool LuhnCheck();

int main()
{
   int count = Count();
   //Looping each card number individually through the BIN check
   for(int i = 1; i <= count; i++){
   string number;
   number = CardNumber(i);
   string type;
   type = CardType(number);
   cout << "type: " << type << " " << "number:" << number << endl;
   }
}

int Count(){
   ifstream fin;
   int count;
   //Open Cards file
   fin.open("Cards.txt");
   //Get Input from the credit card file and store it.
   string line("");
   while(!fin.eof()){
      getline(fin,line);
      count++;
   }
   fin.close();
   return count;
}

string CardNumber(int linenumber){
   ifstream fin;
   string checknumber;
   //Open Cards file
   fin.open("Cards.txt");
   //Get Input from the credit card file and store it.
   string line("");
   for(int i = 0; i < linenumber; i++){
      getline(fin,line);
      if(i == (linenumber - 1)){
        checknumber = line;
      }
   }
   fin.close();

   return checknumber;
}

string CardType(string card){
   //Read each credit card number and determine which card it is based on the BIN. If card isnt on the list output "Unknown Card Type"
   stringstream cardlength;
   stringstream cardprefix;
   stringstream binprefix;
   ifstream fin;
   string type = "none";
   int test;
   card = "341234567891234";
   //Open BIN file
   fin.open("BIN.txt");
   string line;
   while(type == "none"){
        getline(fin,line);
        cardlength << line.at(8) << line.at(9);
        binlength = cardlength.str();
        if(card.length() == binlength){
            if(card.at(0) == line.at(0) && card.at(1) == line.at(1)){
                type = "American Express";
            }
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "American Express";
            }
         }
         getline(fin,line);
         ss.str("");
         ss << line.at(36) << line.at(37);
         binlength = ss.str();
         cout << binlength;
         cin >> test;
         else if(card.length() == binlength){
            if(card.at(0) == line.at(0) && card.at(1) == line.at(1)){
                type = "Discover";
            }
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "Discover";
            }
            getline(fin,line);
            
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "Master Card";
            }
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "Master Card";
            }
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "VISA";
            }
         }
         getline(fin,line);
         ss.str("");
         ss << line.at(36) << line.at(37);
         else if(){   
            else if(card.at(4) == line.at(4) && card.at(5) == line.at(5)){
                type = "VISA";
            }
            
         }   
         
    }
   return type;
}

string LuhnCheck{
   
}