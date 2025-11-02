#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() {
        arr[0] = -1; // Dummy 0-index for easy indexing
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

    void print() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int getMax() {
        if (size == 0) return -1;
        return arr[1];
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

    cout << "Max Heap after insertions: ";
    h.print();

    cout << "Max element: " << h.getMax() << endl;
    
    return 0;
}