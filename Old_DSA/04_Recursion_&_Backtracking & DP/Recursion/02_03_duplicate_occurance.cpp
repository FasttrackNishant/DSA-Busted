#include <iostream>
#include <vector>
using namespace std;

int findfirst(int arr[], int index, int size, int target)
{

    // base case
    if (index == size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    else
    {
        return findfirst(arr, index + 1, size, target);
    }
}

int findlast(int arr[], int size, int index, int target)
{
    // base case
    if (index < 0)
        return -1;

    if (arr[index] == target)
        return index;

    return findlast(arr, size, index - 1, target);
}

void alloccur(int arr[], int index, int size, int target, vector<int> &vec)
{

    // base case

    if (index == size)
        return;

    if (arr[index] == target)
    {
        vec.push_back(index);
    }

    alloccur(arr, index + 1, size, target, vec);
}

int main()
{
    int arr[] = {2, 6, 15, 3, 1, 2, 5, 3, 8, 2};
    int size = sizeof(arr) / 4;
    cout << endl;
    cout << "Element present at " << findfirst(arr, 0, size, 5);
    cout << endl;
    
                      
    cout << "Findlast :- " << findlast(arr, size, size - 1, 3);
    cout << endl;



    //all occurrance                       
    vector<int> vec;
    cout << "Occurrences are ";
    alloccur(arr, 0, size, 2, vec);
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}