#pragma once

#include <vector>
#include <string>
#include "Deck.h"
#include "Card.h"
using std::string;
using std::vector;

class Player{
    public:
        string name;
        vector<Card> hand;
        float handWeight;
        Player();
        ~Player();
        void setHand(Deck& deck);
        void printHand();
};