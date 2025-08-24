#include <iostream>
using namespace std;

int main()
{
    string str1, vowal;
    vowal = "aeiou";
    cout << "Enter Your string value: ";
    cin >> str1;
    int size = str1.length();
    for (int i = 0; i <= size-1; i++)
    {
        for (int j = 0; j < vowal.length(); j++)
        {
            if (str1.at(i) == vowal.at(j))
            {
                str1.erase(i,1);
                size--;
                i--;
                break;
            }
        }
    }
    cout << str1;
    return 0;
}