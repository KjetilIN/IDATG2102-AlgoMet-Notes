/**
 * @file TREE_Case2.cpp
 * @author Kjetil K. Indrehus
 * @version 0.1
 * @date 2022-09-12
 */

#include<iostream>

struct Node
{
    int value;     // value of the node
    char ID;        //Name as a char
    int sum;        // value of all children + the value of the node
    Node *left;     // Point right node
    Node *right;    // Point left node
    Node *parent; // Points to parant 
};

Node* gRoot = nullptr; 


//TODO: complete this and add tree basic 
void displayTree();
void setSum();
void setParent();
