#include <iostream>
using namespace std;
class queue{
private:
  int top = -1;
  int element [5];
  int n = sizeof(element)/sizeof(int);
  int f = -1;
  int r = -1;
public:
 int is_Empty(){
    if(f==-1||r==-1){
        return true;
    }
    else{
        return false;
    }
 }
 int isfull(){
    if(r==n-1){
        return true;
    }
    else
    {
        return false;
    }
}
 void enqueue(int val){
    if (isfull())
    {
        cout<<"overFlow";
    }
    else if(is_Empty()){
        f = f+1;
        r = r+1;
        element[r] = val; 
    }
    else
    {
        r = r+1;
        element[r] = val; 
    }
} 
 void dequeue(){
    if(is_Empty()){
        cout<<"underflow";
    }
    else
    {
        int item = element[f];
        f = f+1;
    }
    
 }
 int peek(){
     int top = element[f];
     return top;
 }
void display(){
    for (int i = f; i <= r; i++)
    {
       cout<<element[i]<<" "; 
    }
} 
};
int main() {
    queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();
    q.dequeue();
    cout<<q.peek();
    return 0;
}