/**
 * @file Tree_Case1.cpp
 * @author Kjetil K. Indrehus
 * @brief
 * @version 0.1
 * @date 2022-09-10
 * 
 * - Only use the given Node struct and global (gRoot).
 * - The tree is binary were the left node is bigger than the right node. 
 *
 */


#include <iostream>
#include <stack>

using namspace std; 

struct Node {
    int ID;
    Node *left, *right;         
    Node(int id, Node* left, Node* right)  {  ID = id;  this->left = left; this->right=right; }
};

Node* gRoot = nullptr; 

/**
 *  Print all node ID from the path:
 *  - Do not use recurtion
 *  - Call the function hoyregren : Means right-node in english
 *  - Path: Root to the right most node
 *  - If not right you can go left
 *  - Summary: find biggest value in the tree
 * 
 */

void hoyreGren(){
    Node* node = gRoot;
    while(node){
        cout << node->ID << " ";
        node = (node->right) ? node->right: node->left; 
    }

}

/**
 *  - Do not use recurtion
 *  - Node given is always on the tree. 
 *  - Find the node that has the given key value
 *  - The node must also point to nullptr
 *  - Summary: print the path from root to the given node.
 * 
 * @param node given node
 */

void gren(Node* node){
    int id = node->ID; 
    node = gRoot;
    while(node){
        cout << node->ID << " ";
        node = (node->ID > id) ? node->left : node->right;
    }

}


/**
 * - Use recurtion
 * - Print all paths from the root node
 * 
 * @param node given node
 */


void grener(Node* node){
    if(node){ 
        if(!node->left && !node->right){
            //If a node has no child, print the path to the child
            gren(node); cout << "\n";
        } else{
            //Else call the function on each child
            grener(node->left);
            grener(node->right);
        }
    }

}





//Main function for testing 
int main(){
    return 0; 
}
