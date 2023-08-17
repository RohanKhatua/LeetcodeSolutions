#include <bits/stdc++.h>
using namespace std;

class TrieNode;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  // Use pointers here
    bool endOfWord;

    TrieNode() {
        children = {};
        endOfWord = false;
    }
};

bool inWord(char ch, unordered_map<char, TrieNode*> children) {
    if (children.find(ch) == children.end())
        return false;
    return true;
}

class Trie {
public:
    TrieNode root;
    Trie() {
        root = TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = &root;

        for (char letter : word) {
            if (!inWord(letter, curr->children)) {
                curr->children[letter] = new TrieNode();
            }
            curr = curr->children[letter];
        }

        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = &root;
        for (char letter : word) {
            if (!inWord(letter, curr->children)) {
                return false;
            }
            curr = curr->children[letter];
        }

        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = &root;
        for (char letter : prefix) {
            if (!inWord(letter, curr->children)) {
                return false;
            }
            curr = curr->children[letter];
        }

        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    string word = "apple";
    obj->insert(word);
    bool param_2 = obj->search(word);
    string prefix = "app";
    bool param_3 = obj->startsWith(prefix);
    cout<<param_2<<param_3;
    
    // Clean up memory (optional)
    delete obj;
}
