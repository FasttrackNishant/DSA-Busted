/*https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650*/

/*code studion pe tle mar gaya as iski time limit dp se solve hogin so tab tak ke liye good bye*/

#include <iostream>
using namespace std;

int stair(int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
    {
        return 1;
    }
    int ans =  stair(n-1)+stair(n-2);
    return ans;
}

int main()
{
    int a;
    cin >> a;
    int res = stair(a);
    cout << res << endl;
    return 0;
}