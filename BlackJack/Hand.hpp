//
//  Hand.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-12-26.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

using namespace std;


class Hand{
public:
    Hand();
    void startGame(Card card);
    
    void printHand();
    void addCard(Card card);
    
//    void printDealerHand();
    void startDealerGame(Card card);
    
    int getHandValue();
    int getNumOfCards();
    
    
private:
    vector<Card> newHand;
};

#endif /* Hand_hpp */
