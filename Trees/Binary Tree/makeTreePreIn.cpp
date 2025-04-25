#include<iostream>
#include<queue>
#include<map>
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

void createMapping(int inOrder[], int size, map<int, int>& val) {
    for(int i = 0; i < size; i++) {
        int element = inOrder[i];
        val[element] = i;
    }
}


int searchInOrder(int inOrder[], int size, int element) {
    for(int i = 0; i < size; i++) {
        if(inOrder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* constructPreInTree(map<int, int> &valToIndex, int preOrder[], int inOrder[], int size, int &preOrderIndex, int inOrderStart, int inOrderEnd) {
    // base case
    if(preOrderIndex >= size || inOrderStart > inOrderEnd) {
        return NULL;
    }

    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    Node* root = new Node(element);

    // int position = searchInOrder(inOrder, size, element);
    int position = valToIndex[element];

    root -> left = constructPreInTree(valToIndex, preOrder, inOrder, size, preOrderIndex, inOrderStart, position - 1);
    root -> right = constructPreInTree(valToIndex, preOrder, inOrder, size, preOrderIndex, position + 1, inOrderEnd);

    return root;
}

int main() {
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    map<int, int> valToIndex;
    createMapping(inOrder, size, valToIndex);

    Node* root = constructPreInTree(valToIndex, preOrder, inOrder, size, preOrderIndex, inOrderStart, inOrderEnd);
    cout<<"Printing Entire Tree: "<<endl;
    levelOrderTraversal(root);

    return 0;
}