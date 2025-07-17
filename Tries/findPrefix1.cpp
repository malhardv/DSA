// FIND PREFIX USING HASHMAPS WAALA TRIES
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

void insertWord(TrieNode* root, string word) {
    // base case
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

    insertWord(child, word.substr(1));
}

void storeString(TrieNode* root, string input, vector<string> &ans, string &prefix) {
    // base case
    if(root -> isTerminal) {
        ans.push_back(prefix + input);
    }

    for(char ch = 'a'; ch < 'z'; ch++) {

        TrieNode* next = root -> children[ch];

        if(next != NULL) {

            // child exists
            input.push_back(ch);

            // recursive call
            storeString(next, input, ans, prefix);

            // backtracking
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode* root, string input, vector<string> &ans, string &prefix) {
    // base case
    if(input.length() == 0) {
        TrieNode* lastChar = root;
        storeString(root, input, ans, prefix);
        return;
    }

    char ch = input[0];
    TrieNode* child;

    if(root -> children.find(ch) != root -> children.end()) {
        child = root -> children[ch];
    } else {
        return;
    } 

    storeString(child, input.substr(1), ans, prefix);
    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestion(TrieNode* root, string input) {

    vector<vector<string>> output;
    TrieNode* prev = root;

    for(int i = 0; i < input.length(); i++) {
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode* curr = prev -> children[index];

        if(curr == NULL) {
            break ;
        } else {
            
        }
    }

}


int main() {

    TrieNode* root = new TrieNode('#');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lads");
    insertWord(root, "linger");
    insertWord(root, "lentils");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout<<"Insertion Done!"<<endl;

    string input;
    cout<<"Enter the prefix string: ";
    cin>> input;
    vector<string> ans;

    findPrefixString(root, input, ans, input);

    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}