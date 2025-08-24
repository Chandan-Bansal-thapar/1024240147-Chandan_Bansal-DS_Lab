#include <iostream>
using namespace std;

// Linear Search: O(n)
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // return index
        }
    }
    return -1; // not found
}

// Binary Search: O(log n)
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter number to search: ";
    cin >> target;

    // Linear Search
    int linearIndex = linearSearch(arr, n, target);
    if (linearIndex != -1)
        cout << "Linear Search: Found at index " << linearIndex << endl;
    else
        cout << "Linear Search: Not found" << endl;

    // Binary Search
    int binaryIndex = binarySearch(arr, n, target);
    if (binaryIndex != -1)
        cout << "Binary Search: Found at index " << binaryIndex << endl;
    else
        cout << "Binary Search: Not found" << endl;

    return 0;
}