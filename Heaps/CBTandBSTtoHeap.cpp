#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertInBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> data) {
        root -> right = insertInBST(root -> right, data);
    } else {
        root -> left = insertInBST(root -> left, data);
    }

    return root;
}

Node* createBST(Node* root) {
    int data;
    cout << "Enter Value: ";
    cin >> data;

    while(data != -1) {
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

void storeInOrder(Node* root, vector<int> &in) {
    if(root == NULL) {
        return;
    }
    storeInOrder(root -> left, in);
    in.push_back(root ->data);
    storeInOrder(root -> right, in);
}

void replaceNodesUsingPostOrder(Node* root, vector<int> inorder, int &index) {
    if(root == NULL) {
        return;
    }

    // replace using LRN
    replaceNodesUsingPostOrder(root -> left, inorder, index);
    replaceNodesUsingPostOrder(root -> right, inorder, index);
    root -> data = inorder[index];
    index++;
}

void convertBSTintoMaxHeap(Node* root) {
    // store the inorder of the given tree
    vector<int> inorder;
    storeInOrder(root, inorder);

    // replace the nodes of the tree with the sorted values from the inorder
    int index = 0;
    replaceNodesUsingPostOrder(root, inorder, index);
}

int main() {
    Node* root = NULL;
    root = createBST(root);
    cout<<endl;
    levelOrderTraversal(root);

    convertBSTintoMaxHeap(root);

    cout<<"CBT + BST converted to Max Heap: "<<endl;

    levelOrderTraversal(root);
    return 0;
}

// 100 50 150 40 60 110 200 20 -1