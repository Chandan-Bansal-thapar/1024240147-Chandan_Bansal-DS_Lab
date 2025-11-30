#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> h;

    void heapifyUp(int i) {
        int p = (i - 1) / 2;
        if (i > 0 && h[i] > h[p]) {
            swap(h[i], h[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int n = h.size();
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if (l < n && h[l] > h[largest]) largest = l;
        if (r < n && h[r] > h[largest]) largest = r;

        if (largest != i) {
            swap(h[i], h[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int x) {
        h.push_back(x);
        heapifyUp(h.size() - 1);
    }

    int getMax() {
        if (h.empty()) return -1;
        return h[0];
    }

    int extractMax() {
        if (h.empty()) return -1;
        int maxVal = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);
        return maxVal;
    }

    void display() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(40);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(60);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Max: " << pq.getMax() << endl;

    pq.extractMax();
    cout << "After extractMax: ";
    pq.display();

    return 0;
}
