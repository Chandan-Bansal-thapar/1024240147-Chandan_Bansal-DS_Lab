#include <iostream>
using namespace std;

#define MAX 100

// Function to display sparse matrix in triplet form
void display(int mat[][3], int nonZero) {
    cout << "Row Col Value\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

// Function to add two sparse matrices in triplet form
void addSparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added (different dimensions).\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int aNZ = A[0][2], bNZ = B[0][2];

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= aNZ && j <= bNZ) {
        // Compare row & col of current elements
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { // Same row & col → add values
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    // Copy remaining elements
    while (i <= aNZ) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= bNZ) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1; // update non-zero count
}

int main() {
    // Example Sparse Matrix A
    int A[MAX][3] = {
        {4, 4, 4},  // rows, cols, non-zero
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 3},
        {3, 0, 6}
    };

    // Example Sparse Matrix B
    int B[MAX][3] = {
        {4, 4, 3},  // rows, cols, non-zero
        {0, 0, 7},
        {1, 2, 9},
        {3, 0, 4}
    };

    int C[MAX][3]; // Result matrix

    cout << "Matrix A (Triplet):\n";
    display(A, A[0][2]);

    cout << "\nMatrix B (Triplet):\n";
    display(B, B[0][2]);

    addSparse(A, B, C);

    cout << "\nResult (A + B) in Triplet Form:\n";
    display(C, C[0][2]);

    return 0;
}
