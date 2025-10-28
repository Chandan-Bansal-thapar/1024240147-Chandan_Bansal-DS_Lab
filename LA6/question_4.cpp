#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node * prev;
    Node(char val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Double_list
{
private:
    Node *head;
    Node *tail;

public:
    Double_list()
    {
     head = tail = nullptr;
    }
    void insert_front(char val){
        Node * newNode = new Node(val);
        if(head==nullptr){
            head = tail = newNode;   
        }
        else
        {
            newNode->next = head;
            head ->prev = newNode;
            head = newNode;
        } 
    }
    void check_palidrome(){
        Node * N = head;
        Node * P = tail;
        while (N!=nullptr&&P!=nullptr)
        {
           if(N->data!=P->data){
            cout<<"False";
            return;
           }
           N = N->next;
           P = P->prev;   
        }
         cout<<"True";
        
    }
};
int main() {
    Double_list l;
    l.insert_front('L');
    l.insert_front('E');
    l.insert_front('V');
    l.insert_front('E');
    l.insert_front('L');
    l.check_palidrome();
    return 0;
}