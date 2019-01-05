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

Deck::Deck(){
    fillDeck();
    shuffleDeck();
}

// Don't really need custom made copy constructor because there's no dynamic mem allocation
Deck::Deck(const Deck& deckObj){
    
}

Deck::~Deck(){

}

void Deck::fillDeck(){
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
            for(k = 0; k < numOfDeck; k++){
                myDeck.push_back(Card(card, j));
                count++;
            }
        }
    }
    if(count == 52 * numOfDeck){
        cout << "Filled " << numOfDeck << " deck\n";
    }
    
    // Printing before shuffle
//    for(vector<Card>::iterator it = myDeck.begin(); it != myDeck.end(); it++){
//        cout << myDeck[i].getCardNum() << " " << myDeck[i].getCardSuit() << endl;
//    }
    
}

void Deck::shuffleDeck(){
    int i = 0;
    cout << "Shuffle begins\n";
    random_shuffle(myDeck.begin(), myDeck.end(), randomNum);
    cout << "Shuffle is done\n";
    // Printing after shuffle
    for(i = 0; i < 52; i++){
        cout << myDeck[i].getCardNum() << " " << myDeck[i].getCardSuit() << endl;
    }
    cout << "Print is done\n" << endl;
}

void Deck::printDeck(){
    int i = 0;
    cout << "Size : " << myDeck.size() << endl;
    for(i = 0; i < myDeck.size(); i++){
        cout << myDeck[i].getCardNum() << " " << myDeck[i].getCardSuit() << endl;
    }
}

Card Deck::giveCard(){
    Card card = myDeck[0];
    usedDeck.push_back(card);
    myDeck.erase(myDeck.begin());
    return card;
}

long int Deck::getDeckSize() const {
    return myDeck.size();
}
