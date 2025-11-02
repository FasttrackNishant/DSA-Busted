#include <iostream>
using namespace std;

bool search(int *arr, int size, int key)
{
    if (size == 0)
    {
        return false;
    }

    if(arr[0]==key)
    {
        return true;
    }
    else
    {
        bool remainingpart = search(arr + 1, size - 1, key);
        return remainingpart;
    }
}
int main()
{
    int arr[] = {3, 5, 1, 2, 6};
    bool res = search(arr, 5, 2);
    cout<<res;
    if (res)
    {
        cout << "element is present";
    }
    else
    {
        cout << "element is not present";
    }

    cout << endl;
    return 0;
}