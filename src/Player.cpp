#include "Player.h"
#include <iostream>

Player::Player(){
    for(int i = 0; i < 6; i++){
        hand.push_back(Card(Rank(), Suit()));
    }
}

Player::~Player(){
    delete this;
}

void Player::setHand(Deck& deck){
    hand.clear();
    for(int i = 0; i < 5; i++){
        hand.push_back(deck.cards.back());
        deck.cards.pop_back();
    }
}

void printCard(const Card& card) { std::cout<<card.value << " of " << card.suit <<std::endl; }

void Player::printHand(){
    for (int i = 0; i < hand.size(); i++)
    {
        printCard(hand[i]);
    }
}