#include<iostream>
#include<queue>
#include<vector>
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

// convert a binary search tree to sorted DLL
void convertBSTtoSortedDLL(Node* root, Node*& head) {
    if(root == NULL) {
        return;
    }

    // Right
    convertBSTtoSortedDLL(root -> right, head);

    // Node
    root -> right = head;
    if(head != NULL) {
        head -> left = root;
    }
    head = root;

    // Left
    convertBSTtoSortedDLL(root -> left, head);
}

Node* convertDLLtoBST(Node* head, int n) {
    if (head == NULL || n <= 0) {
        return NULL;
    }

    // LNR

    // L
    Node* leftSubtree = convertDLLtoBST(head, n/2);

    // N
    Node* root = head;
    root -> left = leftSubtree;
    head = head -> right;

    // R
    Node* rightSubtree = convertDLLtoBST(head, n - n/2 - 1);
    root -> right = rightSubtree;
    return root;
}

int main() {




    return 0;
}