class Solution {
  public:
    int solve(long long A[] ,int N , int k )
    {
        priority_queue<long long int> pq;
        for(int i = 0 ; i < N ; i++)
        {
            int element = A[i];
            
            pq.push(element);
            
             if(pq.size() > k)
             {
                 pq.pop();
             }
            
        }
        
        return pq.top();
    }
    
    
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
       
       
       
       long long int ans = 0;
       
       long long int left = solve(A,N,K1);
       long long int right = solve(A,N,K2);
       
       
       for(int i = 0; i < N ; i++)
       {
           if(A[i] > left && A[i] < right)
           {
               ans += A[i];
           }
       }
       
       return ans;
    }
};