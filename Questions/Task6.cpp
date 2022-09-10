/**
 * @file Task6.cpp
 * @author Kjetil K. Indrehus
 * @version 0.1
 * @date 2022-09-10
 * 
 * 
 * Complete the following task using recurtion to a binary tree. 
 * 1. Count all nodes;
 * 2. Count all pointers 
 * 3. Count all full nodes (both are not nullprt)
 * 4. Tree height 
 * 
 */

#include<iostream>

using namespace std; 

int amount = 0;


/**
 *  Binary tree node:
 */
struct Node {
    char ID;
    Node *left, *right;         
    Node(char id)  {  ID = id;  left = right = nullptr;  }
};


Node* buildTree() {
/*   TREE:                                             A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
    Node*  node[15];
    for (int i = 0; i < 15; i++)
        node[i] = new Node(static_cast <char> ('A' + i));

    node[0]->left = node[1];  node[0]->right = node[2];
    node[1]->left = node[3];  node[1]->right = node[4];
    node[2]->left = node[5];
    node[3]->left = node[6];  node[3]->right = node[7];
                                node[4]->right = node[8];
    node[5]->left = node[9];
                                node[6]->right = node[10];
    node[7]->left = node[11]; node[7]->right = node[12];
    node[8]->left = node[13];
                                node[9]->right = node[14];
    return node[0];
}


/**
 * Task 1: 
 * @brief Count all nodes in the tree. 
 * 
 * @param node given node
 * @return int returns the amount of nodes in the tree
 */

int nodes(Node* node){
    if(node){
        return 1 + nodes(node->left) + nodes(node->right);
    }
    return 0; // no node 
}


/**
 * Task 2: 
 * @brief Count all pointers that is not null. 
 * 
 * @param node given node
 * @return int return the amount of pointers that point to a node
 */

int pointerCount(Node* node){
    if(node){
        if(node->left && !node->right){
            return 1 + pointerCount(node->left);
        }
        if(node->right && !node->left){
            return 1 + pointerCount(node->right);
        }
        if(node->right && node->left){
            return 2 + pointerCount(node->left) + pointerCount(node->right); 
        }
    }
    return 0; //no pointer 
}


/**
 * Task 3: 
 * @brief Count all full nodes in a binary tree 
 * 
 * @param node the given node
 * @return int returns the height of the node
 */

int fullNodes(Node* node){
    if(node){
        if(node->left && node->right){
            return 1 + fullNodes(node->left) + fullNodes(node->right);
        }
    }
    return 0; // no node or not full
}


/**
 * Task 4:
 * @brief Find the height of the binary tree using recursion.
 * 
 * @param node node given
 * @return int returns the heigt of the node
 */

int height(Node* node){
    if(!node){
        return 0; 
    }

    int left = height(node->left); // Height from the left node
    int right = height(node->right); // Height ftom the right node

    //Return the biggest one + 1
    if(left > right){
        return 1 + left;
    }
    return 1 + right;
}


int main(){
    Node* head = buildTree();

    cout << "AMOUNT OF NODES: "<<nodes(head)<< endl;
    cout << "AMOUNT OF POINTERS: " << pointerCount(head) << endl;
    cout << "AMOUNT OF FULL NODES: " << fullNodes(head) << endl;
    cout << "HEIGHT OF THE THREE: " << height(head) << endl;


    return 0;
}