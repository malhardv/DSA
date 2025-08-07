#include<iostream>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    int data;

    Node(int val) {
        this -> left = NULL;
        this -> right = NULL;
        this -> data = val;
    }
};

void inOrder(Node* root) {
    if(root -> left) {
        Node* prev = root -> left;
        while(prev -> right) {
            prev = prev -> right;
        }

        inOrder(root -> left);

        prev -> right = root;
        root -> left = prev;
    }

    if(root -> right) {
        Node* next = root -> right;
        while(next -> left) {
            next = next -> left;
        }

        inOrder(root -> right);

        next -> left = root;
        root -> right = next;
    }
}

Node* BTtoDLL(Node* root) {

    if(root == NULL) {
        return;
    }
    Node* head = root;

    while(head -> left) {
        head = head -> left;
    }

    inOrder(root);

    return head;
}

int main() {
    // hardcode the tree
    return 0;
}