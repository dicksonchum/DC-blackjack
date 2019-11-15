//
//  Player.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Hand.hpp"
#include "Deck.hpp"

class Player{

public:
    Player();
    Player(string playerName, double playerAccount);
    ~Player();
    
    void setBet();
    void autoSetBet(double numOfDeck);
    bool canDoubleDown();
    void doubleDownBet();
    void getBet();
    void setMyHand(Deck &deck);
    void dealSecondCard(Deck &deck);
    void hit(Deck &deck);
    void stand();
    bool playerDecision(Player &playerObj, Deck &deckobj);
    bool playerDecisionAutomation(Player &playerObj, Player &dealerObj, Deck &deckobj);
    
    int getValue();
    void setValue();
    void printMyHand();
    
    
    string getName() const;
    double getAccount() const;
    void setName(string playerName);
    void setAccount(double playerAccount);
    
    int numOfWin() const;
//    void winGame(Player &playerObj);
    void winGame();
    void drawGame();
    void loseGame();
    
    void cashOut();
    void changeAccount(double playerAccount);
    
    void getCount(Deck& deckobj);
    
protected:
    string newName;
    double newAccount;
    Hand myHand;
    int win;
    double bet;
    int cardCount;
};


#endif /* Player_hpp */
