// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

#include <iostream>
using namespace std;

void printarr(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void printUnion(int arr1[], int arr2[], int size1, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
 
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
 
        else {
            cout << arr2[j++] << " ";
            i++;
        }
    }
 
    /* Print remaining elements of the larger array */
    while (i < size1)
        cout << arr1[i++] << " ";
 
    while (j < size2)
        cout << arr2[j++] << " ";
}
 


int intersection(int arr1[], int arr2[], int size1, int size2)
{
    int array[size1];
    int k = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                array[k] = arr1[i];
                k++;
            }
        }
    }
    printarr(array, k);
}

int main()
{
    int arr1[3], arr2[3];
    int size1 = sizeof(arr1) / 4;
    int size2 = sizeof(arr2) / 4;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> arr2[i];
    }
    // intersection(arr1, arr2, size1, size2);
    printUnion(arr1, arr2, size1, size2);
    // printarr(arr1, arr2, size1, size2);
    return 0;
}