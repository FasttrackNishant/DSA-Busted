class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        vector<int> ans;

        for(int i = 0 ; i < n ; i++)
        {
            mp[nums[i]]++;
        }

        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }

        while(pq.size() > k)
        {
            pq.pop();
        }

        while(!pq.empty())
        {
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        
        return ans;
    }
};