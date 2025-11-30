#include <iostream>
using namespace std;
class Node{
public:
   int data;
   Node*left;
   Node*right;
Node(int val){
    data = val;
    left = right = NULL;
}
};
static int idx = -1;
Node* build_tree(int arr[]){
    idx++;
    if (arr[idx] == -1){
        return NULL; 
    }
    Node *root = new Node(arr[idx]);
    root->left = build_tree(arr);
    root->right = build_tree(arr);
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
Node * inorder(Node*root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return root;
}
Node * postorder(Node*root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return root;
}

int main() {
    
    return 0;
}