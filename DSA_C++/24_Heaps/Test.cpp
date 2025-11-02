#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0; 
    }
    
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

       while(index > 1)
       {
            int parent = arr[index/2];

            if(arr[index] > parent)
            {
                swap(arr[index], parent);
                index++;
            }
            else
            {
                break;
            }
       }
    }

    void print()
    {
        for(int i =0 ; i < size; i ++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    vector<int> ans = {10,5,2,4,3};

    Heap h;

    for(auto i : ans)
    {
        h.insert(i);
    }

    h.print();

    return 0;
}