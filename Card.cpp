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
  //string num;
  /*stringstream ss;
  ss.clear();*/
  string temp;
  getline(fin, name, ' ');
  getline(fin, temp, '\n');
  price = stoi(temp);
  /*ss.int(num);
  ss >> temperature;*/
}
