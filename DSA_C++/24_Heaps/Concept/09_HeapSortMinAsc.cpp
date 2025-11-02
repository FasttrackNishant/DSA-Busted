
// heapSortMinAsc.cpp
#include <iostream>
#include <vector>
using namespace std;

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

void heapSortMinAsc(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Min-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Step 2: Extract from heap and rebuild
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    reverse(arr.begin(), arr.end()); // Reverse to get ascending
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapSortMinAsc(arr);

    cout << "Min-Heap → Ascending Order: ";
    for (int x : arr) cout << x << " ";
    return 0;
}