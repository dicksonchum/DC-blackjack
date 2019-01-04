//
//  Dealer.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-12-26.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Dealer_hpp
#define Dealer_hpp

#include <stdio.h>
#include "Player.hpp"

class Dealer : public Player{
public:
    void setDealerHand(Deck &deck);
    void printHand();
    bool dealerDecision(Deck &deck);
    void game(Player player);
    
};

#endif /* Dealer_hpp */
