#include<iostream>
#include<queue>
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

Node* BSTfromInOrder(int inOrder[], int s, int e) {
    if(s > e) {
        return NULL;
    }

    int mid = s + (e - s)/2;
    Node* root = new Node(inOrder[mid]);

    // recursive call;
    root -> left = BSTfromInOrder(inOrder, s, mid - 1);
    root -> right = BSTfromInOrder(inOrder, mid + 1, e);

    return root;
}


int main() {
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int s = 0;
    int e = 6;
    Node* root = BSTfromInOrder(inOrder, s, e);
    levelOrderTraversal(root);
    return 0;
}