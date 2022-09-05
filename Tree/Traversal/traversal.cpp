#include <iostream>
#include <stack>
#include <queue>

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
Node* buildTree() {
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
 * First we add the root to the stack, then;
 *  
 * 1. Visit current node on top of the stack
 * 2. Add right node to stack (if exist)
 * 3. Add left node to stack (if exist)
 * 4. Repeat until stack is empty
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

/**
 * Inorder 
 * 
 * Checks if current node is valid, if true:
 *  - add it to the stack, and set the currude to the left child
 * If it is not a valid node:
 *  - get the node that is on top of the stack
 *  - visit, and set the current node to the right child
 * 
 * Repeat until stack is empty
 * 
 * @param node root node
 */

void inorder(Node* node){
    while(node || !nStack.empty()){
        if(node){ 
            //Node is pushed to the stack and we change the node to the left child
            nStack.push(node);
            node = node->left;
        }else{
            //No left node is foud so we visit the last node on stack

            node = nStack.top(); nStack.pop();

            //Visit
            cout << " " << node->ID;

            //Then go right 
            node = node->right;
        }
    }
}

void postorder(Node *node){
    if(node){
        nStack.push(node);
    }
    
    while(!nStack.empty()){
        node = nStack.top();

        if(node->left && !node->left->visit){
            nStack.push(node->left);
        }else if (node->right && !node->right->visit){
            nStack.push(node->right);
        }else{
            //Visit
            cout << " " << node->ID;
            node->visit = true;
            nStack.pop();
        }
        
    }
}


void levelorder(Node *node){

}




int main(){


    Node *root = buildTree();

    cout << "NODE ROOT: " << root->ID << endl;

    postorder(root);

    return 0; 
}