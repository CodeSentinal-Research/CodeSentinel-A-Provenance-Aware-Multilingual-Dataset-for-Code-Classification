Here's a simple implementation of the problem in C++. This code uses a Trie data structure to store the input string and the words. It then counts the number of times each word appears in the input string.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool leaf;
    int count;
};

struct TrieNode *getNode() {
    struct TrieNode *node = new TrieNode;
    node->leaf = false;
    node->count = 0;

    for(int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode *root, string key) {
    struct TrieNode *node = root;

    for(int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if(node->children[index] == NULL)
            node->children[index] = getNode();

        node = node->children[index];
    }

    node->leaf = true;
}

int countPrefix(struct TrieNode *root, string prefix) {
    struct TrieNode *node = root;

    for(int i = 0; i < prefix.length(); i++) {
        int index = prefix[i] - 'a';

        if(node->children[index] == NULL)
            return 0;

        node = node->children[index];
    }

    return node->count;
}

int main() {
    string str;
    int n;

    cin >> str;
    cin >> n;

    struct TrieNode *root = getNode();

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if(str.find(word) != string::npos)
            insert(root, word);
    }

    int count = 0;

    for(int i = 0; i < str.length(); i++) {
        string prefix = str.substr(0, i + 1);

        count += countPrefix(root, prefix);
    }

    cout << count << endl;

    return 0;
}

This code creates a Trie data structure with each node representing a character in the alphabet, and each child representing a subsequent character. The leaf node represents a word that ends at this node. The count attribute of the leaf nodes keeps track of the number of words that end at this node. The main function reads the string and the number of words, and inserts each word into the Trie. It then counts the number of words that are prefixes of the input string, and prints the count.