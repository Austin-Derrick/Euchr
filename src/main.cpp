#include <iostream>
#include <string>

class Card{
    public: 
        int value;
        //string suit;
        void intializeCard(const int VAL);
};

void Card::intializeCard(const int VAL) { this->value = VAL;}

int main() {
    Card deck [52];
    for(int i = 0; i < 52; i++){
        deck[i].intializeCard(i);
    }
    for(int i = 0; i < 52; i++){
        std::cout<<deck[i].value<< std::endl;
    }
}