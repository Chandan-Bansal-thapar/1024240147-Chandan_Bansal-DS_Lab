#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int,int>m1;
    int a[] ={2, 3, 2, 4, 3, 2};
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
        (m1[a[i]])++;
    }
    for (auto i:m1){
        cout<<i.first<<"--->"<<i.second<<endl;
    }

}