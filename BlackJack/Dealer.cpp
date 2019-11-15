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

void Dealer::printDealerHand(){
    cout << "Dealer's hand is\n";
    myHand.printHand();
}

bool Dealer::dealerDecision(Deck &deck){
    cout << "Dealer's turn\n";
    myHand.addCard(deck.giveCard());
    printDealerHand();
    
    cout << "Dealer decision\n";
    while(getValue() < 17){
        hit(deck);
    }
    printDealerHand();
    if(getValue() > 21){
        return false;
    }
    return true;
}

void Dealer::game(Player &player){
    // check if player or dealer win
    cout << "Player : " << player.getValue() << endl;
    cout << "Dealer : " << getValue() << endl;
    if(player.getValue() >= 22){
        winGame();
        player.loseGame();
        cout << "Player busts, Dealer wins, ";
    }
    else if(myHand.getHandValue() >= 22){
        player.winGame();
        cout << "Dealer busts, Player wins, ";
    }
    else if(player.getValue() == myHand.getHandValue()){
        player.drawGame();
        cout << "Draw, ";
//        cout << "Player's account = " << player.getAccount() << endl;
    }
    else if(player.getValue() > myHand.getHandValue()){
        player.winGame();
        cout << "Player wins, ";
//        cout << "Player's account = " << player.getAccount() << endl;
    }
    else{
        winGame();
        player.loseGame();
        cout << "Dealer wins, ";
    }
    cout << "Player's account = " << player.getAccount() << endl;
}
