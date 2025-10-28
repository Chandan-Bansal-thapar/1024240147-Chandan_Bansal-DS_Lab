#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = NULL;
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
    void insert_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insert_last(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void insert_any_specific(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head->next;
        if (pos == 0)
        {
            insert_front(val);
            return;
        }
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                cout << "invalid position";
            }
        }
        if (temp->next == head)
        {
            insert_last(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "l is empty";
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        tail->next = head;
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
        temp->next = head;
        delete tail;
        tail = temp;
        tail->next = head;
    }
    void delete_any_position(int pos)
    {
        if (head == NULL)
        {
            cout << "list is empty";
        }
        if (pos == 1)
        {
            pop_front();
            return;
        }
        Node *temp = head->next;
        for (int i = 2; i < pos - 1 && temp != head; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "pos out of range" << pos << endl;
            return;
        }
        if (temp->next == tail)
        {
            pop_back();
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void search_list(int key)
    {
        Node *temp = head;
        int count = 1;
        if (head == nullptr)
        {
            cout << "List empty" << endl;
            return;
        }
        do
        {
            if (temp->data == key)
            {
                cout << "Found at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        } while (temp != head);
        cout << "Data not found" << endl;
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
    void insert_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insert_last(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insert_any_specific(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head->next;
        if (pos == 0)
        {
            insert_front(val);
            return;
        }
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == nullptr)
            {
                cout << "invalid position";
            }
        }
        if (temp->next == nullptr)
        {
            insert_last(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
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
    void delete_any_position(int pos)
    {
        if (head == NULL)
        {
            cout << "list is empty";
        }
        if (pos == 1)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "pos out of range" << pos << endl;
            return;
        }
        if (temp->next == nullptr)
        {
            pop_back();
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void search_list(int key)
    {
        Node *temp = head;
        int count = 1;
        if (head == nullptr)
        {
            cout << "List empty" << endl;
            return;
        }
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Found at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Data not found" << endl;
    }
};
int main()
{
    Circular_list l;
    l.insert_front(5);
    l.insert_front(7);
    l.insert_front(6);
    l.insert_front(8);
    l.search_list(6);
    Double_list dl;
    dl.insert_front(5);
    dl.insert_front(7);
    dl.insert_front(6);
    dl.insert_front(8);
    dl.search_list(6);
    return 0;
}