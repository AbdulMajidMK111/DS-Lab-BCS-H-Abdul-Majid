#include <iostream>
using namespace std;

class Node {
public:
    int price;
    int height;
    Node* left;
    Node* right;

    Node(int p) 
    {
        price = p;
        height = 1;
        left = right = NULL;
    }
};

class AVLTree {
private:
    Node* root = NULL;

    int height(Node* n) 
    {
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n) 
    {
        return n ? height(n->left) - height(n->right) : 0;
    }

    int max(int a, int b) 
    {
        return (a > b ? a : b);
    }

    Node* rotateRight(Node* y) 
    {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) 
    {
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, int price) 
    {
        if (!node)
        {
            return new Node(price);
        }
        if (price < node->price)
        {
            node->left = insertNode(node->left, price);
        }
        else if (price > node->price)
        {
            node->right = insertNode(node->right, price);
        }
        else
        {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int bf = balanceFactor(node);

        if (bf > 1 && price < node->left->price)
        {
            return rotateRight(node);
        }
        if (bf < -1 && price > node->right->price)
        {
            return rotateLeft(node);
        }
        if (bf > 1 && price > node->left->price) 
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && price < node->right->price) 
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void rangeSearch(Node* node, int X, int Y) 
    {
        if (!node)
        {
            return;
        }
        if (X < node->price)
        {
            rangeSearch(node->left, X, Y);
        }
        if (node->price >= X && node->price <= Y)
        {
            cout << node->price << " ";
        }
        if (Y > node->price)
        {
            rangeSearch(node->right, X, Y);
        }
    }

public:

    void insert(int price) 
    {
        root = insertNode(root, price);
    }

    void printRange(int X, int Y) 
    {
        cout << "Prices between " << X << " and " << Y << ": ";
        rangeSearch(root, X, Y);
        cout << endl;
    }
};

int main() 
{
    AVLTree tree;

    tree.insert(50);
    tree.insert(10);
    tree.insert(80);
    tree.insert(20);
    tree.insert(30);
    tree.insert(60);
    tree.insert(70);

    int X, Y;
    cout << "Enter range (X and Y): ";
    cin >> X >> Y;

    tree.printRange(X, Y);

    return 0;
}
