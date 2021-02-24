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

// class Player{
//     public:
//         string name;
//         vector<Card> hand [5];
//         void Set_Hand();
// } ;


// void Player::Set_Hand(){

// }

struct Deck
{
    vector <Card> cards;
    int MAX_SIZE = 24;
};

void initializeDeck(Deck& deck){
    for(int i = 0; i < 4; i++){
        for(int j = 9; j <= 14; j++){
            
            deck.cards.push_back(Card(Rank(j), Suit(i)));
        }
    }
}

void printCard(const Card& card){
    std::cout<<card.value << " of " << card.suit <<std::endl;
}


void printDeck(const Deck& deck){
    for(int i = 0; i < deck.cards.size(); i++){
        printCard(deck.cards[i]);
    }
}



// void showTopCard(vector<Card> deck){
//     std::cout<<deck[0].value << " of " << deck[0].suit << std::endl;
// }

// void shuffleDeck(vector<Card> deck){
//     std::random_shuffle(deck.begin(), deck.end());
// }

int main() {
    // Player players[4];
    Deck deck;

    initializeDeck(deck);
    printDeck(deck);

    // int index = 0;
    // for(int i = 0; i < 4; i++){
    //     players[i].name = ("Player " + i);
    //     for(int j = 0; j < 5; j++){
    //         players[i].hand->push_back(deck[index]);
    //         //  std::cout<<players[i].hand[j].value << " of " << players[i].hand[j].suit <<std::endl;
    //         index++;
    //     }
    // }

    // showTopCard(deck);
    // shuffleDeck(deck);
    // showTopCard(deck);

}   

