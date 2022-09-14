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

using namespace std;

struct Node
{
    int ID;
    Node *left, *right;
    Node(int id, Node *left, Node *right)
    {
        ID = id;
        this->left = left;
        this->right = right;
    }
};

Node *gRoot = nullptr;

/**
 *  Print all node ID from the path:
 *  - Do not use recurtion
 *  - Call the function hoyregren : Means right-node in english
 *  - Path: Root to the right most node
 *  - If not right you can go left
 *  - Summary: find biggest value in the tree
 *
 */

void hoyreGren()
{
    Node *node = gRoot;
    while (node)
    {
        cout << node->ID << " ";
        node = (node->right) ? node->right : node->left;
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

void gren(Node *node)
{
    int id = node->ID;
    node = gRoot;
    while (node)
    {
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

void grener(Node *node)
{
    if (node)
    {
        if (!node->left && !node->right)
        {
            // If a node has no child, print the path to the child
            gren(node);
            cout << "\n";
        }
        else
        {
            // Else call the function on each child
            grener(node->left);
            grener(node->right);
        }
    }
}

// Main function for testing
int main()
{
    Node *n6, *n8, *n11a, *n11b, *n12, *n13a, *n13b,
        *n17, *n28, *n31, *n33, *n34, *n35a, *n35b, *n39;
    /*
    Bygger treet:          17
                       /        \
                      11         33
                    /    \     /    \
                   6      13 28     35
                    \    /  \ \     / \
                     8  12  13 31  34 39
                        /            /
                       11           35
    */
    n8 = new Node(8, nullptr, nullptr);
    n11b = new Node(11, nullptr, nullptr);
    n13b = new Node(13, nullptr, nullptr);
    n31 = new Node(31, nullptr, nullptr);
    n34 = new Node(34, nullptr, nullptr);
    n35b = new Node(35, nullptr, nullptr);
    n12 = new Node(12, n11b, nullptr);
    n39 = new Node(39, n35b, nullptr);
    n6 = new Node(6, nullptr, n8);
    n13a = new Node(13, n12, n13b);
    n28 = new Node(28, nullptr, n31);
    n35a = new Node(35, n34, n39);
    n11a = new Node(11, n6, n13a);
    n33 = new Node(33, n28, n35a);
    n17 = new Node(17, n11a, n33);
    gRoot = n17;

    cout << "Right path : ";
    hoyreGren(); cout << "\n\n";

    cout << "Find Node ID test :\n";

    cout << "FIND 31: "; gren(n31);   cout << '\n';       
    cout << "FIND 8: "; gren(n8);    cout << '\n';     

    cout << "Print all paths: \n";
    grener(gRoot);  


    return 0;
}
