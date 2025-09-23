#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> q;
    string ch = "aabcc";
    string ch2 = "";
    int size = ch.length();

    for (int i = 0; i < size; i++)
    {
        q.push(ch.at(i));  

        while (!q.empty() && ch.find(q.front()) < i && ch.at(i) == q.front()) {
            q.pop();
        }

        if (q.empty()) {
            ch2 += "-1";
        } else {
            ch2 += q.front();
        }
    }
    cout << ch2;
    return 0;
}
