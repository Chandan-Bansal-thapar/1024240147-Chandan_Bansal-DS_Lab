#include <iostream>
using namespace std;
const int maxsize = 30;
int size = 7;
int arr [maxsize];
void create(){
  int i,n;
 for(i=0;i<size;i++){
    cout<<"Enter your array Element";
    cin>>n;
    arr[i] = n; 
 }   
 cout<<"Array is successfully created"<<endl;
}
void display(){
    int i,n;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insert(){
int i;
int pos,val;
cout<<"Enter your position"<<endl;
cin>>pos;
cout<<"Enter your value"<<endl;
cin>>val;
for(i = size;i>=pos-1;i--){
    arr[i+1] = arr[i];
}
arr[pos-1] = val;
size++;
}
void del(){
    /*pos = val = 0
    i = pos -1
    size + 1 
    */

int pos,val,i;
cout<<"Enter your position"<<endl;
cin>>pos;
arr[pos-1] = 0;
for(i=pos-1;i<size;i++){
    arr[i] = arr[i+1];
} 
size--;
}
void liner(){
int i,val;
cout<<"Enter your value"<<endl;
cin>>val;
for(i=0;i<size;i++){
if(val == arr[i]){
    cout<<i<<endl;
    break;
}
}
}
void option(){
      cout<<"1. Create array"<<endl;
    cout<<"2. display array"<<endl;
    cout<<"3. insert array"<<endl;
    cout<<"4. delete array"<<endl;
    cout<<"5. search a element in array"<<endl;  
    cout<<"6. Stop "<<endl;  
}
int main(){
    int n;
    option();
    cout<<"chose your option(1,2,3,4,5)"<<endl;
    cin>>n;
while (n<6)
{
switch (n)
{
case 1:
    create();
    break;
case 2:
    display();
    break;
case 3:
 insert();
    break;
case 4:
del();
    break;
case 5:
liner();
break;        
default:
    break;
}
option();
   cout<<"chose your option(1,2,3,4,5)"<<endl;
 cin>>n;
}
return 0;
}