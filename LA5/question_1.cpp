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
    void Push_back(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
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
    void insertElement_withPosition(int val, int pos)
    {
        if (head == NULL)
        {
            head = tail = new Node(val);
            return;
        }
        if (pos == 1)
        {
            Push_front(val);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "pos out of range" << pos << endl;
            return;
        }
        if (temp->next == NULL)
        {
            Push_back(val);
            return;
        }
        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void delete_any_position(int pos){
        if (head == NULL)
        {
           cout<<"list is empty";
        }
        if (pos == 1)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos -1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout <<"pos out of range"<<pos<<endl;
            return;
        }
        if (temp->next==tail)
        {
            pop_back();
            return;
        }
        Node* del = temp->next; 
        temp->next = del->next;
        delete del;
    }
    void search_list(int key){
        Node* temp = head;
        int count = 1;
        while(temp != NULL && temp->data != key){
         temp = temp->next;
         count++;
        }
        if (temp==NULL)
        {
            cout<<"data is not given"<<endl;
        }
        else
        {
            cout<<count<<"-"<<temp->data<<endl;
        }
        
    }
};
int main()
{
    list l;
    l.Push_front(6);
    l.Push_front(5);
    l.Push_back(7);
    l.insertElement_withPosition(8, 4);
    l.display();
    l.delete_any_position(2);
    l.display();
    return 0;
}