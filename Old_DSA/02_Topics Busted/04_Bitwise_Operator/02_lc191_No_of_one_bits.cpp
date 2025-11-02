#include <iostream>
using namespace std;

int binary(uint32_t n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }

    return count;
}
int main()
{
    uint32_t n;
    cin >> n;
   int result=  binary(n);
   cout<<result;

    return 0;
}