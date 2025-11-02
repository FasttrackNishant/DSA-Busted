#include <iostream>
#include <vector>
using namespace std;

// Max-Heapify: ensures the subtree rooted at index 'i' follows max-heap property
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < n && arr[leftIdx] > arr[largest])
        largest = leftIdx;

    if (rightIdx < n && arr[rightIdx] > arr[largest])
        largest = rightIdx;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int main() {
    vector<int> arr = {34, 10, 23, 15, 41};
    int n = arr.size();

    // Build max-heap (heapify non-leaf nodes)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    cout << "Max Heapified Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}