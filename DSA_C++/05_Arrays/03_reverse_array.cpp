#include <iostream>
using namespace std;

void reverse(int arr[],int n)
{
    int s= 0 ; 
    int e = n-1;

    while(s < e)
    {
        swap(arr[s++],arr[e--]);
    }

}

int main() {
    int arr[] = {23,33,12,22};

    reverse(arr,4);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }

    return 0;
}