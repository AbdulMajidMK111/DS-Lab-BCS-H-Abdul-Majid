#include <iostream>
using namespace std;

class Node {
public:
    int severity;
    int height;
    Node* left;
    Node* right;

    Node(int s)
    {
        severity = s;
        height = 1;
        left = NULL;
        right = NULL;
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
        return a > b ? a : b;
    }

    Node* rotateRight(Node* y)
    {
        cout << "Right Rotataion" << endl;
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
        cout << "Left Rotation" << endl;
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, int severity)
    {
        if (!node)
        {
            cout << "Inserted: " << severity << endl;
            return new Node(severity);
        }

        if (severity < node->severity)
        {
            node->left = insertNode(node->left, severity);
        }
        else if (severity > node->severity)
        {
            node->right = insertNode(node->right, severity);
        }
        else
        {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int bf = balanceFactor(node);

        if (bf > 1 && severity < node->left->severity)
        {
            cout << "Unbalanced: LL" << endl;
            return rotateRight(node);
        }

        if (bf < -1 && severity > node->right->severity)
        {
            cout << "Unbalanced: RR" << endl;
            return rotateLeft(node);
        }

        if (bf > 1 && severity > node->left->severity)
        {
            cout << "Unbalanced: LR" << endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && severity < node->right->severity)
        {
            cout << "Unbalanced: RL" << endl;
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minNode(Node* node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int severity)
    {
        if (!node)
        {
            cout << "Not found" << endl;
            return NULL;
        }

        if (severity < node->severity)
        {
            node->left = deleteNode(node->left, severity);
        }
        else if (severity > node->severity)
        {
            node->right = deleteNode(node->right, severity);
        }
        else
        {
            cout << "Deleted: " << severity << endl;

            if (!node->left || !node->right)
            {
                Node* temp = node->left ? node->left : node->right;

                if (!temp)
                {
                    temp = node;
                    node = NULL;
                }
                else
                {
                    *node = *temp;
                }

                delete temp;
            }
            else
            {
                Node* temp = minNode(node->right);
                node->severity = temp->severity;
                node->right = deleteNode(node->right, temp->severity);
            }
        }

        if (!node)
        {
            return NULL;
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balanceFactor(node);

        if (bf > 1 && balanceFactor(node->left) >= 0)
        {
            cout << "Unbalanced delete: LL" << endl;
            return rotateRight(node);
        }

        if (bf > 1 && balanceFactor(node->left) < 0)
        {
            cout << "Unbalanced delete: LR" << endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && balanceFactor(node->right) <= 0)
        {
            cout << "Unbalanced delete: RR" << endl;
            return rotateLeft(node);
        }

        if (bf < -1 && balanceFactor(node->right) > 0)
        {
            cout << "Unbalanced delete: RL" << endl;
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

public:

    void insertSeverity(int severity)
    {
        root = insertNode(root, severity);
        cout << "Tree height: " << height(root) << endl;
        printHighestSeverity();
        cout << endl;
    }

    void dischargeSeverity(int severity)
    {
        root = deleteNode(root, severity);
        cout << "Tree height: " << height(root) << endl;
        printHighestSeverity();
        cout << endl;
    }

    void printHighestSeverity()
    {
        if (!root)
        {
            cout << "No patients" << endl;
            return;
        }

        Node* temp = root;
        while (temp->right)
        {
            temp = temp->right;
        }

        cout << "Highest severity: " << temp->severity << endl;
    }
};

int main()
{
    AVLTree tr;

    tr.insertSeverity(30);
    tr.insertSeverity(40);
    tr.insertSeverity(70);
    tr.insertSeverity(10);
    tr.insertSeverity(30);
    tr.insertSeverity(50);
    tr.insertSeverity(60);
    tr.insertSeverity(90);

    tr.dischargeSeverity(40);
    tr.dischargeSeverity(50);
    tr.dischargeSeverity(70);

    return 0;
}
