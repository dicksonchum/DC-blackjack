//
//  Hand.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-12-26.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Hand.hpp"

Hand::Hand(){
    Card defaultCard;
    newHand.push_back(defaultCard);
}

void Hand::startGame(Card card){
    newHand.clear();
    handValue = 0;
    indexOfAce = -1;
    numOfAceInHand = 0;
    addCard(card);
}

void Hand::printHand(){
    int i = 0;
    long int handSize = newHand.size();
    for(i = 0; i < handSize; i++){
        newHand[i].printCard();
    }
    cout << "Value is " << handValue << endl << endl;
}

void Hand::addCard(Card card){
    newHand.push_back(card);
    setHandValue(card);
    if(card.getCardNum() == 'A'){
        indexOfAce = int(newHand.size()) - 1;
        numOfAceInHand++;
    }
}

void Hand::startDealerGame(Card card){
    newHand.clear();
    newHand.push_back(card);
}

int Hand::getHandValue(){
    return handValue;
}

void Hand::setHandValue(Card card){
    handValue += card.getCardValue();
    if(handValue > 21 && numOfAceInHand > 0){
        handValue = handValue - 10;
        numOfAceInHand--;
    }
}


int Hand::getNumOfCards(){
    return (int)newHand.size();
}
