#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}


class Solution {
public:
    int mySqrt(int x) {

        if(x==0 ) return 0;
        
        int start = 1;
        int end = x;
        int ans = 1;
        while(start <= end)
        {
            long long int mid = start + ( end - start )/2;

            if(mid * mid <= x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};