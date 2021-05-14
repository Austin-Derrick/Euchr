#pragma once

enum Rank {NINE = 9, TEN, JACK, QUEEN, KING, ACE, TRUMP};
enum Suit {SPADES, CLUBS, DIAMONDS, HEARTS};

class Card{
    public: 
        Rank value;
        Suit suit;
        int weight;
        Card(Rank VAL, Suit SUIT);
        Card();
};