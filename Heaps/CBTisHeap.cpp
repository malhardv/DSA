#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Info {
    public:
    int maxValue;
    bool isHeap;

    Info(int a, bool b) {
        this -> maxValue = a;
        this -> isHeap = b;
    }
};

Info checkMaxHeap(Node* root) {
    if(root == NULL) {
        Info temp(INT8_MIN, true);
        return temp;
    }

    if(root -> left == NULL && root->right == NULL) {
        Info temp(root -> data, true);
        return temp;
    }

    Info leftAns = checkMaxHeap(root -> left);
    Info rightAns = checkMaxHeap(root -> right);

    // 1 case mujhe solve karna hai
    if(root -> data > leftAns.maxValue && root -> data > rightAns.maxValue && leftAns.isHeap && rightAns.isHeap) {
        Info temp(root -> data, true);
        return temp;
    } else {
        Info temp(max(root -> data, max(leftAns.maxValue, rightAns.maxValue)), false);
        return temp;
    }
}

// using only bool
bool checkHeap(Node* root) {
    if(root == NULL) {
        return false;
    }

    if(root -> left == NULL && root -> right == NULL) {
        return true;
    }

    if(root -> right == NULL) {
        return (root -> data >= root -> left -> data) && checkHeap(root -> left);
    }

    bool leftAns = checkHeap(root -> left);
    bool rightAns = checkHeap(root -> right);

    if(root -> data > root -> left -> data && root -> data > root -> right -> data && leftAns && rightAns) {
        return true;
    } else {
        return false;
    }

}

int main() {

    return 0;
}