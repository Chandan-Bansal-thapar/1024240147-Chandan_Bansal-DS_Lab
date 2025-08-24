#include <iostream>
using namespace std;
int tridiagnal_matrix(){
        int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = 3 * n - 2;     
    int tri[size];            

    cout << "Enter " << size << " elements (lower diag, main diag, upper diag):\n";
    for (int i = 0; i < size; i++) {
        cin >> tri[i];
    }

    cout << "\nTri-diagonal Matrix:\n";
    int k = 0;  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1) {        
                cout << tri[k++] << " ";
            } else if (i == j) {     
                cout << tri[k++] << " ";
            } else if (j - i == 1) { 
                cout << tri[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
int main() {
    tridiagnal_matrix();
    return 0;
}