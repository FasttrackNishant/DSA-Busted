#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int k )
{
    for(int i=0 ; i < n ; i++)
    {
        if(k==arr[i]) return true;
    }
    return false;
}

int main() {
    int arr[] = {3,24,33,2,12};

    cout<<linearSearch(arr,5,24);

    return 0;
}