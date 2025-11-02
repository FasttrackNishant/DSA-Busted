#include <iostream>
using namespace std;

void saydigit(string arr[], int n)
{
    int digit;
    if (n == 0)
    {
        return;
    }
    digit = n % 10;
    n = n / 10;

    // this will print  214   
    saydigit(arr, n);
    cout << arr[digit] << " ";

    // this will print  412 
    //   saydigit(arr, n);
    //  cout << arr[digit]<<" ";
}
int main()
{
    string arr[10] = {"zero", "one", "two",
                      "three",
                      "four",
                      "five",
                      "six", "seven", "eight", "nine"};

    int n = 412;
    // cin>>n;
    cout << endl
         << endl
         << endl;
    saydigit(arr, n);
    cout << endl
         << endl
         << endl;

    cout << endl;
    return 0;
}