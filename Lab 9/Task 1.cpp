#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k)
    {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
public:
    Node* root = NULL;

    int height(Node* n)
    {
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n)
    {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rotateRight(Node* y)
    {
        cout << "Rotation: Right" << endl;
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x)
    {
        cout << "Rotation: Left" << endl;
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int key)
    {
        if (!node)
        {
            cout << "Inserting " << key << endl;
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int bf = balanceFactor(node);

        cout << "BF(" << node->key << ")=" << bf << endl;

        if (bf > 1 && key < node->left->key)
        {
            return rotateRight(node);
        }

        if (bf < -1 && key > node->right->key)
        {
            return rotateLeft(node);
        }

        if (bf > 1 && key > node->left->key)
        {
            cout << "Rotation: LR" << endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && key < node->right->key)
        {
            cout << "Rotation: RL" << endl;
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValue(Node* n)
    {
        while (n->left)
        {
            n = n->left;
        }
        return n;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (!root)
        {
            return root;
        }

        cout << "Deleting " << key << endl;

        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (!root->left || !root->right)
            {
                Node* temp = root->left ? root->left : root->right;

                if (!temp)
                {
                    temp = root;
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }

                delete temp;
            }
            else
            {
                Node* temp = minValue(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root)
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int bf = balanceFactor(root);

        cout << "BF(" << root->key << ")=" << bf << endl;

        if (bf > 1 && balanceFactor(root->left) >= 0)
        {
            return rotateRight(root);
        }

        if (bf > 1 && balanceFactor(root->left) < 0)
        {
            cout << "Rotation: LR" << endl;
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (bf < -1 && balanceFactor(root->right) <= 0)
        {
            return rotateLeft(root);
        }

        if (bf < -1 && balanceFactor(root->right) > 0)
        {
            cout << "Rotation: RL" << endl;
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void insertKey(int k)
    {
        root = insert(root, k);
        cout << "Tree Height: " << height(root) << endl << endl;
    }

    void deleteKey(int k)
    {
        root = deleteNode(root, k);
        cout << "Tree Height After Delete: " << height(root) << endl << endl;
    }

    void inorder(Node* r)
    {
        if (!r)
        {
            return;
        }
        inorder(r->left);
        cout << r->key << " ";
        inorder(r->right);
    }
};

int main()
{
    AVL tree;

    tree.insertKey(40);
    tree.insertKey(50);
    tree.insertKey(90);
    tree.insertKey(10);
    tree.insertKey(20);
    tree.insertKey(70);
    tree.insertKey(60);
    tree.insertKey(80);

    tree.deleteKey(60);
    tree.deleteKey(20);
    tree.deleteKey(40);

    cout << "Final Tree (Inorder): ";
    tree.inorder(tree.root);

    return 0;
}
