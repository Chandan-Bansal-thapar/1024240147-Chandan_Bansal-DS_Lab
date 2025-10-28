#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
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
    void display(){
        Node * temp = head;
        do
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        } while (temp!=head);
        cout<<head->data;
    }
};
int main() {
    Circular_list l;
    l.insert_front(10);
    l.insert_front(8);
    l.insert_front(6);
    l.insert_front(4);
    l.insert_front(2);
    l.display();
    return 0;
}