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

bool isBst(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBst(root->left, minVal, root->data) &&
           isBst(root->right, root->data, maxVal);
}

int main() {
    Node* root = BST(v);

    if (isBst(root, INT_MIN, INT_MAX))
        cout << "yes this is valid bst";
    else
        cout << "no this is not valid bst";

    return 0;
}
