// #include<iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         this->data = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Node *createTree()
// {
//     cout<<"Enter the value: ";
//     int data;
//     cin>>data;

//     if(data == -1) {
//         return NULL;
//     }

//     // create root
//     Node* root = new Node(data);

//     // left of root
//     cout<<"Left of Node: "<<root -> data<<endl;
//     root -> left = createTree();

//     // right of root
//     cout<<"Right of Node: "<<root -> data<<endl;
//     root -> right = createTree();

//     return root;
// }

// Node* KthAncestor(Node* root, Node* p, int k) {
//     if(root == NULL) {
//         return NULL;
//     } else if (k )

//     if(root -> data == p -> data) {
//         k--;
//         return p;
//     }

//     Node* left = lowestCommonAncestor(root -> left, p, q);
//     Node* right = lowestCommonAncestor(root -> right, p, q);

//     if(left == NULL && right == NULL) {
//         return NULL;
//     } else if(left != NULL && right == NULL) {
//         return left;
//     } else if(left == NULL && right != NULL) {
//         return right;
//     } else {
//         return root;
//     }
// }

// int main() {
//     Node* root = createTree();
//     Node* p = new Node(40);

//     cout<<"Enter the value of K: ";
//     int k;
//     cin>>k; 

//     Node* kAncestor = KthAncestor(root, p, k);

//     cout<<"Kth Ancestor: "<<kAncestor -> data;

//     return 0;
// }