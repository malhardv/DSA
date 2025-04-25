#include<iostream>
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

void printRightView(Node* root, int level, vector<int>& rightView) {
    if(root == NULL) {
        return;
    }

    if(level == rightView.size()) {
        rightView.push_back(root -> data);
    }

    printRightView(root -> right, level + 1, rightView);
    printRightView(root -> left, level + 1, rightView);
}


int main() {
    Node* root = createTree();
    vector<int> right_view;
    printRightView(root, 0, right_view);

    cout<<"Left View: "<<endl;
    for(int i = 0; i < right_view.size(); i++){
        cout<<right_view[i]<< " ";
    }

    return 0;
}