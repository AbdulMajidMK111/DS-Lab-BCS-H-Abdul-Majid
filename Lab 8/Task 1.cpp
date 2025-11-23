#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    Person* mother;
    Person* father;

    Person(string n) 
    {
        name = n;
        mother = father = nullptr;
    }
};

class FamilyTree {
private:
    Person* root;

    void printLeafNodes(Person* node) 
    {
        if (!node) 
        {
            return;
        }
        if (!node->mother && !node->father) 
        {
            cout << node->name << " ";
            return;
        }
        if (node->mother)
        {
            printLeafNodes(node->mother);
        }
        if (node->father)
        {
            printLeafNodes(node->father);
        }
    }

    int findHeight(Person* node) 
    {
        if (!node) 
        {
            return 0;
        }
        int leftH = findHeight(node->mother);
        int rightH = findHeight(node->father);
        return max(leftH, rightH) + 1;
    }

    void printGivenLevel(Person* node, int targetLevel, int currentLevel) 
    {
        if (!node) 
        {
            return;
        }
        if (currentLevel == targetLevel)
        {
            cout << "Level " << targetLevel << ": " << node->name << endl;
        }
        else 
        {
            printGivenLevel(node->mother, targetLevel, currentLevel + 1);
            printGivenLevel(node->father, targetLevel, currentLevel + 1);
        }
    }

public:
    FamilyTree(Person* r) 
    {
        root = r;
    }

    void displayRoot() 
    {
        cout << "Root (youngest person): " << root->name << endl;
    }

    void displayLeafNodes() 
    {
        cout << "\nLeaf Nodes (ancestors with no known parents): ";
        printLeafNodes(root);
        cout << endl;
    }

    void displayHeight() 
    {
        cout << "\nHeight of the tree: " << findHeight(root) << endl;
    }

    void displayLevels() 
    {
        int height = findHeight(root);
        cout << "\nLevel of each member:" << endl;
        for (int i = 1; i <= height; i++) 
        {
            printGivenLevel(root, i, 1);
        }
    }
};

int main() 
{
    Person* linda = new Person("Linda");
    Person* john = new Person("John");
    Person* aisha = new Person("Aisha");
    Person* saif = new Person("Saif");

    Person* susan = new Person("Susan");
    susan->mother = linda;
    susan->father = john;

    Person* zubair = new Person("Zubair");
    zubair->mother = aisha;
    zubair->father = saif;

    Person* aqsa = new Person("Aqsa");
    aqsa->mother = susan;
    aqsa->father = zubair;

    FamilyTree tree(aqsa);

    tree.displayRoot();
    tree.displayLeafNodes();
    tree.displayHeight();
    tree.displayLevels();

    delete linda;
    delete john;
    delete aisha;
    delete saif;
    delete susan;
    delete zubair;
    delete aqsa;

    return 0;
}
