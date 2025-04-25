#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertInBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> val) {
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
            cout << front->val << " ";

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

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout<<root -> val<<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}
void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrder(root -> left);
    cout<<root -> val<<" ";

    inOrder(root -> right);
}
void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> val<<" ";
}

int main() {
    Node* root = NULL;
    root = createBST(root);
    levelOrderTraversal(root);

    cout<<endl;

    cout<<"In-Order: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Pre-Order: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"Post-Order: "<<endl;
    postOrder(root);
    return 0;
}