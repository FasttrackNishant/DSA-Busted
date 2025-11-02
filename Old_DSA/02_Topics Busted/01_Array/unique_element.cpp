/*https://www.codingninjas.com/codestudio/problems/find-unique_625159*/

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, 3, 5, 5, 3, 2, 52};
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        ans = ans ^ arr[i];
    }

    cout << ans;
    return 0;
}