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

//using namespace std;

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
        
        player.playerDecisionAutomation(player, dealer, deck1);
//        player.playerDecision(player, deck1);
//
//        if(player.playerDecisionAutomation(player, dealer, deck1)){
////        if(player.playerDecision(player, deck1)){
//            cout << "Player's hand is " << player.getValue() << endl;
//        }
//        else{
//            cout << "Player's hand exceeds 21.\n";
//        }
        cout << endl;
        dealer.dealerDecision(deck1);
//        if(dealer.dealerDecision(deck1)){
//            cout << "Dealer has 17 - 21\n";
//        }
//        else{
//            cout << "Dealer busts\n";
//        }
        
        dealer.game(player);
        cout << "Done game? (y/n)\n\n";
        //        cin >> input;
        cout << "================================\n";
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

/*
bool playerDecision(Player &playerObj, Deck &deckobj){
    char input;
    
    while(playerObj.getValue() < 22){
        playerObj.printMyHand();
        do{
            cout << "Please input 'h' or 's'.\n";
            cout << "Hit or stand? (h/s) ";
            cin >> input;
        }while(input != 'h' && input != 's');
        
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

bool playerDecisionAutomation(Player &playerObj, Dealer &dealerObj, Deck &deckobj){
    char input;
    
    if(playerObj.getValue() == 21){
        cout << "BlackJack 21\n";
        return true;
    }
    
    while(playerObj.getValue() <= 21){
        playerObj.printMyHand();
        input = 's';
        if(playerObj.getValue() >= 9 && playerObj.getValue() <= 11){
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
        else{
            input = 's';
        }
        
        
        if(input == 'h'){
            playerObj.hit(deckobj);
        }
        else if(input == 'd'){
            playerObj.hit(deckobj);
            return true;
        }
        else{
            playerObj.stand();
            cout << endl;
            return true;
        }
    }
    
    return false;
}
*/
