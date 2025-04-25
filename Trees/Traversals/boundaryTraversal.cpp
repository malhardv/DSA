#include <iostream>
#include <queue>
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

// it returns root node of the created tree
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

void printLeft(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout << root->data << " ";

    if (root->left != NULL)
    {
        printLeft(root->left);
    }
    else
    {
        printLeft(root->right);
    }
}

void printLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRight(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    

    if (root->right != NULL)
    {
        printRight(root->right);
    }
    else
    {
        printRight(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    printLeft(root);
    printLeafNodes(root);
    if(root -> right != NULL) {
        printRight(root->right);
    } else printRight(root -> left);
}

int main()
{
    //10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    Node* root = createTree();
    boundaryTraversal(root);
    return 0;
}