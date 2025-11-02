#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[101];  // 1-based indexing (index 0 is dummy)
    int size;

    MaxHeap() {
        arr[0] = -1;  // dummy value
        size = 0;
    }

    // Insert a new element into the heap
    void insert(int val) {
        size++;
        arr[size] = val;
        int index = size;

        // Percolate up to maintain heap property
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Delete root (max element)
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        // Heapify from root
        int index = 1;
        while (index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != index) {
                swap(arr[largest], arr[index]);
                index = largest;
            } else {
                break;
            }
        }
    }

    // Print all elements in the heap
    void print() {
        cout << "Heap: ";
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Get max element (root)
    int getMax() {
        if (size == 0) return -1;
        return arr[1];
    }

    // Get element at specific index (1-based)
    int getElementAt(int index) {
        if (index < 1 || index > size) return -1;
        return arr[index];
    }

    // Heapify for heap sort
    void heapify(int arr[], int size, int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

    // Heap Sort (Descending order for max heap)
    void heapSort() {
        int tempSize = size;
        for (int i = tempSize; i > 1; i--) {
            swap(arr[1], arr[i]);
            tempSize--;
            heapify(arr, tempSize, 1);
        }
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    h.print();
    cout << "Max element: " << h.getMax() << endl;
    cout << "Element at index 3: " << h.getElementAt(3) << endl;

    h.deleteRoot();
    cout << "After deleting root: ";
    h.print();

    h.heapSort();
    cout << "After heap sort (descending): ";
    for (int i = 1; i <= h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;

    return 0;
}