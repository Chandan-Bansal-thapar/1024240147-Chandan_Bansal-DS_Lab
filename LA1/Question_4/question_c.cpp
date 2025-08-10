#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3] = {{1,2,3},{4,6,9},{5,11,34}};
    int transporsematrix[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        transporsematrix[j][i] = matrix[i][j];
        }
        cout<<endl;
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
         cout<<transporsematrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}