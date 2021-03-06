#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <time>
#include "Card.h"

using namespace std;

int card_check(Card *i, string c){
  for(int j = 0; j < sizeof(i)/sizeof(i[0]); j++){
    cout << "Checking for card: " << c << "\n";
    cout << "Current card: " << i[j].name << "\n";
    if(i[j].name == c) return 0;
  }
  return 1;
}

int find_profit(Card *i, Card *m){
  int ret = 0;
  for(int j = 0; j < sizeof(m)/sizeof(m[0]); j++){
    for(int k = 0; k < sizeof(i)/sizeof(i[0]); k++){
      if(m[j].name == i[k].name) ret += i[k].price - m[j].price;
    }
  }
  return ret;
}

int main(int argc, char *argv[]){
  clock_t start = clock();
  cout << "Please enter the name of the market price file: ";
  string mpf;
  cin >> mpf;
  ifstream mpfin;
  mpfin.open(mpf, ios::in);
  cout << mpf << " has been successfully opened.\n";
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
  cout << "Please enter the name of the price list file: ";
  string plf;
  cin >> plf;
  ifstream plfin;
  plfin.open(plf, ios::in);
  cout << plf << " has been successfully opened.\n";
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
      card_check(i, s[j].name); // for debugging
      if(card_check(i, s[j].name) == 1){
        cout << "ERROR: " << s[j].name << " not found in market price file.\nEnding program...\n";
        return 0;
      }
    }
    int maxProfit = 0, cardsBought = 0;
    Card *m = new Card[x];
    if(sum <= w){
      ofstream fout;
      fout.open("output.txt", ios::out | ios::trunc);
      fout << x << "\n";
      fout << find_profit(i, s) << "\n";
      fout << x << "\n";
      fout << ((double)clock()-start)/(double)CLOCKS_PER_SEC << "\n";
      cout << "The current problem has finished, press ENTER to go to the next one or type 'q' to end the program.\n";
      string input;
      cin >> input;
      if(input == "q" || input == "Q"){
        cout << "The program has ended, results for the most recent problem can be found in 'output.txt'\n";
        return 0;
      }
    }

    start = clock();
  }
  cout << "The program has ended, results for the most recent problem can be found in 'output.txt'\n";
  return 0;
}
