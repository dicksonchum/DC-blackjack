//
//  Dealer.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-12-26.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Dealer.hpp"

void Dealer::setDealerHand(Deck &deck){
    cout << "Dealer's hand is\n";
    myHand.startGame(deck.giveCard());
}

void Dealer::printHand(){
    cout << "Dealer's hand is\n";
    myHand.printHand();
}

bool Dealer::dealerDecision(Deck &deck){
    myHand.addCard(deck.giveCard());
    while(getValue() < 17){
        hit(deck);
    }
    if(getValue() > 21)
        return false;
    
    return true;
}

void Dealer::game(Player player){
    // check if player or dealer win
    
    if(player.getValue() == myHand.getHandValue()){
        cout << "Draw\n";
    }
    else if(player.getValue() > myHand.getHandValue()){
        cout << "Player wins\n";
    }
    else
        cout << "Dealer wins\n";
    
}
