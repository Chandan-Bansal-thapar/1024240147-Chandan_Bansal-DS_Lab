#include <iostream>
using namespace std;

#define MAX 100

void display(int mat[][3]) {
    int nonZero = mat[0][2];
    cout << "Row Col Value\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void multiplySparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible (invalid dimensions).\n";
        return;
    }

    int rowsA = A[0][0], colsA = A[0][1], nzA = A[0][2];
    int rowsB = B[0][0], colsB = B[0][1], nzB = B[0][2];

    C[0][0] = rowsA;
    C[0][1] = colsB;
    int k = 1;


    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;

      
            for (int p = 1; p <= nzA; p++) {
                if (A[p][0] == i) {
                    
                    for (int q = 1; q <= nzB; q++) {
                        if (B[q][0] == A[p][1] && B[q][1] == j) {
                            sum += A[p][2] * B[q][2];
                        }
                    }
                }
            }

            if (sum != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = sum;
                k++;
            }
        }
    }

    C[0][2] = k - 1; 
}

int main() {

    int A[MAX][3] = {
        {3, 3, 4},  
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3},
        {2, 0, 4}
    };

    
    int B[MAX][3] = {
        {3, 3, 4},  
        {0, 0, 5},
        {1, 2, 6},
        {2, 0, 7},
        {2, 2, 8}
    };

    int C[MAX][3]; 

    cout << "Matrix A (Triplet):\n";
    display(A);

    cout << "\nMatrix B (Triplet):\n";
    display(B);

    multiplySparse(A, B, C);

    cout << "\nResult (A x B) in Triplet Form:\n";
    display(C);

    return 0;
}

