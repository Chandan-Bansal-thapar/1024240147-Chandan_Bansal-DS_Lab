#include <iostream>
#include <stack>
using namespace std;
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '(')
        return 0;
    else
        return -1;
}
int main()
{
    stack<char> s;
    string postfix = "";
    string infix = "(a+b)*c/d+(e-f)";
    int size = infix.length();
    char ope[] = {'+', '-', '*', '/', '(', ')', '^'};
    int size2 = sizeof(ope) / sizeof(ope[0]);
     for (int i = 0; i < size; i++) {
        bool isOp = false;
        for (int j = 0; j < size2; j++) {
            if (infix.at(i) == ope[j]) {
                isOp = true;
                if (infix.at(i) == '(') {
                    s.push(infix.at(i));
                }
                else if (infix.at(i) == ')') {
                    while (!s.empty() && s.top() != '(') {
                        postfix += s.top();
                        s.pop();
                    }
                    if (!s.empty()) s.pop(); 
                }
                else {
                    while (!s.empty() && precedence(infix.at(i)) <= precedence(s.top())) {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix.at(i));
                }
                break;
            }
        }
        if (!isOp) {
            postfix += infix.at(i);
        }
    }
        cout << postfix;
        cout << s.top();
        return 0;
    }
