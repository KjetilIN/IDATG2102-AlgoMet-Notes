/**
 *   Hovedrisset til oblig nr 2.
 *
 *   For programmets funksjonalitet se:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */

#include <iostream>
using namespace std;

/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node
{
    int ID;             //  Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; //  Peker til begge subtrærne (evt. 'nullptr').
    Node(int id)
    {
        ID = id;
        left = right = nullptr;
    }
};

void byggTre();
void skrivAnnenhverBladnode(Node *node); //  Oppgave A
int tellStorre(Node *node, int verdi);   //  Oppgave B
bool storreEnnBarna(Node *node);         //  Oppgave C

Node *root = nullptr; ///<  Peker til treet rot.
bool skrev = true;    ///<  Om forrige bladnode ble skrevet eller ei.

/**
 *  Bygger et tre for å kunne teste de ulike funksjonene.
 */
void byggTre()
{
    Node *p[19];
    for (int i = 0; i < 19; i++)
        p[i] = new Node(19 - i);
    root = p[0]; //  Bygger treet:          //
    p[0]->left = p[1];
    p[0]->right = p[2]; //          19             //
    p[1]->left = p[3];
    p[1]->right = p[4]; //       /       \         //
    p[2]->left = p[5];
    p[2]->right = p[6]; //     18        17        //
    p[3]->left = p[7];
    p[3]->right = p[8];  //    /   \     /   \      //
    p[4]->left = p[9];   //  16     15  14    13    //
    p[5]->right = p[10]; //  / \    /     \   / \   //
    p[6]->left = p[11];
    p[6]->right = p[12]; // 12 11  10      9 8   7  //
    p[9]->left = p[13];
    p[9]->right = p[14];  //       / \     /   \     //
    p[10]->left = p[15];  //      6   5   4     3    //
    p[11]->right = p[16]; //         /     \         //
    p[14]->left = p[17];  //        2       1        //
    p[15]->right = p[18];
}

/**
 *  OPPGAVE A:
 *     Skriver annenhver bladnode startende fra høyre, og med den andre noden.
 *
 *   @param   node  -  Noden som skal besøkes.
 */
void skrivAnnenhverBladnode(Node *node)
{
    if (node)
    {
        if (!node->left && !node->right)
        { // Noden har ingen blad -> ergo en blad node
            if (skrev)
            {
                // Skriv ut node ID og ikkje skriv neste bladnode
                cout << node->ID << " ";
                skrev = false;
            }
            else
            {
                // Skriver ikkje ut bladnoden, men gir besjed om at neste skal skrivest
                skrev = true;
            }
        }
        else
        {
            // Kaller seg rekursivt fra høyre til venstre
            skrivAnnenhverBladnode(node->right);
            skrivAnnenhverBladnode(node->left);
        }
    }

    //  LAG INNMATEN  (se oppgaveteksten)
}

/**
 *  OPPGAVE B: Finner antall noder under 'node' STØRRE ENN enn 'verdi'.
 *
 *  @param   node   -  Noden som skal besøkes/undersøkes
 *  @param   verdi  -  verdien det skal sjekkes om nodens ID er større enn
 *  @return  Antall noder under 'node' med 'ID' STØRRE ENN 'verdi'
 */
int tellStorre(Node *node, int verdi)
{
    int current = node && node->ID > verdi ? 1 : 0;                                          // Tester om noden er større en verdien
    int left = node->left && node->left->ID > verdi ? tellStorre(node->left, verdi) : 0;     // Kaller på tellStorre kun om vedrien til venstre er høyere enn verdi
    int right = node->right && node->right->ID > verdi ? tellStorre(node->right, verdi) : 0; // Kaller på tellStorre kun om vedrien til venstre er høyere enn verdi
    return current + left + right;                                                           // Reuturnerer resultatet
}

/**
 *  OPPGAVE C: Finner ut om alt under 'node' er mindre dens 'ID'.
 *
 *  @param   Node  -  Noden som skal besøkes/undersøkes
 *  @return  Returnerer om 'node's ID er større enn barnas eller ei
 */
bool storreEnnBarna(Node *node)
{
    if (node)
    {
        bool leftIsSmaller = (!node->left || (node->left->ID < node->ID));
        bool rightIsSmaller = (!node->right || (node->right->ID < node->ID));

        if (leftIsSmaller && rightIsSmaller)
        {
            return storreEnnBarna(node->left) && storreEnnBarna(node->right);
        }
        return false; 
    }
    return true;
    
}

/**
 *  Hovedprogrammet:
 */
int main()
{
    int verdi; //  Innlest og ønsket verdi fra brukeren.

    byggTre();

    cout << "\n\nTester Oppgave A:\n"
         << "\tAnnenhver bladnode i treet:   ";
    skrivAnnenhverBladnode(root);

    cout << "\n\n\n\nTester Oppgave B:\n"
         << "\tNoder storre enn verdien: ";
    cin >> verdi;
    cout << "\tAntall noder storre enn " << verdi << ": "
         << tellStorre(root, verdi);

    cout << "\n\n\n\nTester Oppgave C:\n"
         << "\tEnhver foreldre er " << ((storreEnnBarna(root)) ? "" : "IKKE ")
         << "storre enn barna sine!\n";

    root->left->right->ID = 20; //  Endrer verdien 15 til 20.
    cout << "\tEnhver foreldre er " << ((storreEnnBarna(root)) ? "" : "IKKE ")
         << "storre enn barna sine!\n\n";
    return 0;
}