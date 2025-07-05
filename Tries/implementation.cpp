#include<iostream>
using namespace std;

class TrieNode {
    public:

    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
        this -> value = val;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this -> isTerminal = false;
    }
};

void insertWord(TrieNode* &root, string word) {

    if(word.length() == 0) {
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // if character is already a child of the node
    // present
    if(root -> children[index] != NULL) {
        child = root -> children[index];
    } else {
        // if not a child
        child = new TrieNode(ch);
        root -> children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* &root, string word) {
    if(word.length() == 0) {
        return root -> isTerminal;
    }
    
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root -> children[index] != NULL) {
        // character is one of the children
        child = root -> children[index];
    } else {
        // if character is not the child of the root
        return false;
    }

    bool searchAnswer = searchWord(child, word.substr(1));
    return searchAnswer;
}

int main() {

    TrieNode* root = new TrieNode('#');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout<<"Insertion Done"<<endl;

    string input;
    cout<<"Search Words: "<<endl;
    cout<<"Enter the Word to Search: ";
    cin>>input;

    bool output = searchWord(root, input);
    if(output) {
        cout<<input<<" was found in the Trie"<<endl;
    } else {
        cout<<input<<" was not found in the Trie"<<endl;
    }
    return 0;
}