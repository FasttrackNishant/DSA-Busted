class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        vector<int> ans ; 

        // priority queue -> maxheap
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < n ; i++)
        {
            int diff = abs(arr[i] - x);

            pq.push(make_pair(diff,i));

            if(pq.size() > k)
            {
                pq.pop();
            }
            
        }

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
        
            ans.push_back(arr[top.second]);
        }

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};