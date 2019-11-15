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
    int getNumOfDeck() const;
    
    // Counting Card functions
    void setCount(Card curCard);
    int getCount() const;
    
private:
    vector<Card> myDeck;
    vector<Card> usedDeck;
    int numOfDeck;
    
    int countingCard;
};


#endif /* Deck_hpp */
