// FIND PREFIX USING ARRAY WAALA TRIES

#include<iostream>
#include<vector>
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


void storeString(TrieNode* root, vector<string> &ans, string input, string &prefix) {
    
    // base case
    if(root -> isTerminal){
        ans.push_back(prefix + input);
    }


    for(char ch = 'a'; ch < 'z'; ch++) {
        int index = ch - 'a';
        TrieNode* next = root -> children[index];

        if(next != NULL) {
            // child exists
            input.push_back(ch);
            // recursion
            storeString(next, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefix(TrieNode* root, string input, vector<string> &ans, string &prefix) {
    if(input.length() == 0) {
        TrieNode* lastChar = root;
        storeString(lastChar, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root -> children[index]!= NULL) {
        child = root -> children[index];
    } else {
        return;
    }

    findPrefix(child, input.substr(1), ans, prefix);
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
    // cout<<"Search Words: "<<endl;
    // cout<<"Enter the Word to Search: ";
    // cin>>input;

    // bool output = searchWord(root, input);
    // if(output) {
    //     cout<<input<<" was found in the Trie"<<endl;
    // } else {
    //     cout<<input<<" was not found in the Trie"<<endl;
    // }

    // searching all words starting from the input
    cout<<"Enter the letter: ";
    cin>>input;
    vector<string> ans;

    findPrefix(root, input, ans, input);

    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }


    return 0;
}   