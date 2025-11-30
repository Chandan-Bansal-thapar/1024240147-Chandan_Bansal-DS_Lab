#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIndex]) minIndex=j;
        }
        swap(a[i],a[minIndex]);
    }
}

int main() {
    int a[]={8,3,5,2,9};
    int n=5;
    selectionSort(a,n);
    for(int i=0;i<n;i++){ 
        cout<<a[i]<<" ";
    }
}
