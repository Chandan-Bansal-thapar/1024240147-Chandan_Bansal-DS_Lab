#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    cout<<"Enter Your string value: ";
    cin>>str1;
    int size = str1.length();
    for (int i = size-1; i >= 0; i--)
    {
        str2+=(str1.at(i));
    }
    cout<<str2;
    return 0;
}