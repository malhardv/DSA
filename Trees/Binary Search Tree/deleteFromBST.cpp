#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
    }
    else
    {
        root->left = insertInBST(root->left, data);
    }

    return root;
}

Node *createBST(Node *root)
{
    int data;
    cout << "Enter Value: ";
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cout << "Enter Value: ";
        cin >> data;
    }

    return root;
}

Node* maxValue(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp;
}

Node *deleteNode(Node *root, int target)
{
    // find target
    // delete target (4 cases)

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // 4 cases

        // case 1
        // left and right of root both NULL (lead node)
        if(root -> left == NULL && root -> right == NULL){
            return NULL;
        } else if(root -> left != NULL && root -> right == NULL) {
            // when left is non NULL and right is NULL
            Node* childSubtree = root -> left;
            delete root;
            return childSubtree;
        } else if(root -> left == NULL && root -> right != NULL) {
            // when left is NULL and right is non NULL
            Node* childSubtree = root -> right;
            delete root;
            return childSubtree;
        } else {
            // both left and right of root are non NULL
            // main case

            // find max value of left subtree    or    min value of right subtree
            Node* maxi = maxValue(root -> left);
            
            // replacement
            root -> data = maxi -> data;

            // delete the original maxi node
            root -> left = deleteNode(root -> left, maxi -> data);
            
            return root;
        }
    }
    else if(root -> data > target )
    {

    }
    else 
    {

    }
}