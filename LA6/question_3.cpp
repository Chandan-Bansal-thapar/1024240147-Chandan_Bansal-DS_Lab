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
      void size(){
        Node * temp = head;
        int count = 0;
        do
        {
            temp = temp->next;
            count++;

        } while (temp!=head);
       cout<<"Size of Circular Linked List: "<<count<<endl;
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
    void insert_front(int val){
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
      void size(){
        Node * temp = head;
        int count = 0;
      while (temp!=nullptr)
        {
            temp = temp->next;
            count++;

        } 
        cout<<"Size of Double Linked List: "<<count<<endl;
    }
};
int main() {
    Circular_list Cl;
    Cl.insert_front(10);
    Cl.insert_front(8);
    Cl.insert_front(6);
    Cl.insert_front(4);
    Cl.insert_front(2); 
    Cl.size();
    Double_list dl;
    dl.insert_front(10);
    dl.insert_front(8);
    dl.insert_front(6);
    dl.insert_front(4);
    dl.insert_front(2); 
    dl.size();
    return 0;
}