#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class Card{
    public:
        Card();
        void new_card_file(std::ifstream &fin);
        std::string name;
        int price;
};
#endif
