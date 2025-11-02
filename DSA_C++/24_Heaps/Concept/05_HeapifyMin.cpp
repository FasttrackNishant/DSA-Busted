#include <iostream>
#include <vector>
using namespace std;

// Min-Heapify: ensures the subtree rooted at index 'i' follows min-heap property
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < n && arr[leftIdx] < arr[smallest])
        smallest = leftIdx;

    if (rightIdx < n && arr[rightIdx] < arr[smallest])
        smallest = rightIdx;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    int n = arr.size();

    // Build min-heap (heapify non-leaf nodes)
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    cout << "Min Heapified Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}