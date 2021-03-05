#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "Card.h"

using namespace std;

bool card_check(Card *i, string c){
  for(int j = 0; j < sizeof(i)/sizeof(i[0]); j++){
    if(i[j].name == c) return true;
  }
  return false;
}

int main(int argc, char *argv[]){
  string mpf;
  cin >> mpf;
  ifstream mpfin;
  mpfin.open(mpf, ios::in);
  string temp;
  getline(mpfin, temp);
  int n = stoi(temp); //number of cards in market_price
  Card *i = new Card[n];

  for(int j = 0; j < n; j++){
    Card c;
    c.new_card_file(mpfin);
    i[j] = c;

  }
  mpfin.close();
  string plf;
  cin >> plf;
  ifstream plfin;
  plfin.open(plf, ios::in);
  while(!plfin.eof()){
    getline(plfin, temp, ' ');
    int x = stoi(temp); //number of cards for current section in price_list
    getline(plfin, temp, '\n');
    int w = stoi(temp); //weight constraint for problem
    Card *s = new Card[x];
    int sum = 0; //potential cost of all of Gertrude's card
    for(int j = 0; j < x; j++){
      Card c;
      c.new_card_file(plfin);
      s[j] = c;
      sum += s[j].price;
      if(!card_check(i, s[j].name)){
        cout << "ERROR: " << s[j].name << " not found in market price file.\nEnding program...\n";
        return 0;
      }
    }
    int maxProfit = 0;
    Card *m = new Card[x];


  }
}
