#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

bool hasLoop(Node* head){
    unordered_set<Node*> st;
    Node* curr = head;

    while(curr){
        if(st.count(curr)) return true;
        st.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; 

    cout << (hasLoop(head) ? "true" : "false");
}
