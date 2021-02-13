#include <iostream>
#include <string>
#include <algorithm>
using std::string;

class Card{
    public: 
        int value;
        // char * suit;
        string suit;
        void intializeCard(const int VAL, string SUIT);
};

void Card::intializeCard(const int VAL, string SUIT) { this->value = VAL; this->suit = SUIT;}

class Player{
    public:
        string name;
        Card hand [5];
        void Set_Hand();
} ;

void Player::Set_Hand(){

}

void showTopCard(Card * deck){
    std::cout<<deck[0].value << " of " << deck[0].suit << std::endl;
}

void shuffleDeck(Card * deck){
    std::random_shuffle(&deck[0], &deck[52]);
}

int main() {
    Player players[4];
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    Card deck [52];
    int index = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            deck[index].intializeCard(j, suits[i]);
            index++;
        }
    }

    index = 0;
    for(int i = 0; i < 4; i++){
        players[i].name = ("Player " + i);
        for(int j = 0; j < 5; j++){
            players[i].hand[j] = deck[index];
            //  std::cout<<players[i].hand[j].value << " of " << players[i].hand[j].suit <<std::endl;
            index++;
        }
    }

    showTopCard(deck);
    shuffleDeck(deck);
    showTopCard(deck);

}   

