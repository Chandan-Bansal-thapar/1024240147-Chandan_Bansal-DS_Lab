#include <iostream>
using namespace std;

int main() {
    int row = 3, column = 3;
    int matrix1[row][column] = {{1, 2, 4}, {6, 7, 23}, {8, 19, 11}};
    int matrix2[row][column] = {{43, 6, 7}, {21, 7, 30}, {45, 9, 4}};
    int multiplymatrix[row][column] = {0};

    // Matrix multiplication
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            multiplymatrix[i][j] = 0;
            for (int k = 0; k < column; k++) { 
                multiplymatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << multiplymatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
