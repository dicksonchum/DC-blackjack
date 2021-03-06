//
//  Deck.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-10-01.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Deck.hpp"

int randomNum(int i){
    return rand() % i;
}

Deck::Deck(int numDeck){
    fillDeck(numDeck);
    shuffleDeck();
//    printDeck();
    countingCard = 0;
    numOfDeck = numDeck;
}

Deck::Deck(const Deck& deckObj){
    
}

Deck::~Deck(){

}

void Deck::fillDeck(int numDeck){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    
    for(i = 1; i <= 13; i++){
        char card = '0';
        
        if(i == 1)
            card = 'A';
        else if(i >= 2 && i <= 9)
            card = i + 48;
        else if(i == 10)
            card = 'T';
        else if(i == 11)
            card = 'J';
        else if(i == 12)
            card = 'Q';
        else if(i == 13)
            card = 'K';
        
        for(j = 0; j <= 3; j++){
            for(k = 0; k < numDeck; k++){
                myDeck.push_back(Card(card, j));
                count++;
            }
        }
    }
    if(count == 52 * numDeck){
        cout << "Filled " << numDeck << " deck\n";
    }
}

void Deck::shuffleDeck(){
    cout << "Shuffle begins\n";
    random_shuffle(myDeck.begin(), myDeck.end(), randomNum);
    cout << "Shuffle is done\n";
}

void Deck::printDeck(){
    int i = 0;
    cout << "Print Deck\n" << endl;
    cout << "Size : " << myDeck.size() << endl;
    for(i = 0; i < myDeck.size(); i++){
        cout << myDeck[i].getCardNum() << " " << myDeck[i].getCardSuit() << endl;
    }
    cout << "Print Deck is done\n" << endl;
}

Card Deck::giveCard(){
    Card card = myDeck[0];
    usedDeck.push_back(card);
    myDeck.erase(myDeck.begin());
    setCount(card);
    return card;
}

long int Deck::getDeckSize() const {
    return myDeck.size();
}

void Deck::setCount(Card curCard){
    int cardValue = curCard.getCardValue();
//    cout << "Current card value = " << cardValue << endl;
    if(cardValue >= 10)
        countingCard--;
    else if(cardValue >= 2 && cardValue <= 6)
        countingCard++;
    
//    cout << "current count = " << countingCard << endl;
}

int Deck::getCount() const{
    return countingCard;
}

int Deck::getNumOfDeck() const {
    return numOfDeck;
}
