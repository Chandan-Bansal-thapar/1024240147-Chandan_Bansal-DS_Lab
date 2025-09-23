#include <iostream>
using namespace std;
class circular_queue
{
private:
    int top = -1;
  int element [5];
  int n = sizeof(element)/sizeof(int);
  int f = -1;
  int r = -1;
public:
int isEmpty(){
    if (f==-1 && r==-1)
    {
        return true;
    }
    else{
        return false;
    }
}
int isfull(){
    if(f==(r+1)%n){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int val){
    if (isfull())
    {
        cout<<"overflow";
    }
    else
    {
        r = (r+1)%n;
        element[r] = val; 
    }
}
void dequeue(){
    if (isEmpty())
    {
        cout<<"underflow";
    }
    else
    {
        if(f==r){
            f = r-1;
        }
        else
        {
            f = (f+1)%n;
        } 
    }
}
void display(){
    for (int i = f; i <= r; i++)
    {
       cout<<element[i]<<" "; 
    }
} 
};
int main() {
    circular_queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();
    q.dequeue(); 
    return 0;
}