#include <iostream>
using namespace std;
int main() {
    int count;
   int arr[] = {1,2,3,4,3,2,1};
   int n = sizeof(arr)/sizeof(int);
       for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }
            if (!isDuplicate) {
            count++;
        }
    }
    cout << "Total distinct elements = " <<count << endl;
    return 0;
}