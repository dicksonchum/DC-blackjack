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

#include "Deck.hpp"
#include "Player.hpp"
//#include "Hand.hpp"
#include "Dealer.hpp"
//#include "Card.hpp"
//#include "Table.hpp"

void printMenu();
void promptReadPlayer(string&, double&);
void promptReadPlayerName(string&, char&);
void initGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj);

int main() {
    string playerName = "Jon";
    double account = 10;
    string change;
    
    bool done = false;
    
    int numOfGame = 0;
    int numOfDeck = 0;
    int mode = 0;
    char input;
    srand((unsigned)time(NULL));
    
    do{
        cout << "How many decks of cards do you want to use? ";
        cin >> numOfDeck;
    }while(numOfDeck < 1);
    
    Deck deck1(numOfDeck);
    promptReadPlayer(playerName, account);
    Player player;
    player.setName(playerName);
    player.setAccount(account);
    Dealer dealer;
    dealer.setName("Dealer");
    dealer.setAccount(10000);
    
    do{
        cout << "This is a Blackjack simulator.\n";
        cout << "There are two modes on this game.\n";
        cout << "1. One is game mode, where player can make their own decision on hit or stand.\n";
        cout << "2. Two is automation mode, where the program will automate player's decision with basic Blackjack strategy.\n\n";
        cout << "Select game mode, 1 or 2.  Mode: ";
        cin >> mode;
        cout << "=========================================================\n";
    }while(mode != 1 && mode != 2);
    
    while(!done){
        // check if deck has enough card;
        if(deck1.getDeckSize() < 15){
            cout << "Deck is less than 15\n";
            cout << "Size = " << deck1.getDeckSize() << endl << endl;
            cout << "Num of Games = " << numOfGame;
            cout << "\nPlayer wins = " << player.numOfWin();
            cout << "\nDealer wins = " << dealer.numOfWin();
            cout << "\nDraw = " << numOfGame - player.numOfWin() - dealer.numOfWin() << endl;
            break;
        }
        
        initGame(player, dealer, deck1);
        
        
        // playerDecisionAutomation will automate player's decision based on basic Blackjack Strategy
        // playerDecision will allow player to decide whether to hit or stand
        if(mode == 1)
            player.playerDecision(player, deck1);
        else if(mode == 2)
            player.playerDecisionAutomation(player, dealer, deck1);
        else{
            cout << "Mode != 1 or 2.   *ERROR*\n";
            break;
        }
        
        cout << endl;
        dealer.dealerDecision(deck1);
        
        dealer.game(player);
        cout << "Done game? (y/n)\n\n";
//        cin >> input;
        cout << "=========================================================\n";
        input = 'n';
        if (input == 'y')
            done = true;
        
        numOfGame++;
        
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
    playerObj.setMyHand(deckObj);
    dealerObj.setMyHand(deckObj);
    playerObj.dealSecondCard(deckObj);
    dealerObj.printDealerHand();
}
