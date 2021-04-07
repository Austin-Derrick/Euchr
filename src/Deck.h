#pragma once

#include <vector>
#include "Card.h"
using std::vector;

class Deck{
    public:
        vector <Card> cards;
        int MAX_SIZE;
        void initializeDeck(Deck& deck);
        
};

