//
//  Player.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Player.hpp"
Player::Player(){
    newName = "";
    newAccount = 0;
    win = 0;
}

Player::Player(string playerName, double playerAccount){
    newName = playerName;
    newAccount = playerAccount;
    win = 0;
}

Player::~Player(){
}

void Player::setBet(){
    int cash = 0;
    do{
        cout << "How much are you betting? ";
        cin >> cash;
    }while(cash <= 0);
    bet = cash;
}

void Player::getBet(){
    newAccount += bet;
    bet = 0;
}

void Player::setMyHand(Deck &deck){
    myHand.startGame(deck.giveCard());
}

void Player::dealSecondCard(Deck &deck){
    myHand.addCard(deck.giveCard());
}

void Player::printMyHand(){
    cout << "Player's hand is\n";
    myHand.printHand();
}

void Player::hit(Deck &deck){
    cout << "Hit\n\n";
    myHand.addCard(deck.giveCard());
//    myHand.printHand();
}

void Player::stand(){
    cout << "Player stands\n";
}

int Player::getValue(){
    return myHand.getHandValue();
}

string Player::getName() const{
    return newName;
}

double Player::getAccount() const{
    return newAccount;
}

void Player::setName(string playerName){
    newName = playerName;
}

void Player::setAccount(double playerAccount){
    newAccount = playerAccount;
}

void Player::cashOut(){
    newAccount = 0;
}

void Player::changeAccount(double changeA){
    newAccount += changeA;
}

int Player::numOfWin() const{
    return win;
}

//void Player::winGame(Player &playerObj){
//    bet = bet * 2;
//    getBet();
//    win++;
//}

void Player::winGame(){
    win++;
}

bool Player::playerDecision(Player &playerObj, Deck &deckobj){
    char input;
    
    while(playerObj.getValue() < 22){
        playerObj.printMyHand();
        do{
            cout << "Please input 'h' or 's'.\n";
            cout << "Hit or stand? (h/s) ";
            cin >> input;
        }while(input != 'h' && input != 's');
        
        if(input == 'h'){
            playerObj.hit(deckobj);
        }
        else{
            playerObj.stand();
            return true;
        }
    }
    return false;
}

bool Player::playerDecisionAutomation(Player &playerObj, Player &dealerObj, Deck &deckobj){
    char input;
    
    if(playerObj.getValue() == 21){
        cout << "BlackJack 21\n";
        return true;
    }
    
    while(playerObj.getValue() <= 21){
        playerObj.printMyHand();
        input = 's';
        if(playerObj.getValue() >= 9 && playerObj.getValue() <= 11){
            cout << "Double down\n";
            input = 'd';
        }
        else if(playerObj.getValue() <= 9){
            input = 'h';
        }
        else if(playerObj.getValue() >= 12 && playerObj.getValue() <= 16 && dealerObj.getValue() <= 6){
            cout << "Dealer has high chance to bust\n";
            input = 's';
        }
        else if(playerObj.getValue() - 10 < dealerObj.getValue() && playerObj.getValue() <= 17){
            cout << "Player hits for higher chance to win\n";
            input = 'h';
        }
        else{
            input = 's';
        }
        
        
        if(input == 'h'){
            playerObj.hit(deckobj);
        }
        else if(input == 'd'){
            playerObj.hit(deckobj);
            return true;
        }
        else{
            playerObj.stand();
            cout << endl;
            return true;
        }
    }
    cout << "Player busts, value = " << playerObj.getValue() << endl << endl;
    
    return false;
}
