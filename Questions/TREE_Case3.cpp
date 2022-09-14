#include <iostream>
#include <cstdlib>           //  (s)rand
using namespace std; 


struct Node
{
    char ID;     
    int level;   
    Node *left;  
    Node *right; 
    Node()
    {
        ID = '-';
        level = 0;
        left = right = nullptr;
    }
};

Node* gRoot = nullptr;
int gNumber = 65; //Ascii code 


/**
 *  Rekursiv funksjon som (om mulig) genererer en node
 *  og KANSKJE dets venstre og/eller høyre subtre.
 *
 *  @param    depth        -  Aktuell (dybde)nivå i treet
 *  @param    probability  -  Sannsynlighet for å lage subtre
 *  @return   Peker til det genererte (sub)treet
 */
Node* generate(const int depth, const int probability) {
    Node* rot = nullptr;                   //  Peker til det som returneres.
                                           //  NB: Initieres til 'nullptr'!
    if (depth > 0) {                       //  Kan fortsatt legge til et nivå:
        if (rand() % 100 < probability) {  //  Trukket tall i rett intervall:
            rot = new Node;                //  Lager en ny node.
            rot->left = generate(depth-1, probability); //Lager evt v.subtre.
            rot->ID = static_cast <char> (gNumber++);  //  Legger inn egen ID.
            rot->right = generate(depth-1, probability); //Lager evt h.subtre.
        }
    }
    return rot;                     //  Returnerer generert tre eller nullptr.
}

void visit(Node* node){
    cout << node->ID << ": level " << node->level << endl;
}

void traverse(Node* node){
    if(node){
        traverse(node->left);
        visit(node);
        traverse(node->right);

    }
}

//TASKS 

void setLevel(Node*node){
    if(node){
        if(node->left) node->left->level = node->level + 1;
        if(node->right) node->right->level = node->level + 1;
        setLevel(node->left);
        setLevel(node->right);
    }
}






/**
 *  Main Program:
 */
int main() {
    int sumLevel = 0, amount = 0;  
    char ch;

    srand(0);                   
    cout << "\nNodes in the tree3:\n";
    gRoot = generate(5, 80);     
    traverse(gRoot);
    cout << "\n\nSet level...\n";
    cin >> ch;
    setLevel(gRoot);
    traverse(gRoot);

    return 0;
}
