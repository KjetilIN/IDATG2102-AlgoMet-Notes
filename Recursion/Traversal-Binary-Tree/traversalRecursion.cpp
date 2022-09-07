#include<iostream>

using namespace std;


/**
 *  Binary tree node:
 */
struct Node {
    char ID;
    Node *left, *right;         
    Node(char id)  {  ID = id;  left = right = nullptr;  }
};

//Display the ID of the node, when we visit
void visit(Node* node){
    cout << " " << node->ID;
}

/**
 *  Build a binary tree for testing
 *  @return root node of tree
 */
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


void inorder(Node* node){
    if(node){
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
}

void preorder(Node* node){
    if(node){
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node* node){
    if(node){
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
}



int main(){

    Node* root = buildTree();

    cout << "\nInorder: "; inorder(root); cout << "\n";
    cout << "\nPreorder: "; preorder(root); cout << "\n";
    cout << "\nPostorder: "; postorder(root); cout << "\n";

    return 0;
}