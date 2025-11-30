#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> v = {5, 3, 2, 7, 6, 4};

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

Node* BST(vector<int> v) {
    Node* root = NULL;
    for (int x : v)
        root = insert(root, x);
    return root;
}
Node* findMin(Node* root) {
   while (root && root->left != NULL)
       root = root->left;
   return root;
}   
Node* delete_node(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);

    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
    
}
Node * preorder(Node*root){
    if(root==nullptr){
        return root;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return root;
}
int maxdepth(Node *root){
    if(root == nullptr){
        return 0;
    }
    int ltree = maxdepth(root->left);
    int rtree = maxdepth(root->right);
    return max(ltree,rtree)+1;
}
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = INT_MAX, right = INT_MAX;

    if (root->left)
        left = minDepth(root->left);

    if (root->right)
        right = minDepth(root->right);

    return 1 + min(left, right);
}

    int main() {
    Node * root  = BST(v);
    root = delete_node(root,7);
    preorder(root);
    cout<<"\nmax depth-"<<maxdepth(root);
    cout<<"\nmin depth-"<<minDepth(root);
}
