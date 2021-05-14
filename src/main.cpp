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

    //float temp = 0;
    
    for(int i = 0; i < hand.size(); i++){
        hand[i].weight = hand[i].value;
        if (hand[i].value == 11)
        {
            if ((TRUMP_SUIT / 4 >= 0.5) && (hand[i].suit / 4 >= 5))
            {
                hand[i].weight = hand[i].suit == TRUMP_SUIT ? 21:20;
            }
            else if ((TRUMP_SUIT / 4 <= 0.5) && (hand[i].suit / 4 <= 5))
            {
                hand[i].weight = hand[i].suit == TRUMP_SUIT ? 21:20;
            }
        }
        else if (hand[i].suit == TRUMP_SUIT)
        {
            if (hand[i].suit == 14)
            {
                hand[i].weight = hand[i].value + 5;
            }
            else{
                hand[i].weight = hand[i].value + 6;
            }
        }
        std::cout<<hand[i].value << " " << hand[i].weight<<std::endl;
        weight += hand[i].weight;
    }
    //std::cout<<weight<<std::endl;
    return weight / 95;
}

void redeal(Player *players, Deck& deck){
    initializeDeck(deck);
    shuffleDeck(deck);
    shuffleDeck(deck);
    for(int i = 0; i < 4; i++){
        players[i].setHand(deck);
        std::cout<<""<<std::endl;
        players[i].printHand();
    }
}

int decideTrumpCard(Player *players, Deck &deck){
    bool isTrumpDecided = false;
    int trumpSuit = deck.cards[0].suit;
    std::cout<<trumpSuit<<std::endl;
    for (int i = 0; i < 4; i++)
    {
        players[i].handWeight = getHandWeight(players[i].hand, trumpSuit);
        std::cout<<"Player "<< i + 1 << " Hand weight: "<< players[i].handWeight <<std::endl;
    }
    
    for(int i = 0; i < 4; i++)
    { 
        if (players[i].handWeight > 0.75f)
        {
            std::cout<<"Player "<< i + 1 << "Chose the trump" <<std::endl;
            return trumpSuit;
        }
        else{
            continue;
        }
        std::cout<<"Player "<< i + 1 << "passed" <<std::endl;
    }
    return trumpSuit;
}

void playTrick(Player* players, int &trumpSuit){
    Card *cardToPlay;
    Card *cardsInTrick[4];
    
    for (int i = 0; i < 4; i++)
    {
        cardToPlay = &players[i].hand[0];
        for (int j = 0; j < players[i].hand.size(); j++)
        {
            if (players[i].hand[j].suit == trumpSuit)
            {
                if (players[i].hand[j].weight > cardToPlay->weight)
                {
                    cardToPlay = &players[i].hand[j];
                }
                else{
                    cardToPlay = &players[i].hand[j];
                }
            }
        }
        //std::cout<<"Player "<< i << " plays " << cardToPlay->value<< " Of " << cardToPlay->suit <<std::endl;//
        cardsInTrick[i] = cardToPlay;
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout<<cardsInTrick[i]->value<< " OF " << cardsInTrick[i]->suit << " WEIGHT OF - "<< cardsInTrick[i]->weight <<std::endl;
    }
    
}

int main() {
    Deck deck;
    initializeDeck(deck);
    // printDeck(deck);
    int trumpSuit;
    Player players[4];

    for(int i = 0; i < 4; i++){
        players[i].setHand(deck);
        
        // std::cout<<""<<std::endl;
        // players[i].printHand();
    }
    bool isPlaying = false;
    while (askContinueGame())
    {
        redeal(players, deck);
        redeal(players, deck);
        redeal(players, deck);
        redeal(players, deck);
        trumpSuit = decideTrumpCard(players, deck);
        playTrick(players, trumpSuit);
    }
    std::cout<<"Thank you for playing"<<std::endl;
}