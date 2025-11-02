#include <iostream>
using namespace std;

class TrieNode
{
    // data , nodes , terminal
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    // util function -> called by this fun

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        // need to insert

        int index = word[0] - 'A';

        if (root->children[index] != nullptr)
        {
            // prsent
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // true / false is return value
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        TrieNode *child;

        int index = word[0] - 'A';

        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    bool hasChildren(TrieNode * root )
    {
        for(int i =0 ; i < 26 ; i++)
        {
            if(root->children[i] != nullptr)
                return true;
        }

        return false;
    }
    // remove
    bool removeUtil(TrieNode *root, string word, int depth = 0)
    {
        if(root==nullptr) return false;

        if(depth == word.length())
        {
            if(!root->isTerminal)
                return false;

            root->isTerminal = false;

            return !hasChildren(root);
        }

        int index = word[depth]-'A';
        TrieNode * child = root->children[index];

        if(!child)
            return false;

        bool shouldDeleteCurretNode = removeUtil(child, word, depth+1);
        if(shouldDeleteCurretNode)
        {
            delete root->children[index];
            root->children[index] = nullptr;

            return !root->isTerminal && !hasChildren(root);
        }

        return false;
    }

    // insertion
    void insert(string word)
    {
        insertUtil(root, word);
    }

    // search
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool remove(string word)
    {
        return removeUtil(root, word);
    }
};

int main()
{

    Trie *t = new Trie();
    t->insert("ABC");
    t->insert("CAR");

    bool ans = t->search("ABC");
    ans ? cout << "hain" : cout << "nahi hain";

    bool delAns = t->remove("ABC");
    cout<<delAns;

    return 0;
}