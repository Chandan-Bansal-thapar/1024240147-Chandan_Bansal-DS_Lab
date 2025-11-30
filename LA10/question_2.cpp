#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,int>m1;
    int a[] ={1,2,3,4};
    int b[] = {3,4,6,7};
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
        (m1[a[i]])++;
    }
   for (int i = 0; i < n; i++)
   {
      if(m1[b[i]]==1){
        cout<<b[i]<<" ";
      }
   }
   

    return 0;
}