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
#include <cstdlib>
#include "Card.hpp"

//using namespace std;

class Deck{
public:
    Deck(int numDeck);

    // optional
    Deck(const Deck&);
    ~Deck();
    
    void fillDeck(int numDeck);
    void shuffleDeck();
    void printDeck();
    Card giveCard();
    long int getDeckSize() const;
    
private:
    vector<Card> myDeck;
    vector<Card> usedDeck;
//    int numOfDeck = 2;
};


#endif /* Deck_hpp */
