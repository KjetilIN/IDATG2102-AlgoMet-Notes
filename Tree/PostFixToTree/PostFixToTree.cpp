#include <iostream>
#include <stack>


/**
 * This is the script that turnes a postfix into a tree.
 * There are included checks 
 * 
 */

using namespace std;

//Node that has no children, by default nullptr
struct Node{
    char ID;
    Node *left;
    Node *right;

    Node(char id){ID = id; left = right = nullptr;}
};



//Methods for testing

void travserPostorder(const Node* node) {
    if (node) {                          //  Peker til en reell node:
        travserPostorder(node->left);    //  Besøker venstre subtre/barn.
        travserPostorder(node->right);   //  Besøker høyre subtre/barn.
        cout << ' ' << node->ID;         //  Skriver ("besøker") seg selv.
    }
}



void travserInorder(const Node* node) {
    if (node) {                          //  Peker til en reell node:
        if (node->left) cout << '(';     //  Skriver '(' før subtreet.
        travserInorder(node->left);      //  Besøker venstre subtre/barn.
        cout << ' ' << node->ID;         //  Skriver ("besøker") seg selv.
        travserInorder(node->right);     //  Besøker høyre subtre/barn.
        if (node->right) cout << ')';    //  Skriver ')' etter subtreet.
    }
}


int main(){
    char ch; //Current char of the postfix
    Node *newNode; //The new node created
    stack<Node*> nodes; // Stack of nodes 

    cout << "Please Enter a Postfix to be parsed:\n";

    //For each char. 
    while((ch = cin.get()) != '\n'){
        //Loop until no more white space
        while(ch == ' '){ch = cin.get();}

        //Create a new node
        newNode = new Node(ch);

        //If the node is an operator, set the two top nodes on the stack to be its children.
        if(ch == '+' || ch == '*'){
            newNode->left = nodes.top(); nodes.pop(); 
            newNode->right = nodes.top(); nodes.pop(); 
        }

        //Push the new node to the stack
        nodes.push(newNode);

    }

    cout << "TREE-> INFIX check:\n";
    travserInorder(nodes.top());
    
    cout << "\n\nTREE-> POSTFIX check:\n";
    travserPostorder(nodes.top());



    return 0;
}