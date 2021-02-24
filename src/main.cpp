#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
    
enum Rank {NINE = 9, TEN, JACK, QUEEN, KING, ACE, TRUMP};
enum Suit {SPADES, CLUBS, DIAMONDS, HEARTS};

class Card{
    public: 
        Rank value;
        Suit suit;
        Card(Rank VAL, Suit SUIT);
};

Card::Card( Rank VAL, Suit SUIT) { this->value = VAL; this->suit = SUIT;}

struct Deck
{
    vector <Card> cards;
    int MAX_SIZE = 24;
};

// Prints a passed through card's value and suit
void printCard(const Card& card) { std::cout<<card.value << " of " << card.suit <<std::endl; }

class Player{
    public:
        string name;
        vector<Card> hand;
        Player();
        void setHand(Deck& deck);
        void printHand();
};

Player::Player(){
    for(int i = 0; i < 6; i++){
        hand.push_back(Card(Rank(), Suit()));
    }
}

void Player::setHand(Deck& deck){
    hand.clear();
    for(int i = 0; i < 5; i++){
        hand.push_back(deck.cards.back());
        deck.cards.pop_back();
    }
}

void Player::printHand(){
    for (int i = 0; i < hand.size(); i++)
    {
        printCard(hand[i]);
    }
    
}

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

int main() {
    Deck deck;
    initializeDeck(deck);
    printDeck(deck);

    Player players[4];

    for(int i = 0; i < 4; i++){
        players[i].setHand(deck);
        std::cout<<""<<std::endl;
        players[i].printHand();
    }
}