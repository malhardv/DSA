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

Node* minValue(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp;
}

Node* maxValue(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp;
}


int main() {

    Node* root = NULL;
    root = createBST(root);
    cout<<endl;
    Node* min = minValue(root);
    cout<<"Minimum Value in BST: "<< min -> val<<endl;

    Node* max = maxValue(root);
    cout<<"Maximum Value in BST: "<< max -> val<<endl;

    return 0;
}