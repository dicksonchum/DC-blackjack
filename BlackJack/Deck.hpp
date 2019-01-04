//
//  Deck.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-10-01.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Card.hpp"


class Deck{
public:
    Deck();

    // optional
    Deck(const Deck&);
    ~Deck();
    
    void fillDeck();
    void shuffleDeck();
    void printDeck();
    Card giveCard();
    long int getDeckSize() const;
    
private:
//    Card myDeck[52];
    vector<Card> myDeck;
};


#endif /* Deck_hpp */
