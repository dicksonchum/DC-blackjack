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

void promptReadPlayer(string&, double&);
void promptReadPlayerName(string&, char&);
void initGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj);
void doneGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj, int numGame);

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
            break;
        }
        cout << "Game " << numOfGame + 1 << endl;
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
        if(mode == 1){
            cout << "Done game? (y/n)\n\n";
            cin >> input;
            if (input == 'y'){
                done = true;
            }
        }
        else{
            input = 'n';
        }
        
        cout << "=========================================================\n";
        
        numOfGame++;
    }
    
    doneGame(player, dealer, deck1, numOfGame);
    
    return 0;
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
        cout << "Enter Your Buy In (Betting has not implemented) : ";
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
//    playerObj.setBet();
    playerObj.setMyHand(deckObj);
    dealerObj.setMyHand(deckObj);
    playerObj.dealSecondCard(deckObj);
    dealerObj.printDealerHand();
}

void doneGame(Player &playerObj, Dealer &dealerObj, Deck &deckObj, int numGame){
    cout << "\nDone Game\n";
    cout << "Size = " << deckObj.getDeckSize() << endl << endl;
    cout << "Num of Games = " << numGame;
    cout << "\nPlayer wins = " << playerObj.numOfWin();
    cout << "\nDealer wins = " << dealerObj.numOfWin();
    cout << "\nDraw = " << numGame - playerObj.numOfWin() - dealerObj.numOfWin() << endl;
}
