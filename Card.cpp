#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "Card.h"

using namespace std;

Card::Card(){
  name = "EmptyName";
  price = -1;
}

void Card::assignValue(string n, int p){
  name = n;
  price = p;
}

void Card::new_card_file(ifstream &fin){
  string temp;
  getline(fin, name, ' ');
  getline(fin, temp, '\n');
  price = stoi(temp);
}

int Card::get_price(){
  return price;
}

string Card::get_name(){
  return name;
}
