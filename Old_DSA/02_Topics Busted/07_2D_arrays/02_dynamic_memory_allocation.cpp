#include <iostream>
using namespace std;
int main()
{
    int a[5][5];
    // 2d array of 5 column and 5 rows

    int row;
    cin >> row;
    int column;
    cin >> column;

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }
    // dynamic 2d array created

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // releasing memory

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
        // here only array is freeed
    }

    delete[] arr; //it will free all the pointers
    
    
    /*
    dynamically jaggered array create karna hain
    */
    
    return 0;
}