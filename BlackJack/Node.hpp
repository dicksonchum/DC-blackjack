//
//  Node.hpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Player.hpp"

class Node {
public:
    Node();
    ~Node();
    Node(const Player p);
    Node(const Node &n);
    
    Player getData() const;
    Node* getChild() const;
    void setData(Player p);
    void setChild(Node *newChild);
    
    Node* getParent() const;
    void setParent(Node *newParent);
    
private:
    Player data;
    Node *child;
    Node *parent;
};


#endif /* Node_hpp */
