#include<iostream>
#include<queue>
#include<vector>
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

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if(root == NULL) {
        return;
    }

    if(level == leftView.size()) {
        leftView.push_back(root -> data);
    }

    printLeftView(root -> left, level+1, leftView);
    printLeftView(root -> right, level+1, leftView);
    
}

int main() {
    Node* root = createTree();
    vector<int> left_view;
    printLeftView(root, 0, left_view);

    cout<<"Left View: "<<endl;
    for(int i = 0; i < left_view.size(); i++){
        cout<<left_view[i]<< " ";
    }

    return 0;
}