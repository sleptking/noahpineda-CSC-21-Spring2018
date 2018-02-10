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
bool LuhnCheck(string card);

int main()
{
   int count = Count();
   //Looping each card number individually through the BIN and Luhn Algorithm check to determine the validity of the card and the type
   for(int i = 1; i <= count; i++){
      string number;
      number = CardNumber(i);
      bool valid = false;
      valid = LuhnCheck(number);
      if(valid == true){
         string type;
         type = CardType(number);
         cout << "Type: " << type << " || " << "Number: " << number << endl;
         }
      else{
         cout << "Invalid Card" << endl;
      }
   }
   return 0;
}

int Count(){
   //Funcion counts number of lines in the file
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
   //Function pulls a card number from the file
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
                type = "American Express";
        }
        else if(card.length() == 16){
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3) << card.at(4) << card.at(5);
            ss.clear();
            ss.str("");
            ss >> prefix;
            if(622126 <= prefix && prefix <= 622925){
               type = "Discover";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1) << card.at(2) << card.at(3);
            ss >> prefix;
            if(prefix == 6011){
               type = "Discover";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1) << card.at(2);
            ss >> prefix;
            if(644 <= prefix && prefix <= 649){
               type = "Discover";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(prefix == 65){
               type = "Discover";
            }
            ss.clear();
            ss.str("");
            ss << card.at(0) << card.at(1);
            ss >> prefix;
            if(51 <= prefix && prefix <= 55){
               type = "MasterCard";
            }
            else if(card.at(0) == 4){
               type = "VISA";
            }
         }
         if(13 <= card.length() && card.length() <= 16){
            ss.clear();
            ss.str("");
            ss << card.at(0);
            ss >> prefix;
            if(prefix == 4)
            type = "VISA";
         }
   //Returns the card type
   return type;
}

bool LuhnCheck(string card){
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
   return valid;
}
