// heapSortMaxDesc.cpp
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

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

void heapSortMaxAsc(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Step 2: Extract from heap and rebuild
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortMaxDesc(vector<int>& arr) {
    heapSortMaxAsc(arr); // Sort ascending first
    reverse(arr.begin(), arr.end()); // Reverse to get descending
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapSortMaxDesc(arr);

    cout << "Max-Heap → Descending Order: ";
    for (int x : arr) cout << x << " ";
    return 0;
}