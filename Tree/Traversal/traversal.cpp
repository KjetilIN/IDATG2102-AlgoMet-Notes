#include <iostream>
#include <stack>

using namespace std; 


/**
 * There is a lot of diffrent ways to vist all nodes in a tree. 
 * Here are them summerized using my own words:
 * 
 * PREODER: Visit current node, then go visit left. If left has been visited, visit right.
 * 
 * INORDER: Visit the left before current node, only then visit right.
 * 
 * LEVELORDER: Visit each node from the lowest level to the top
 * 
 * @author Kjetil K. Indrehus
 *  
 */

//Node struct
struct Node {
    char ID;
    bool visit;                       
    Node *left, *right;                
    Node(char id)  {  ID = id;  left = right = nullptr;   visit = false;  }
};


stack<Node*> nStack; 

//Build a tree for testing 
Node* byggTre() {
/*   Builds:                                     A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
    Node*  noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast <char> ('A' + i));

    noder[0]->left = noder[1];  noder[0]->right = noder[2];
    noder[1]->left = noder[3];  noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];  noder[3]->right = noder[7];
                                noder[4]->right = noder[8];
    noder[5]->left = noder[9];
                                noder[6]->right = noder[10];
    noder[7]->left = noder[11]; noder[7]->right = noder[12];
    noder[8]->left = noder[13];
                                noder[9]->right = noder[14];
    return noder[0];
}




/**
 * PREORDER
 * 
 * @param node root node
 */
void preorder(Node* node) {
    if(node != nullptr){
        nStack.push(node);
        while(!nStack.empty()){
            //Get the node that is on top of the stack 
            node = nStack.top(); nStack.pop();
            //Visit
            cout << " " << node->ID; 

            //Push each child to the stack, but left will be on top
            //But first verify they exist (Only push valid nodes)
            if(node->right) nStack.push(node->right);
            if(node->left) nStack.push(node->left);
        }
        
    }
}


int main(){


    Node *root = byggTre();

    cout << "NODE ROOT: " << root->ID << endl;

    preorder(root);

    return 0; 
}