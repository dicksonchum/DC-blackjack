//
//  Card.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-11.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

// One Card

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
//#include <time.h>

using namespace std;

class Card{

public:
    Card();
    Card(char card_num, int card_suit);
    Card(const Card&);
    ~Card();
    
    char getCardNum() const;
    int getCardSuit() const;
    int getCardValue() const;
    bool getCardGiven() const;
    
    void printCard();
    int setValue();
    void setCardGiven(bool status);
    
//    int const getTempDeckCard(int tempCardNum);
    
private:
    char cardNum;   // A,2,3,4,5,6,7,8,9,10,J,Q,K
    int cardSuit;   // Diamonds = 0, Clubs = 1, Hearts = 2, Spades = 3
    int cardValue;  // A = 11, 2,3,4,5,6,7,8,9, {T = 10,J,Q,K} = 10
    string cardName;
    
    bool cardGiven; // false = not given, true = given
};

#endif /* Card_hpp */
