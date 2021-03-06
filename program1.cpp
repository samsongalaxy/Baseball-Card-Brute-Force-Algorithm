#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "Card.h"

using namespace std;

int card_check(Card *i, Card c){
  for(int j = 0; j < sizeof(i)/sizeof(i[0]); j++){
    cout << "Checking for card: " << c.name << "\n";
    cout << "Current card: " << i[j].name << "\n";
    if(i[j].name == c.name) return 0;
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
    cout << "attempting to read: " << temp << "\n";
    int x = stoi(temp); //number of cards for current section in price_list
    getline(plfin, temp, '\n');
    cout << "attempting to read: " << temp << "\n";
    int w = stoi(temp); //weight constraint for problem
    Card *s = new Card[x];
    int sum = 0; //potential cost of all of Gertrude's card
    for(int j = 0; j < x; j++){
      Card c;
      c.new_card_file(plfin);
      s[j] = c;
      sum += s[j].price;
      //cout << "Current card: " << s[j].name << "\n";
      //card_check(i, s[j]); // for debugging
      int flag = 0;
      for(int j = 0; j < n; j++){
        //cout << "Checking for card: " << c.name << "\n";
        //cout << "Current card: " << i[j].name << "\n";
        string s1 = i[j].name;
        string s2 = s[j].name;
        if(s1.compare(s2) == 0) flag = 1;
      }
      if(flag == 0){
        cout << "ERROR: " << s[j].name << " not found in market price file.\nEnding program...\n";
        return 0;
      }
    }
    int maxProfit = 0, cardsBought = 0;

    if(sum <= w){
      //cout << "hi1\n";
      ofstream fout;
      fout.open("output.txt", ios::out | ios::trunc);
      fout << x << "\n";
      int profit = 0;
      for(int j = 0; j < x; j++){
        /*cout << "Current card price: " << s[j].get_price() << "\n";
        cout << "Current card name: " << s[j].get_name() << "\n";*/
        for(int k = 0; k < n; k++){
          string s1 = s[j].get_name();
          string s2 = i[k].get_name();
          /*cout << "Current card price: " << i[k].price << "\n";
          cout << "Current card name: " << s2.c_str() << "\n";*/
          if(s1.compare(s2) == 0) profit += i[k].price - s[j].price;
          //cout << "Current profit: " << profit << "\n";
        }
      }
      fout << profit << "\n";
      fout << x << "\n";
      fout << ((double)clock()-start)/(double)CLOCKS_PER_SEC << "\n";
      fout.close();
      cout << "The current problem has finished, enter 'q' to end the program, enter anything else to continue.\n";
      string input;
      cin >> input;
      if(input == "q" || input == "Q"){
        cout << "The program has ended, results for the most recent problem can be found in 'output.txt'\n";
        return 0;
      }
      else cout << "Continuing program.\n";
    }
    else{
      vector<Card> m;
      m.push_back(s[0]);
      int a = 0, b = 0;
      while(true){
        if(a == x){
          a = 0;
          b++;
          if(b == x) break;
          m.push_back(s)
        }
        m[b] = s[a];
        vector<string>::iterator it;
        it = m.begin();
        int profit = 0, count = 0;
        while(it != m.end()){
          for(int k = 0; k < n; k++){
            string s1 = m[count].get_name();
            string s2 = i[k].get_name();
            if(s1.compare(s2) == 0) profit += i[k].price - s[j].price;
          it++;
          count++;
        }
        if(profit > maxProfit){
          maxProfit = profit;
          cardsBought = b;
        }
      }
      a++;
    }
    start = clock();
  }
  cout << "The program has ended, results for the most recent problem can be found in 'output.txt'\n";
  return 0;
}
