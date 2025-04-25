#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertInBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> val) {
        root -> right = insertInBST(root -> right, data);
    } else {
        root -> left = insertInBST(root -> left, data);
    }

    return root;
}

Node* createBST(Node* root) {
    int data;
    cout << "Enter Value: ";
    cin >> data;

    while(data != -1) {
        root = insertInBST(root, data);
        cout << "Enter Value: ";
        cin >> data;
    }

    return root;
}

Node* searchBST(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    
}