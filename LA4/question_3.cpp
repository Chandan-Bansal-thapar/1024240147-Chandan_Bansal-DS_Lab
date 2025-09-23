#include <iostream>
#include <queue>
using namespace std;
void change_queue(queue<int> &q){
    queue<int>first_half;
    queue<int>second_half;
    int size = q.size();
    int half = size/2;
    for (int i = 0; i < half; i++)
    { 
        first_half.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        second_half.push(q.front());
        q.pop();
    }
    while (size != q.size())
    {
        q.push(first_half.front());
        first_half.pop();
        q.push(second_half.front());
        second_half.pop();
    }
}
void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main() {
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    change_queue(q);
    display(q);
    return 0; 
}