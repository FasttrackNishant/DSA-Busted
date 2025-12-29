class Solution {
public:
    int findMax(vector<int> & nums)
    {
        int maxi = INT_MIN;

        for(auto it : nums)
        {
            maxi = max(maxi , it);
        }

        return maxi;
    }

    long long int findHours(vector<int> &nums , int k )
    {
        long long int ans = 0;

        for(auto it : nums)
        {
            ans += ceil((double)it/(double)k);
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        int start = 1;
        int end = findMax(piles);

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            long long int hours = findHours(piles,mid);
          
            if(hours > h)
            {
                start = mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
        
        return start;
    }
};