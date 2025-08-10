#include <iostream>
using namespace std;
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0, j = 9;

    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}