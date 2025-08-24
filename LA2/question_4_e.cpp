#include <iostream>
using namespace std;

int main() {
    string str1,str2;
    cout<<"Enter your string value: ";
    cin>>str1;
    int size = str1.length();
    for (int i = 0; i < size; i++)
    {
       int a = static_cast<int>(str1.at(i));
       int upper = a-32;
       char character = static_cast<char>(upper);
       str2 += character; 
    }
    cout<<str2;
    return 0;
}