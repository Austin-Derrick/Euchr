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

float getHandWeight(vector<Card> &hand, int TRUMP_SUIT){
    float weight = 0;

    //float temp = 0;
    
    for(int i = 0; i < hand.size(); i++){
        hand[i].weight = hand[i].value;
        if (hand[i].value == 11)
        {
            if (((float)TRUMP_SUIT / 4 >= 0.5) && ((float)hand[i].suit / 4 >= 5))
            {
                hand[i].weight = hand[i].suit == TRUMP_SUIT ? 21:20;
            }
            else if (((float)TRUMP_SUIT / 4 <= 0.5) && ((float)hand[i].suit / 4 <= 5))
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
        //std::cout<<hand[i].value << " " << hand[i].weight<<std::endl;
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
        //std::cout<<""<<std::endl;
        //players[i].printHand();
    }
}

int decideTrumpCard(Player *players, Deck &deck){
    bool isTrumpDecided = false;
    int trumpSuit = deck.cards[0].suit;
    std::cout<<"TRUMP SUIT: "<<trumpSuit<<std::endl;
    for (int i = 0; i < 4; i++)
    {
        players[i].handWeight = getHandWeight(players[i].hand, trumpSuit);
        //std::cout<<"Player "<< i + 1 << " Hand weight: "<< players[i].handWeight <<std::endl;
    }
    
    for(int i = 0; i < 4; i++)
    { 
        if (players[i].handWeight > 0.75f)
        {
            //std::cout<<"Player "<< i + 1 << "Chose the trump" <<std::endl;
            return trumpSuit;
        }
        else{
            continue;
        }
        //std::cout<<"Player "<< i + 1 << "passed" <<std::endl;
    }
    return trumpSuit;
}

void playTrick(Player* players, int &trumpSuit){
    Card cardToPlay;
    Card cardsInTrick[4];
    int highestCardPos = 0;
    for (int i = 0; i < 4; i++)
    {
        //std::cout<<"Player "<< i << " plays " << players[i].hand[0].value<< " Of " << players[i].hand[0].suit <<std::endl;//
        cardToPlay = players[i].hand[0];
        for (int j = 0; j < players[i].hand.size(); j++)
        {
            //std::cout<<"Player "<< i << " plays " << players[i].hand[j].value<< " Of " << players[i].hand[j].suit <<std::endl;
            if (players[i].hand[j].weight > cardToPlay.weight)
            {
                //std::cout<<"CHANGE"<<std::endl;
                cardToPlay = players[i].hand[j];
                highestCardPos = j;
                // std::cout<<"Player "<< i << " plays " << cardToPlay.value<< " Of " << cardToPlay.suit <<std::endl;//
                // std::cout<<""<<std::endl;
            }
        }
        
        //std::cout<<players[i].hand.size()<<std::endl;
        players[i].hand.erase(players[i].hand.begin() + highestCardPos);
        //std::cout<<players[i].hand.size()<<std::endl;

        //std::cout<<"Player "<< i << " plays " << players[i].hand[i].value<< " Of " << players[i].hand[0].suit <<std::endl;//
        //std::cout<<"Player "<< i << " plays " << cardToPlay.value<< " Of " << cardToPlay.suit <<std::endl;//
        cardsInTrick[i] = cardToPlay;
    }

    Card highestCard;
    highestCard = cardsInTrick[0];
    int highestPlayer = 0;

    for (int i = 0; i < 4; i++)
    {
        if (highestCard.weight < cardsInTrick[i].weight)
        {
            highestCard = cardsInTrick[i];
            highestPlayer = i + 1;
        }
        std::cout<<"\t"<<"Player "<<i + 1<<" plays - "<<cardsInTrick[i].value<< " OF " << cardsInTrick[i].suit << " WEIGHT OF - "<< cardsInTrick[i].weight <<std::endl;
    }
    std::cout<<"WINNER : PLAYER "<<highestPlayer<<std::endl;
    std::cout<<highestCard.value<< " OF " << highestCard.suit << " WEIGHT OF - "<< highestCard.weight <<std::endl;
    // std::cout<<""<< std::endl;
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
        trumpSuit = decideTrumpCard(players, deck);
        while (players[0].hand.size() > 0)
        {
            playTrick(players, trumpSuit);
        }
        // for (int i = 0; i < 4; i++)
        // {
        //     std::cout<<"BEFORE: "<<std::endl;
        //     for (int j = 0; j < players[i].hand.size(); j++)
        //     {
        //         std::cout<<players[i].hand[j].value<< " OF "<< players[i].hand[j].suit<<std::endl;
        //     }

        //     players[i].hand.erase(players[i].hand.begin() + i);

        //     std::cout<<"AFTER: "<<std::endl;
        //     for (int j = 0; j < players[i].hand.size(); j++)
        //     {
        //         std::cout<<players[i].hand[j].value<< " OF "<< players[i].hand[j].suit<<std::endl;
        //     }
        //     std::cout<<""<<std::endl;
        // }
        
    }
    std::cout<<"Thank you for playing"<<std::endl;
}