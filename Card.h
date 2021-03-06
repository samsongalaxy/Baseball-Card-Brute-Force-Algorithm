#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class Card{
    public:
        Card();
        void assignValue(std::string n, int p);
        void new_card_file(std::ifstream &fin);
        int card_check(Card *i);
        std::string name;
        int price;
};
#endif
