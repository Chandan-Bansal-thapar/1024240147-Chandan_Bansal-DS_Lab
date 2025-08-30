#include <iostream>
using namespace std;
int Diagnal_matrix(){
     int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int diag[n]; 

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> diag[i];
    }

    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main() {
    Diagnal_matrix();
    return 0;
}