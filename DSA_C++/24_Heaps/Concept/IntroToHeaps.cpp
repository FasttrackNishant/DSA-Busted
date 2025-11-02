#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100]; // 1-based indexing
    int size;

    // Constructor
    Heap()
    {
        arr[0] = -1; // Dummy value at index 0
        size = 0;
    }

    // Insert a new value into the heap
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        // Percolate up to restore max-heap property
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Delete root node from the heap
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "No data to delete" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        size--;

        // Step 2: Heapify down from root to restore max-heap
        int i = 1;
        while (true)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

    // Print the heap
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> arr, int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;

    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(4);
    h.insert(25);

    cout << "Heap after insertions: ";
    h.print();

    h.deleteRoot(); // Only deletes root (maximum element)
    cout << "Heap after deleting root: ";
    h.print();

    // for loop
    vector<int> arr = {4, 10, 3, 5, 1};
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }

    heapSort(arr, 5);
    cout << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}