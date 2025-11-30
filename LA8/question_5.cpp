#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;

    if(largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void minHeapify(vector<int>& a, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] < a[smallest]) smallest = left;
    if(right < n && a[right] < a[smallest]) smallest = right;

    if(smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void heapSortAscending(vector<int>& a) {
    int n = a.size();
    for(int i=n/2-1;i>=0;i--) maxHeapify(a,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

void heapSortDescending(vector<int>& a) {
    int n = a.size();
    for(int i=n/2-1;i>=0;i--) minHeapify(a,n,i);
    for(int i=n-1;i>=0;i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
}

int main() {
    vector<int> a = {8, 3, 5, 1, 9, 4};
    vector<int> b = a;

    heapSortAscending(a);
    heapSortDescending(b);

    cout << "Increasing: ";
    for(int x: a) cout << x << " ";

    cout << "\nDecreasing: ";
    for(int x: b) cout << x << " ";
}
