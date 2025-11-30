#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,int>m1;
    int a[] ={1,2,3,1};
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i <= n; i++)
    {
        (m1[a[i]])++;
        if(m1[a[i]]==2){
            cout<<"yes duplicate element is exist";
            break;
        }
    }
    return 0;
}