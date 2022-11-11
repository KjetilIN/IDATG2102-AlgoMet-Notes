#include <iostream>

using namespace std;

struct Node {
    int ID; // Nodens ID/key/nøkkel/navn (et tall).
    int avstand; // Nodens "vertikale avstand" ift. rota (brukes kun i 3A).
    Node *left, *right; // Referanse til begge subtrærne (evt. 'nullptr/NULL').
    Node(int id) { ID = id; left = right = nullptr; avstand = 0; }
};


Node* gRoot = nullptr; //Root peker



/**
 * Setter avstanden fra "sentert"
 * Pluss en om høyre barn
 * Minus en om venstre barn
 * 
 * Skal brukes rekrusivt 
 * 
 * @param t node 
 */

void settVertikalAvstand(const Node* t){
    if(t){
        //Setter avstand fot venstre node og høyre noode 
        if(t->left) t->left->avstand = t->avstand - 1;
        if(t->right) t->right->avstand = t->avstand + 1;

        settVertikalAvstand(t->left);
        settVertikalAvstand(t->right);
    }

}


/**
 * Printer om en node har ingen søsken.
 * 
 * Rekrusivt kall. 
 * 
 * @param t aktuell node
 */

void skrivNoderUtenSosken(const Node* t){
    //Base case: noden er root
    if(t == gRoot) cout << t->ID << ", "; 

    if(t->left && !t->right){
        cout << t->left->ID << ", ";
        skrivNoderUtenSosken(t->left);
    }else if (!t->left && t->right){
        cout << t->right->ID << ", ";
        skrivNoderUtenSosken(t->right);
    }else{
        if(t->left) skrivNoderUtenSosken(t->left);
        if(t->right) skrivNoderUtenSosken(t->right);
    }
    

}




//Build a tree for testing 
Node* buildTree() {
/*   Builds:                                     A
                                              /             \
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
        noder[i] = new Node(i);

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



void printNodeDistanse(const Node* node){
    if(node){
        printNodeDistanse(node->left);
        printNodeDistanse(node->right);
        cout << "\t" << node->ID << ": AVSTAND = " << node->avstand << endl;
        
    }

}


int main(){



    gRoot = buildTree();

    cout << "SETT DISTANSE OPPGAVE: \n\n";

    cout << "BEFORE:" << endl;
    printNodeDistanse(gRoot);
    cout << "\n\n";

    cout << "AFTER:" << endl;

    settVertikalAvstand(gRoot);
    printNodeDistanse(gRoot);

    cout << "PRINT OM INGEN SØSKEN: \n\n";

    skrivNoderUtenSosken(gRoot);


    return 0;
}