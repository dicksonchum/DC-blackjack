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
    cout << "Account: " << newAccount << "\nHow much are you betting? ";
    cin >> cash;
    
    while(cash <= 0 || newAccount < cash){
        cout << "Cash cannot be negative or Account does not have enough money. Try again\n\n"
        << "Account: " << newAccount << "\nHow much are you betting? ";
        cin >> cash;
    }
    newAccount -= cash;
    bet = cash;
}

void Player::autoSetBet(double numOfDeck){
    int cash = 10;
    double trueCount = cardCount/numOfDeck;
    cout << "True count = " << trueCount << endl;
//    int temp1 = 10;
//    double tempTrueCount = 5/numOfDeck;
//    cout << "checking math, " << temp1 * int((tempTrueCount - 0.5)/0.5) << endl;
    int tempBet = cash * static_cast<int>((trueCount - 0.5)/0.5);
    if(newAccount >= tempBet && trueCount >= 1.5){
        bet = tempBet;
//        bet = cash * cardCount/3;
    }
    else{
        bet = cash;
    }
    newAccount -= bet;
    cout << "Betting = " << bet << endl;
    
}

void Player::doubleDownBet(){
    newAccount -= bet;
    bet *= 2;
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
    cout << "Player cash out with $ " << newAccount << endl;
    newAccount = 0;
}

void Player::changeAccount(double changeA){
    newAccount += changeA;
}

int Player::numOfWin() const{
    return win;
}

void Player::winGame(){
    newAccount += 2 * bet;
    bet = 0;
    win++;
}

void Player::drawGame(){
    newAccount += bet;
    bet = 0;
}

void Player::loseGame(){
    bet = 0;
}

// return true if player busts
bool Player::playerDecision(Player &playerObj, Deck &deckobj){
    char input;
    
    if(playerObj.getValue() == 21){
        cout << "BlackJack 21\n";
        return false;
    }
    
    while(playerObj.getValue() < 22){
        playerObj.printMyHand();
        do{
            cout << "Please input 'h', 's' or 'd'.\n";
            cout << "Hit, stand or double down? (h/s/d) ";
            cin >> input;
        }while(input != 'h' && input != 's' && !(input == 'd' && canDoubleDown()));
        
        if(input == 'd'){
            playerObj.doubleDownBet();
            playerObj.hit(deckobj);
            if(playerObj.getValue() <= 21){
                return false;
            }
        }
        else if(input == 'h'){
            playerObj.hit(deckobj);
            if(playerObj.getValue() == 21){
                return false;
            }
        }
        else{
            playerObj.stand();
            return false;
        }
    }
    
    cout << "Player busts, value = " << playerObj.getValue() << endl << endl;
    
    return true;
}


// return true if player busts
bool Player::playerDecisionAutomation(Player &playerObj, Player &dealerObj, Deck &deckobj){
    char input;
    
    if(playerObj.getValue() == 21){
        cout << "BlackJack 21\n";
        return false;
    }
    
    while(playerObj.getValue() <= 21){
        playerObj.printMyHand();
        input = 's';
        if(getValue() >= 9 && getValue() <= 11 && canDoubleDown()){
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
        
        // 'h' is hit
        if(input == 'h'){
            playerObj.hit(deckobj);
        }
        // 'd' is double down
        else if(input == 'd'){
            playerObj.doubleDownBet();
            playerObj.hit(deckobj);
            return false;
        }
        else{ // stand
            playerObj.stand();
            cout << endl;
            return false;
        }
    }
    cout << "Player busts, value = " << playerObj.getValue() << endl << endl;
    
    return true;
}

void Player::getCount(Deck& deckobj){
    cardCount = deckobj.getCount();
}

bool Player::canDoubleDown() {
    return ((newAccount - bet*2) >= 0);
}
