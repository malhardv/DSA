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

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // N L R
    // N
    cout << root->data << " ";

    // L
    preOrderTraversal(root->left);

    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // L N R

    // L
    inOrderTraversal(root->left);

    // N
    cout << root->data << " ";

    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // L R N
    
    // L
    postOrderTraversal(root->left);

    // R
    postOrderTraversal(root->right);

    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = createTree();

    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level-Order Traversal: "<<endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}