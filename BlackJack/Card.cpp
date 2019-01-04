//
//  Card.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-11.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Card.hpp"


Card::Card(){
    cardNum = '0';
}

Card::Card(char card_num, int card_suit){
    cardNum = card_num;
    cardSuit = card_suit;
    cardValue = setValue();
    if(cardValue == -1){
        cout << "cardValue = -1, Stop and check\n";
    }
    cardGiven = false;
}

Card::Card(const Card &cardObj){
    cardNum = cardObj.getCardNum();
    cardSuit = cardObj.getCardSuit();
    cardValue = cardObj.getCardValue();
    cardGiven = cardObj.getCardGiven();
}

Card::~Card(){
    
}

int Card::setValue(){
    if(cardNum == 'A')
        return 11;
    else if(cardNum == 'T' || cardNum == 'J' || cardNum == 'Q' || cardNum == 'K')
        return 10;
    else if(cardNum >= '2' && cardNum <= '9')
        return cardNum - 48;    // since 0 as char starts at 48
    else
        return -1;
}

void Card::setCardGiven(bool status){
    cardGiven = status;
}

void Card::printCard() {
    cardName = cardNum;
    switch (cardSuit) {
        case 0:
            cardName += " of Diamonds";
            break;
        case 1:
            cardName += " of Clubs";
            break;
        case 2:
            cardName += " of Hearts";
            break;
        case 3:
            cardName += " of Spades";
            break;
    }
    cout << cardName << endl;
}

char Card::getCardNum() const{
    return cardNum;
}

int Card::getCardSuit() const{
    return cardSuit;
}

int Card::getCardValue() const{
    return cardValue;
}

bool Card::getCardGiven() const{
    return cardGiven;
}
