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

void Card::new_card_file(ifstream &fin){
  //string num;
  stringstream ss;
  ss.clear();
  getline(fin, name, ' ');
  getline(fin, price, '\n');
  /*ss.int(num);
  ss >> temperature;*/
}
