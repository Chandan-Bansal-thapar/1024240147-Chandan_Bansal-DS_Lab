#include <iostream>
using namespace std;
int main(){
    int sum_array = 0;
    int arr[3][5] = {{34,53,53,34,23},{76,7,4,21,9},{12,24,47,78,10}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum_array = sum_array + arr[i][j];
        }
        
    }
    cout<<sum_array;
    return 0;
}