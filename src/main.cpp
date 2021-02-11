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
    Card deck [52];
    for(int i = 0; i < 52; i++){
        deck[i].intializeCard(i, "Hearts");
    }
    for(int i = 0; i < 52; i++){
        std::cout<<deck[i].value<< std::endl;
        std::cout<<deck[i].suit<< std::endl;    
    }
}   