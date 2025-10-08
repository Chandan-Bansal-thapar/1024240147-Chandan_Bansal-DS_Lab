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
    void reverse_list(){
        Node * prev = nullptr;
        Node * curr = head;
        while (curr!=nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        head = prev;
    }
       void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NUll" << endl;
    }
};
int main() {
   list l;
   l.Push_front(35);
   l.Push_front(56);
   l.Push_front(75);
   l.Push_front(20);
   l.Push_front(78);
   l.Push_front(19);
   l.reverse_list();
   l.display();
    return 0;
}