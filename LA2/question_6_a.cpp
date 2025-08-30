#include <iostream>
using namespace std;

#define MAX 100

void display(int mat[][3], int nonZero) {
    cout << "Row Col Value\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void transpose(int mat[][3], int trans[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int nonZero = mat[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nonZero; i++) {
            if (mat[i][1] == c) {
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

int main() {
    int mat[MAX][3] = {
        {4, 5, 6},   
        {0, 2, 3},
        {0, 4, 4},
        {1, 2, 5},
        {1, 3, 7},
        {3, 1, 2},
        {3, 2, 6}
    };

    int n = mat[0][2];

    cout << "Original Triplet Representation:\n";
    display(mat, n);

    int trans[MAX][3];
    transpose(mat, trans);

    cout << "\nTranspose Triplet Representation:\n";
    display(trans, n);

    return 0;
}
