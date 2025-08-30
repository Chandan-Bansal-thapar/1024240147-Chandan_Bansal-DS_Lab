#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
stack <int>st; 
int main() {
    string postfix = "23*42^+9-";
   int size = postfix.length();
     char ope[] = {'+', '-', '*', '/','^'};
    int  ch_size = sizeof(ope)/sizeof(ope[0]);
      int a,b,c;
    for (int i = 0; i <size; i++)
    {
        char token = postfix.at(i);
       if (isdigit(token)) {
            st.push(token - '0'); 
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int c;

            switch (token) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
                case '*': c = b * a; break;
                case '/': c = b / a; break;
                case '^': c = pow(b, a); break;
            }

            st.push(c);
        }
    }
    cout<<st.top();
    return 0;
}