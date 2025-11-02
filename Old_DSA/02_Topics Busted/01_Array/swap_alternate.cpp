/*swap alternate

[1,3,4,3,5,7] --> [3,1,3,4,7,5]
[3,4,6,3]   --> [4,3,3,6 ]
*/

#include <iostream>
using namespace std;

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swapalternate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
int main()
{
    int even[5] = {2, 3, 7, 4};
    int odd[5] = {8, 5, 4, 1, 6};

    swapalternate(even, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << even[i] << " ";
    }
    cout << endl;

    swapalternate(odd, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << odd[i] << " ";
    }

    return 0;
}