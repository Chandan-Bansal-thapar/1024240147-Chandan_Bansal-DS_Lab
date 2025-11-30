#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n){
    int left=0, right=n-1;
    while(left<right){
        int minIndex=left, maxIndex=right;
        if(a[minIndex]>a[maxIndex]) swap(a[minIndex],a[maxIndex]);
        for(int i=left+1;i<right;i++){
            if(a[i]<a[minIndex]) minIndex=i;
            else if(a[i]>a[maxIndex]) maxIndex=i;
        }
        swap(a[left],a[minIndex]);
        swap(a[right],a[maxIndex]);
        left++;
        right--;
    }
}

int main(){
    int a[]={8,3,5,2,9,1};
    int n=6;
    improvedSelectionSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
