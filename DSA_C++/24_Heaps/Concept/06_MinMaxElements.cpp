#include <iostream>
#include <vector>
using namespace std;

// Return max (for max-heap)
int getMax(const vector<int> &maxHeap) {
    return maxHeap.empty() ? -1 : maxHeap[0];
}

// Return min (for min-heap)
int getMin(const vector<int> &minHeap) {
    return minHeap.empty() ? -1 : minHeap[0];
}

// Get value at specific index
int getElementAt(const vector<int> &heap, int i) {
    return (i >= 0 && i < heap.size()) ? heap[i] : -1;
}

int main() {
    vector<int> maxHeap = {60, 50, 20, 30, 10}; // already a max-heap
    vector<int> minHeap = {10, 30, 20, 60, 50}; // already a min-heap

    cout << "Max Element: " << getMax(maxHeap) << endl;
    cout << "Min Element: " << getMin(minHeap) << endl;
    cout << "Element at index 2 in maxHeap: " << getElementAt(maxHeap, 2) << endl;

    return 0;
}