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
   return 0;
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
   //Read each credit card number and determine which card it is based on the BIN. If card isn't on the list output "Unknown Card Type"
   card = "378282246310005";
   string type("none");
   while(type == "none"){
      if(card.length() == 15 && card.at(0) == 3){
         if(card.at(1) == 4 || card.at(1) == 7){
                type = "American Express";
         }
      }
         else if(card.length() == 16){
            stringstream ss;
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3) << card.at(4) << card.at(5);
            int prefix;
            ss >> prefix;
            if(622126 <= prefix && prefix <= 622925){
               type = "Master Card";
            }
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3);
            ss >> prefix;
            if(prefix == 6011){
               type = "Master Card";
            }
            ss << card.at(0) << card.at(1) << card.at(2);
            ss >> prefix;
            if(644 <= prefix && prefix <= 649){
               type = "Master Card";
            }
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(prefix == 65){
               type = "Master Card";
            }
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(51 <= prefix && prefix <= 55){
               type = "Discover";
            }
            else if(card.at(0) == 4){
               type = "VISA";
            }
         }
         else if(13 <= card.length() && card.length() <= 16 && card.at(0) == 4){
            type = "VISA";
         }
         else
            type = "Unknown Card Type";
    }
   return type;
}

bool LuhnCheck(){

}
