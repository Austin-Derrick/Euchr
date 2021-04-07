#include "Deck.h"

void Deck::initializeDeck(Deck& deck){
    for(int i = 0; i < 4; i++){
        for(int j = 9; j <= 14; j++){
            deck.cards.push_back(Card(Rank(j), Suit(i)));
        }
    }
}