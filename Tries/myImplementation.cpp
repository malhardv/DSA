#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TrieNode {
    public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        this -> value = val;
        this -> isTerminal = false;
    }
};

void insertWord(TrieNode* &root, string word) {

    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root -> children.find(ch) != root -> children.end()) {
        child = root -> children[ch];
    } else {
        child = new TrieNode(ch);
        root -> children[ch] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* & root, string word) {
    if(word.length() == 0) {
        return root -> isTerminal;
    }

    char ch = word[0];
    TrieNode* child;

    if(root ->children.find(ch) != root -> children.end()) {
        child = root -> children[ch];
    } else {
        return false;
    }

    bool searchAnswer = searchWord(child, word.substr(1));
    return searchAnswer;
}

int main() {

    TrieNode* root = new TrieNode('#');
    insertWord(root, "malhar");
    insertWord(root, "navyaa");
    insertWord(root, "tanisha");
    insertWord(root, "swayam");
    insertWord(root, "kanish");
    insertWord(root, "sarthak");
    insertWord(root, "surya");
    insertWord(root, "");
    cout<<"Insertion Complete"<<endl;

    // searching
    string input;
    cout<<"Enter the name: ";
    cin>> input;

    bool answer = searchWord(root, input);
    if(answer) {
        cout<<input<<" found in the Trie."<<endl;
    } else {
        cout<<input<<" not found in the Trie"<<endl;
    }

    return 0;
}