#include <iostream>
using namespace std;

int findMax(int arr[],int n )
{
    int maxi = INT_MIN;

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    return maxi;

}

int findMin(int arr[] , int n )
{
    int mini = INT_MAX;

    for(int i =0 ; i < n  ; i++)
    {
        if(mini > arr[i] )
        {
            mini = arr[i];
        }
    }
    return mini;
}

int main() {

    int arr[] = {23,12,10,44,33};

    int maxElement = findMax(arr,5);
    cout<<"Max "<<maxElement<<endl;

    int minElement = findMin(arr,5);
    cout<<"Mini "<<minElement<<endl;
    
    
    return 0;
}