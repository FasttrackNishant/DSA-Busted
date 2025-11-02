#include <iostream>
using namespace std;

// Trie node class
class TrieNode
{
public:
    char data;                    // Character stored in this node
    TrieNode *children[26];       // Pointers to child nodes (for each alphabet letter)
    bool isTerminal;              // True if this node marks the end of a word

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr; // Initialize all children as nullptr
        }
        isTerminal = false;        // Not terminal by default
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0'); // Root node with null character
    }

    // Helper function to insert a word into the Trie
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true; // Mark end of word
            return;
        }

        TrieNode *child;
        int index = word[0] - 'A'; // Map character to index (assuming uppercase)

        if (root->children[index] != nullptr)
        {
            // Child node exists, move to it
            child = root->children[index];
        }
        else
        {
            // Child node does not exist, create it
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recurse for the next character
        insertUtil(child, word.substr(1));
    }

    // Helper function to search for a word in the Trie
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal; // Return true if end of word is reached
        }

        TrieNode *child;
        int index = word[0] - 'A';

        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return false; // Character not found
        }

        // Recurse for the next character
        return searchUtil(child, word.substr(1));
    }

    // Helper function to remove a word from the Trie
    bool removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false; // Unmark terminal
            return isEmpty(root);     // If node has no children, it can be deleted
        }

        int index = word[0] - 'A';
        TrieNode *child = root->children[index];

        if (child == nullptr)
            return false; // Word not found

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild)
        {
            delete child;
            root->children[index] = nullptr;
            // If current node is not terminal and has no children, it can be deleted
            return !root->isTerminal && isEmpty(root);
        }

        return false;
    }

    // Insert a word into the Trie
    void insert(string word)
    {
        insertUtil(root, word);
    }

    // Search for a word in the Trie
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // Remove a word from the Trie
    void remove(string word)
    {
        removeUtil(root, word);
    }

    // Check if a Trie node has any children
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool startsWithUtil(TrieNode* root, string prefix) {
        if (prefix.length() == 0) {
            return true; // All characters in prefix matched
        }
        int index = prefix[0] - 'A';
        if (root->children[index] == nullptr) {
            return false; // Prefix character not found
        }
        return startsWithUtil(root->children[index], prefix.substr(1));
    }

    // Public function to check prefix
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
    
    
};

int main()
{
    Trie *t = new Trie();
    t->insert("ABC");
    t->insert("DEF");

    cout << t->search("ABC") << endl; // Should print 1 (true)

    cout << "Is Empty: " << t->isEmpty(t->root) << endl; // Should print 0 (false)

    t->remove("ABC");
    t->remove("DEF");

    cout << t->search("ABC") << endl; // Should print 0 (false)
    cout << "Is Empty: " << t->isEmpty(t->root) << endl; // Should print 1 (true)

		cout << t->startsWith("AB") << endl; // Should print 1 if any word starts with "AB"
    return 0;
}