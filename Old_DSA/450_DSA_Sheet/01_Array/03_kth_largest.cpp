// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int selctionsort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        int minindex = i;
        
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[minindex])
                {
                    minindex = j;
                }
            }

            swap( arr[minindex],arr[i]);
        
    }
}
void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {50,40,30,20,10};
    int n=2;
    int size = sizeof(arr) / 4;
    selctionsort(arr, size);
    printarr(arr, size);
   // cout<<"Enter the max Kth value "<<endl;
    // cin>>n;
  //  cout<<"K the max value is  "<<endl;
    cout<<arr[n-1];



    return 0;
}