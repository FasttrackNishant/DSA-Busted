#include <iostream>
#include <vector>
using namespace std;

// =================== Max Heap using vector ===================
class MaxHeap {
public:
    vector<int> heap;

    MaxHeap() {}

    // Insert into max heap
    void insert(int val) {
        heap.push_back(val);
        int index = heap.size() - 1;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    // Get max element (root)
    int getMax() {
        return heap.size() > 0 ? heap[0] : -1;
    }

    // Print max heap
    void print() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

// ============= Heapify Function (Max for sorting) ============
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// ============= Heapify Function (Min) ============
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// =================== Heap Sort (Ascending) ===================
void heapSortAscending(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Sort
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// =================== Heap Sort (Descending) ===================
void heapSortDescending(vector<int>& arr) {
    int n = arr.size();

    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Sort
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

// =================== Main Function ===================
int main() {
    // Max Heap using class
    MaxHeap h;
    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    cout << "Max Heap after insertions: ";
    h.print();
    cout << "Max element: " << h.getMax() << endl;

    // Heap sort ascending
    vector<int> arr1 = {4, 10, 3, 5, 1};
    heapSortAscending(arr1);
    cout << "\nSorted (Ascending) using Max Heap: ";
    for (int val : arr1) cout << val << " ";

    // Heap sort descending
    vector<int> arr2 = {4, 10, 3, 5, 1};
    heapSortDescending(arr2);
    cout << "\nSorted (Descending) using Min Heap: ";
    for (int val : arr2) cout << val << " ";

    return 0;
}