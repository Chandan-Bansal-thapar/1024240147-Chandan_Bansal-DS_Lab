#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <char>st; 
    string infix = "(a+b)/{c-d-e}*[4]";
    int size = infix.length();
    bool check = true;
    for (int i = 0; i < size; i++)
    {
        if (infix.at(i)=='('||infix.at(i)=='['||infix.at(i)=='{')
        {
            st.push(infix.at(i));
        }
        else if (infix.at(i)==')'||infix.at(i)==']'||infix.at(i)=='}')
        {
            char top = st.top();
            st.pop();
        }
    }
    if (!st.empty()) check = false;
 if(check){
    cout<<"Balanced";
 }   
 else
 {
    cout<<"not Balanced";
 }
 
    return 0;
}