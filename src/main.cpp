#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.cpp"
#include "Deck.cpp"
#include "Card.cpp"
using std::string;
using std::vector;

// Prints a passed through card's value and suit
//void printCard(const Card& card) { std::cout<<card.value << " of " << card.suit <<std::endl; }

// Organizes a Card vector inside of a deck struct
void initializeDeck(Deck& deck){
    for(int i = 0; i < 4; i++){
        for(int j = 9; j <= 14; j++){
            deck.cards.push_back(Card(Rank(j), Suit(i)));
        }
    }
}

// Prints the Card Vector inside of a Deck Struct
void printDeck(const Deck& deck){
    for(int i = 0; i < deck.cards.size(); i++){
        printCard(deck.cards[i]);
    }
}

// Prints the first element of a Card vector from a Deck
void showTopCard(Deck& deck){
    printCard(deck.cards.front());
}

void shuffleDeck(Deck& deck){
    std::random_shuffle(deck.cards.begin(), deck.cards.end());
}

bool askContinueGame(){
    int choice_01 = 0;
    std::cout<<"Would you like to begin the game?"<<std::endl<<"1) - yes"<<std::endl<<"2) - no)"<<std::endl;
    std::cin>>choice_01;
    return choice_01 == 1 ? true : false;
}

float getHandWeight(vector<Card> hand, int TRUMP_SUIT){
    float weight = 0;

    float temp = 0;
    
    for(int i = 0; i < hand.size(); i++){
        temp = hand[i].value;
        if (hand[i].value == 11)
        {
            if ((TRUMP_SUIT / 4 >= 0.5) && (hand[i].suit / 4 >= 5))
            {
                temp = hand[i].suit == TRUMP_SUIT ? 21:20;
            }
            else if ((TRUMP_SUIT / 4 <= 0.5) && (hand[i].suit / 4 <= 5))
            {
                temp = hand[i].suit == TRUMP_SUIT ? 21:20;
            }
        }
        else if (hand[i].suit == TRUMP_SUIT)
        {
            if (hand[i].suit == 14)
            {
                temp = hand[i].value + 5;
            }
            else{
                temp = hand[i].value + 6;
            }
        }
        
        weight += temp;
    }

    return weight / 95;
}

void redeal(Player *players, Deck& deck){
    initializeDeck(deck);
    shuffleDeck(deck);
    for(int i = 0; i < 4; i++){
        players[i].setHand(deck);
        std::cout<<""<<std::endl;
        players[i].printHand();
    }
}

int main() {
    Deck deck;
    initializeDeck(deck);
    // printDeck(deck);

    Player players[4];

    for(int i = 0; i < 4; i++){
        players[i].setHand(deck);
        std::cout<<""<<std::endl;
        players[i].printHand();
    }
    bool isPlaying = false;
    bool isTrumpDecided = false;
    while (askContinueGame())
    {
        redeal(players, deck);
        for(int i = 0; i < 4; i++){ 
            if (!isTrumpDecided)
            {
                isTrumpDecided = getHandWeight(players[i].hand, 0) > 0.75 ? true : false;
            }
            
            else{
                break;
            }
            
            std::cout<<getHandWeight(players[i].hand, 0)<<std::endl;
        }
    }
    std::cout<<"Thank you for playing"<<std::endl;
}