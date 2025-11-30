#include <iostream>
using namespace std;

int partitionArr(int a[], int l, int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=partitionArr(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main(){
    int a[]={8,3,5,2,9};
    int n=5;
    quickSort(a,0,n-1);
       for(int i=0;i<n;i++){ 
        cout<<a[i]<<" ";
    }
}
