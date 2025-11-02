#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Percolate up
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else break;
        }
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Percolate down
        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest]) largest = left;
            if (right <= size && arr[right] > arr[largest]) largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};