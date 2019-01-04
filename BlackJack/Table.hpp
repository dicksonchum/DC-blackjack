//
//  Table.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Player.hpp"

//using namespace std;

class Table{
    
public:
    Table();
//    why this has string?
//    Table(Player po, int position);
    ~Table();
    
    void insert(string name, double ac);
    void remove(string name);
    
    
    
private:
    Node* root;
    Node* tempRoot;
    Node* child;
//    Player table[4];
    
};




#endif /* Table_hpp */
