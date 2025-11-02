#include <iostream>
using namespace std;

void printarr(int arr[], int n, int start = 0)

//ye right most parameter se start hogi nahi toh fas jaoge 

// void printarr(int arr[], int n=0, int start=0 )

{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {1, 4, 7, 8, 9};
    printarr(arr, 5, 1);
    // ab is start ko by default zero banana hain toh kya kare sirf zero set kardo fuctino mein
    cout << endl;
    printarr(arr, 5);
    return 0;
}