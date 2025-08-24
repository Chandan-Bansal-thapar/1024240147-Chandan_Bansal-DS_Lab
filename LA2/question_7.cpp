#include <iostream>
using namespace std;

int main() {
    int inversion_cout = 0;
    int arr[] = {1,3,2,4};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
      for (int j = i+1; j < size; j++)
      {
        if (arr[i]>arr[j])
        {
           cout<<"("<<arr[i]<<","<<arr[j]<<")";
           inversion_cout++;
        } 
      }
    }
    cout<<endl;
    cout<<inversion_cout;
    return 0;
}