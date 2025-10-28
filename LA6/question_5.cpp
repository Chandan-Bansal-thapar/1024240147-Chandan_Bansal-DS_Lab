#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node * prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Circular_list
{
private:
    Node *head;
    Node *tail;

public:
    Circular_list()
    {
     head = tail = nullptr;
    }
    void insert_front(int val){
        Node * newNode = new Node(val);
        if(head==nullptr){
            head = tail = newNode;   
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
      void circular_list_Check(){
        Node * temp = head;
        int count = 0;
        do
        {
            temp = temp->next;
            if(temp ==NULL){
              cout<<"False";
              return;
            }
        } while (temp!=head);
        cout<<"True";
       return;
    }
};
int main() {
    Circular_list Cl;
    Cl.insert_front(10);
    Cl.insert_front(8);
    Cl.insert_front(6);
    Cl.insert_front(4);
    Cl.insert_front(2); 
    Cl.circular_list_Check();
    return 0;
}