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
     void pop_front()
    {
        if (head == NULL)
        {
            cout << "l is empty";
        }
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
     void pop_back()
    {
        if (head == NULL)
        {
            cout << "l is empty";
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
        int delete_any_position(int key){
        int count=0;
        Node * temp = head->next;
        if(head->data == key){
            pop_front();
            count++;
        }
        while (temp->next->next!=nullptr)
        {
            if(temp->next->data==key){
                Node*sim = temp->next;
                temp->next = sim->next;
                delete sim;
                count++;
            }
            temp = temp->next;
        }
         if(tail->data == key){
            pop_back();
            count++;
        } 
        return count;
    }
    void display(){
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
    l.Push_front(1);   
    l.Push_front(2);   
    l.Push_front(3);   
    l.Push_front(1);   
    l.Push_front(3);   
    l.Push_front(1);   
    l.Push_front(2);   
    l.Push_front(1);   
    cout<<"count:- "<<l.delete_any_position(1);
    cout<<"\n";
    l.display();
    return 0;
}