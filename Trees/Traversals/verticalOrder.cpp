#include<iostream>
#include<set>
#include<queue>
#include<map>
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

void verticalOrder(Node* root, vector<int>& vertical) {
    if(root == NULL) {
        return 0;
    }

    map<int, map<int, multiset<int>>> mp; 
    queue<tuple<Node*, int, int>> q;

    q.push({root, 0, 0});

    while (!q.empty())
    {
        auto [node, col, row] = q.front();
        q.pop();

        mp[col][row].insert(node -> data);

        if(node -> left) q.push({node -> left, col - 1, row + 1});
        if(node -> right) q.push({node -> right, col + 1, row + 1});
    }
    
    for(auto& [col, levels] : mp) {
        
    }


}

int main() {
    Node* root = createTree();
    vector<int> vertical;

    verticalOrder(root, vertical);
    for(int i = 0; i < vertical.size(); i++) {
        cout<<vertical[i]<<" ";
    }
    return 0;
}