#include <cassert>
#include "src/main.cpp"

int testHandWeight(){
    Deck deck;
    initializeDeck(deck);
    Player testPlayer;
    testPlayer.setHand(deck);
    return getHandWeight(testPlayer.hand, 0);
}

void testRunner(){/*assert(55)*/assert(testHandWeight() < 1);
}