#include <iostream>
#include <vector>
using namespace std;
vector<int> v = {5, 3, 2, 7, 6, 4};
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

Node *BST(vector<int> v)
{
    Node *root = nullptr;
    for (int i : v)
    {
        root = insert(root, i);
    }
    return root;
}
void search(Node *root, int val)
{
    if (root == nullptr)
    {
        cout<<"Element is not found"<<endl;
        return;
    }
    if (root->data == val)
    {
       cout<<"Element  is found"<<endl;
       return;
    }
    if (root->data<val)
    {
        search(root->right, val);
    }
    else
    {
        search(root->left, val);
    }
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
int min(Node*root){
while (root->left!=nullptr)
{
    root = root->left;
}
cout<<"\n"<<root->data;
 
}
int max(Node*root){
while (root->right!=nullptr)
{
    root = root->right;
}
cout<<"\n"<<root->data;
}
vector<int>a(Node * root,int key){
 Node *curr = root;
 Node *pre = NULL;
 Node *succ= NULL;
 while (curr != NULL){
    if (key<curr->data){
        succ = curr;
        curr = curr->left;
    }
    else if(key>curr->data){
        pre = curr;
        curr = curr->right;
    }
    else{
        if(curr->left != nullptr){
            Node*right = curr->left;
            while (right->right!=NULL)
            {
                right = right->right;
                pre = right;
            }
        if(curr->right != nullptr){
            Node*left = curr->right;
            while (left->left!=NULL)
            {
                left = left->left;
                succ = left;
            }
            
        }
        break;
    }
 }
}
return {pre->data,succ->data};
}
int main()
{
    Node *root = BST(v);
    search(root,7);
    preorder(root);
    min(root);
    max(root);
    vector<int>ans = a(root,5);
    cout<<"\n"<<ans[0];
    cout<<"\n"<<ans[1];
    return 0;
}