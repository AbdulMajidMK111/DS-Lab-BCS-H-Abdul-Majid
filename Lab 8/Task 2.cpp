#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    int playCount;
    Song* left;
    Song* right;

    Song(string t, int p) 
    {
        title = t;
        playCount = p;
        left = right = nullptr;
    }
};

class MusicBST 
{
private:
    Song* root;

    Song* insert(Song* node, string title, int playCount) 
    {
        if (!node)
        {
            return new Song(title, playCount);
        }
        if (playCount < node->playCount)
        {
            node->left = insert(node->left, title, playCount);
        }
        else if (playCount > node->playCount)
        {
            node->right = insert(node->right, title, playCount);
        }
        return node;
    }

    Song* search(Song* node, int playCount) 
    {
        if (!node || node->playCount == playCount)
        {
            return node;
        }
        if (playCount < node->playCount)
        {
            return search(node->left, playCount);
        }
        else
        {
            return search(node->right, playCount);
        }
    }

    void inorder(Song* node) 
    {
        if (!node) return;
        inorder(node->left);
        cout << node->title << " (" << node->playCount << " plays)" << endl;
        inorder(node->right);
    }

    void postorder(Song* node) 
    {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->title << " (" << node->playCount << " plays)" << endl;
    }

    Song* findMin(Song* node) 
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    Song* deleteNode(Song* node, int playCount) 
    {
        if (!node) 
        {
            return node;
        }
        if (playCount < node->playCount)
        {
            node->left = deleteNode(node->left, playCount);
        }
        else if (playCount > node->playCount)
        {
            node->right = deleteNode(node->right, playCount);
        }
        else 
        {
            if (!node->left) 
            {
                Song* temp = node->right;
                delete node;
                return temp;
            } 
            else if (!node->right) 
            {
                Song* temp = node->left;
                delete node;
                return temp;
            }
            Song* temp = findMin(node->right);
            node->title = temp->title;
            node->playCount = temp->playCount;
            node->right = deleteNode(node->right, temp->playCount);
        }
        return node;
    }

public:
    MusicBST() 
    { 
        root = nullptr;
    }

    void insert(string title, int playCount) 
    {
        root = insert(root, title, playCount);
    }

    void search(int playCount) 
    {
        Song* result = search(root, playCount);
        if (result)
        {
            cout << "Found: " << result->title << " (" << result->playCount << " plays)" << endl;
        }
        else
        {
            cout << "Song with play count " << playCount << " not found." << endl;
        }
           
    }

    void displayInorder() 
    {
        cout << "\nSongs sorted from least to most played:" << endl;
        inorder(root);
    }

    void displayPostorder() 
    {
        cout << "\nSongs removed in reverse popularity order:" << endl;
        postorder(root);
    }

    void deleteSong(int playCount) 
    {
        root = deleteNode(root, playCount);
    }
};

int main() 
{
    MusicBST playlist;

    playlist.insert("Song A", 50);
    playlist.insert("Song B", 120);
    playlist.insert("Song C", 30);
    playlist.insert("Song D", 200);
    playlist.insert("Song E", 90);

    playlist.displayInorder();
    playlist.displayPostorder();

    cout << "\nSearching for song with 90 plays:" << endl;
    playlist.search(90);

    cout << "\nDeleting song with 120 plays" << endl;
    playlist.deleteSong(120);

    cout << "\nUpdated playlist (Inorder):" << endl;
    playlist.displayInorder();

    return 0;
}
