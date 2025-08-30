#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,6,7};
    int size = sizeof(arr)/sizeof(int);
    int low = 0,High=size-1,first = arr[0];
      while (low <= High) {
        int mid = (low + High) / 2;
        if ((arr[mid] - first) == mid) {
            low = mid + 1;
        } 
        else {
            High = mid - 1;
        }
    }
    cout<<"missing number is : "<<first+low;
    return 0;
}
