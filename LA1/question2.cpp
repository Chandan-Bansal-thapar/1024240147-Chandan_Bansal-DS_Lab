#include <iostream>
using namespace std;
int main(){
    int arr [] = {34,64,63,23,53,34,63,2,64,45,63,23,52,2,10,34,54,53,10,23,79};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for ( int j = 0; j < size; j++)
        {
            if(i != j && arr[i]==arr[j]){
                arr[j] = 0;
                for (int k = j; k < size; k++)
                {
                    arr[k]=arr[k+1];
                }
                size--;
            }
        }
    }
    for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}