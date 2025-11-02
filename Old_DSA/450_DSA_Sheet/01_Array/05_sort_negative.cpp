#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)

    {

        int minindex = i;
        for (int j = i+1; j < size; j++)
        {

            if (arr[j] < 0 )
            {

                minindex = j;
            }
            else if( arr[minindex]>arr[j])
            {
                minindex =j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, -3, 4, -4, -5};
    int size = sizeof(arr) / 4;

    sort(arr, size);
    // printarr(arr, size);

    return 0;
}