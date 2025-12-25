class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
       
       int n = arr.size();
       
       priority_queue<int , vector<int> , greater<int>> pq;
       
       int index = 0;
       for(int i = 0 ; i < n ;i++)
       {
           pq.push(arr[i]);
           
           if(pq.size() > k )
           {
               int top = pq.top();
               pq.pop();
               arr[index] = top;
               index++;
           }
           
       }
       
       while(!pq.empty())
       {
           arr[index++]= pq.top();
           pq.pop();
       }
       
    
       
    }
};