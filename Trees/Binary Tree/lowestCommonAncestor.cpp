#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // create Node
    Node *root = new Node(data);

    cout << "Left of Node: " << root->data << endl;
    // create left subtree
    root->left = createTree();

    cout << "Right of Node: " << root->data << endl;
    // create right subtree
    root->right = createTree();
    return root;
}

Node* lowestCommonAncestor(Node* root, Node*  p, Node*  q) {

    // base case
    if(root == NULL) {
        return NULL;
    } else if(root -> data == p -> data) {
        return p;
    } else if(root -> data == q -> data) {
        return q;
    }

    Node* left = lowestCommonAncestor(root -> left, p, q);
    Node* right = lowestCommonAncestor(root -> right, p, q);

    if(left == NULL && right == NULL) {
        return NULL;
    } else if(left != NULL && right == NULL) {
        return left;
    } else if(left == NULL && right != NULL) {
        return right;
    } else {
        return root;
    }

}