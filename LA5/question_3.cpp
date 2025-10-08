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
class list
{
private:
    Node *head;
    Node *tail;

public:
    list()
    {
     head = tail = nullptr;
    }
        void Push_front(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    int middle(){
        Node*fast = head;
        Node*slow = head;
        while (fast->next != nullptr)
        {
         fast = fast->next->next;
         slow = slow->next;
         if (fast==NULL){
            break;
         }
        
        }
        return slow->data;
    }
};


int main() {
    list l;
    l.Push_front(5);
    l.Push_front(8);
    l.Push_front(7);
    l.Push_front(6);
    l.Push_front(9);
    l.Push_front(10);
    cout<<l.middle();
    return 0;
}