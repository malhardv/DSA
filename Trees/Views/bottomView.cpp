#include<iostream>
#include<map>
#include<queue>
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

void printBottomView(Node* root) {
    map<int, int> hdToNodeMap; // hd - horizontal distance of every node
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;

        hdToNodeMap[hd] = front -> data;

        if(front -> left != NULL) {
            q.push(make_pair(front->left, hd - 1));
        }

        if(front -> right != NULL) {
            q.push(make_pair(front->right, hd + 1));
        }
    }

    for(auto i: hdToNodeMap) {
        cout<<i.second<<" ";
    }
}



int main() {
    Node* root = createTree();
    printBottomView(root);
    return 0;
}