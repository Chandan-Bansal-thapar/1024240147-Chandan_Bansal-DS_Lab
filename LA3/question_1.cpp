#include <iostream>
using namespace std;
class Stack
{
private:
    int top = -1;
    int element [5];
public:
   int isfull(){
   int  n = sizeof(element)/sizeof(int);
    if(top==n-1){
        return false;
    }
    else{
        return true;
    }
   }
   int push(int x){
    if(isfull()){
        top++;
        element[top] = x;
    }
   }
   int isEmpty(){
    if (top==-1){
        return true;
    }
    else{
        return false;
    }
   }
   int pop(){
     if(isEmpty()){
       cout<<"stack is empty ";
     }
     else{
        top--;
     }
   }
   int display(){
    for (int i = 0; i <= top; i++)
    {
        cout<<element[i]<<" ";
    }
    cout<<endl;
   }
                  
};
int main() {
    Stack stack;
    stack.push(5);
    stack.push(9);
    stack.push(6);
    stack.push(1);
    stack.push(2);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}