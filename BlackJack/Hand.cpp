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
    newHand.push_back(card);
//    newHand.push_back(card2);
}

void Hand::printHand(){
    int i = 0;
    long int handSize = newHand.size();
    int sum = 0;
    for(i = 0; i < handSize; i++){
        sum += newHand[i].getCardValue();
        newHand[i].printCard();
    }
    
    cout << "Value is " << sum << endl << endl;
}

void Hand::addCard(Card card){
    newHand.push_back(card);
}

//void Hand::printDealerHand(){
//    newHand[0].printCard();
//}

void Hand::startDealerGame(Card card){
    newHand.clear();
    newHand.push_back(card);
}

int Hand::getHandValue(){
    int i = 0;
    int value = 0;
    long int handSize = newHand.size();
    for(i = 0; i < handSize; i++){
        value += newHand[i].getCardValue();
    }
    return value;
}

int Hand::getNumOfCards(){
    return (int)newHand.size();
}
