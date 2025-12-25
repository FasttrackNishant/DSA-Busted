class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans =0;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            pq.push(arr[i]);
        }
        
        while(pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            int sum = first + second;
            ans += sum ;
            
            pq.push(sum);
            
        }
        
        
        return ans;
        
    }
};