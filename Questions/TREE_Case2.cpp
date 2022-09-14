/**
 * @file TREE_Case2.cpp
 * @author Kjetil K. Indrehus
 * @version 0.1
 * @date 2022-09-12
 */

#include <iostream>
#include <iomanip> //  setw
#include <cstdlib> //  (s)rand
using namespace std;

struct Node
{
    int value;    // value of the node
    char ID;      // Name as a char
    int sum;      // value of all children + the value of the node
    Node *left;   // Point right node
    Node *right;  // Point left node
    Node *parent; // Points to parant
};

Node *gRoot = nullptr;
int gNumber = 0;

void visit(Node *node)
{
    cout << "ID: " << node->ID << " , Value: " << node->value << ", SUM: " << node->sum;
    if (node->parent)
        cout << ", Parent: " << node->parent->ID;
    cout << "\n";
}

void traverse(Node *node)
{
    if (node)
    {
        traverse(node->left);
        visit(node);
        traverse(node->right);
    }
}

/**
 *  Rekursiv funksjon som (om mulig) genererer en node
 *  og KANSKJE dets venstre og/eller høyre subtre.
 *
 *  @param    depth        -  Aktuell (dybde)nivå i treet
 *  @param    probability  -  Sannsynlighet for å lage subtre
 *  @return   Peker til det genererte (sub)treet
 */
Node *generate(const int depth, const int probability)
{
    Node *rot = nullptr;

    if (depth > 0)
    {
        if (rand() % 100 < probability)
        {
            rot = new Node;
            rot->left = generate(depth - 1, probability);

            rot->value = ++gNumber;
            rot->ID = static_cast<char>('A' - 1 + gNumber);
            rot->sum = 0;
            rot->parent = nullptr;

            rot->right = generate(depth - 1, probability);
        }
    }
    return rot;
}

// TASKES

void setSum(Node *node)
{
    if (node)
    {
        setSum(node->left);
        setSum(node->right);
        node->sum = node->value;
        if (node->left)
            node->sum += node->left->value;
        if (node->right)
            node->sum += node->right->value;
    }
}

void setParent(Node *node)
{
    if(node){
        if(node->left) node->left->parent = node;
        if(node->right) node->right->parent = node;
        setParent(node->left);
        setParent(node->right);
    }
}





/**
 *  mainProgram
 */
int main()
{
    char ch;

    srand(0); // Random init

    cout << "\nNodes in the start tree:\n";

    gRoot = generate(5, 80);
    traverse(gRoot); // Show tree

    cout << "\n\nPress any button to set Sum...\n";
    cin >> ch;

    setSum(gRoot);
    cout << "\n\nTree after sum set\n";
    traverse(gRoot);
    cin >> ch;
    cout << "\n\nPress any button to set parent...\n";

    setParent(gRoot);
    cout << "\n\nTree after set parent\n";
    traverse(gRoot);

    cout << "\n\n";
    return 0;
}