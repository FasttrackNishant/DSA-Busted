#include <iostream>
using namespace std;

void sort012(int a[], int n)
{

    int zero,one , two ;
     zero = one = two = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero++;
        }
        else if (a[i] == 1)
        {
            one++;
        }
        else if (a[i] == 2)
        {
            two++;
        }
    }

    int arr[n];
    for (int j = 0; j < zero; j++)
    {
        arr[j] = 0;
    }

    for (int j = zero; j < zero+one; j++)
    {
        arr[j] = 1;
        // cout << "one loop" << endl;
    }

     for (int l = zero+one; l < zero+one+two; l++)
     {
         arr[l] = 2;
     }
    for (int i = 0; i < zero +one+two; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort012(a, n);

    return 0;
}
