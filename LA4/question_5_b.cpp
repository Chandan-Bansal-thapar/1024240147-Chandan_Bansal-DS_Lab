#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1;

public:
    void push(int x) {
        int size = q1.size();
        q1.push(x);
        for (int i = 0; i < size; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl; 
    s.pop();

    cout << s.top() << endl; 

    return 0;
}
