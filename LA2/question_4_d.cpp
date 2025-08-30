#include <iostream>
using namespace std;

int main() {
    string str1,str2;
    cout<<"Enter your string value: ";
    cin>>str1;
    int size = str1.length();
    int arr[size];
    for (int i = 0; i < size; i++)
    {
       arr[i] = static_cast<int>(str1.at(i)); 
    }
      for(int i = 0;i<size-1;i++){
    for (int j = 0; j <size-i-1; j++)
    {
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
   }
   for (int i = 0; i < size; i++)
   {
   char character = static_cast<char>(arr[i]);
   str2 += character; 
   }
   cout<<str2;
    return 0;
}