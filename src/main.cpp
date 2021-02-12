#include <iostream>
#include <string>
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
            std::cout<<players[i].hand[j].value << " of " << players[i].hand[j].suit <<std::endl;
            index++;
        }
    }

    // for(int i = 0; i < 4; i++){
    //     std::cout<<deck[i].value<< std::endl;
    //     std::cout<<deck[i].suit<< std::endl;    
    // }
}   