#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x){ data=x; left=right=NULL; }
};

bool findDuplicate(Node* root, unordered_set<int>& st){
    if(!root) return false;
    if(st.count(root->data)) return true;
    st.insert(root->data);
    return findDuplicate(root->left,st) || findDuplicate(root->right,st);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(2);

    unordered_set<int> st;
    cout << (findDuplicate(root, st) ? "Duplicates Found" : "No Duplicates");
}
