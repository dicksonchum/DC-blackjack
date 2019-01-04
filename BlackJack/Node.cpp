//
//  Node.cpp
//  BlackJack
//
//  Created by Dickson Chum on 2018-09-06.
//  Copyright © 2018 Dickson Chum. All rights reserved.
//

#include "Node.hpp"

Node::Node(){
    parent = NULL;
    child = NULL;
}

Node::~Node(){

}

Node::Node(Player p){
    data = p;
    child = NULL;
    parent = NULL;
}

Node::Node(const Node &n){
    data = n.getData();
    child = n.child;
    parent = n.parent;
}

Player Node::getData() const{
    return data;
}

Node* Node::getChild() const{
    return child;
}

void Node::setData(Player p){
    data = p;
}

void Node::setChild(Node *newChild){
    child = newChild;
}

Node* Node::getParent() const{
    return parent;
}

void Node::setParent(Node *newParent){
    parent = newParent;
}
