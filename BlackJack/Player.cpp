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
}

//Player::Player(string playerName, double playerAccount, Deck deck){
//    newName = playerName;
//    newAccount = playerAccount;
//    myHand = Hand(deck.giveCard(), deck.giveCard());
//}

Player::Player(string playerName, double playerAccount){
    newName = playerName;
    newAccount = playerAccount;
}

Player::~Player(){
}

void Player::setMyHand(Deck &deck){
    myHand.startGame(deck.giveCard());
}



void Player::printMyHand(){
    cout << "Your hand is\n";
    myHand.printHand();
}

void Player::hit(Deck &deck){
    cout << "Hit\n";
    myHand.addCard(deck.giveCard());
    myHand.printHand();
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


