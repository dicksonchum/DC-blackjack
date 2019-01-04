//
//  main.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

//#include "Table.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Dealer.hpp"
//#include "Card.hpp"

using namespace std;

void printMenu();
void promptReadPlayer(string&, double&);
void promptReadPlayerName(string&, char&);
void initGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj);
bool playerDecision(Player &playerObj, Deck &deckobj);

int main() {
    //    Table table1;
    
    string playerName = "jon";
    double account =10;
    string change;
    bool done = false;
    
    char input;
    srand((unsigned)time(NULL));
    Deck deck1;
    //    promptReadPlayer(playerName, account);
    Player player;
    player.setName(playerName);
    player.setAccount(account);
    Dealer dealer;
    dealer.setName("Dealer");
    dealer.setAccount(10000);
    
    while(!done){
        // check if deck has enough card;
        if(deck1.getDeckSize() < 10){
            cout << "deck is less than 10\n";
            cout << "size = " << deck1.getDeckSize() << endl;
        }
        
        // player get one card, dealer get one, then player get second card
        // check if player wanna hit or stand
        // dealer gets second card, check if its above 17
        // loop until dealer is >17
        // if above 17, check if dealer or player win
        // if below, hit, loop
        
        
        
        initGame(player, dealer, deck1);
        if(playerDecision(player, deck1)){
            cout << "Player's hand is " << player.getValue() << endl;
        }
        else{
            cout << "Player's hand exceeds 21.\n";
        }
        
        if(dealer.dealerDecision(deck1)){
            cout << "Dealer has 17 - 21\n";
        }
        
        dealer.game(player);
        cout << "Done game? (y/n)\n\n";
        //        cin >> input;
        input = 'n';
        if (input == 'y')
            done = true;
        
        
        /*
         printMenu();
         cout << "Select an option: ";
         cin >> input;
         // Input for player
         
         switch(input){
         case 'i': {
         promptReadPlayer(playerName, account);
         Player po;
         po.setName(playerName);
         po.setAccount(account);
         cout << playerName << endl;
         break;
         }
         case 'd': {
         
         break;
         }
         case 's': {
         
         break;
         }
         case 'p': {
         
         break;
         }
         case 'r': {
         
         break;
         }
         case 'f': {
         
         break;
         }
         case 'z': {
         cout << "Print filled deck\n";
         deck1.printDeck();
         break;
         }
         case 'q': {
         // Stop application.
         done = true;
         break;
         }
         }
         */
    }
    
    return 0;
}

void printMenu(){
    // Print user for input option
    cout << endl;
    cout << "===============================================" << endl;
    cout << "Options" << endl;
    cout << " i: Insert new player" << endl;
    cout << " d: Remove a player" << endl;
    cout << " s: Search for a player" << endl;
    cout << " p: Print all player" << endl;
    cout << " r: Print a range of player" << endl;
    cout << " f: Read player data from file" << endl;
    cout << " z: Print deck" << endl;
    cout << " q: Quit application" << endl;
    cout << "===============================================" << endl;
}

void promptReadPlayer(string& fullName, double& account){
    string firstName;
    string lastName;
    string change;
    
    
    // simply get name here and create Player object in Table.cpp
    
    
    do{
        cout << "Enter Your First Name: ";
        cin >> firstName;
        cout << "Enter Your Last Name: ";
        cin >> lastName;
        cout << "Enter Your Buy In: ";
        cin >> account;
        
        fullName = firstName + " " + lastName;
        
        cout << "\nName: " << fullName << endl
        << "Account: " << account << endl << endl;
        
        cout << "Is the info correct? (y/n) ";
        cin >> change;
        
        while(change != "y" && change != "n"){
            cout << "Please enter y or n." << endl;
            cout << "Is the info correct? (y/n) ";
            cin >> change;
            cout << endl;
        }
        if(change == "n"){
            cout << "Please enter your info again.\n";
        }
        else{
            Player Player(fullName, account);
        }
    } while(change == "n");
}

void initGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj){
    // player get one card, dealer get one, then player get second card
    // check if player wanna hit or stand
    // dealer gets second card, check if its above 17
    // loop until dealer is >17
    // if above 17, check if dealer or player win
    // if below, hit, loop
    
    //
    //    player.setMyHand(deck1);
    //    player.printMyHand();
    //    dealer.setDealerHand(deck1);
    //    dealer.printHand();
    
    playerObj.setMyHand(deckObj);
    dealerObj.setMyHand(deckObj);
    playerObj.hit(deckObj);
    //    playerObj.printMyHand();
    dealerObj.printHand();
    
}

bool playerDecision(Player &playerObj, Deck &deckobj){
    char input;
    
    while(playerObj.getValue() < 22){
        playerObj.printMyHand();
        input = 's';
        //        do{
        //            cout << "Please input 'h' or 's'.\n";
        //            cout << "Hit or stand? (h/s) ";
        //            cin >> input;
        //        }while(input != 'h' && input != 's');
        
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
