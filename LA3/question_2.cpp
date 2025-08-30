#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main()
{
    string st = "data structure";
    string rst = "";
    int st_size = st.length();
    for (int i = 0; i < st_size; i++)
    {
        s.push(st.at(i));
    }
    while (!s.empty())
    {
        rst += s.top();
        s.pop();
    }
    cout << rst;
    
    return 0;
}
