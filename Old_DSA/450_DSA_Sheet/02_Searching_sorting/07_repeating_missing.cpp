// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       
       vector<int> ans;
       sort(arr,arr+n);
      
       
       for(int i=1 ; i<n; i++)
       {
           if(arr[i-1]!= i)
           {
               ans.push_back(arr[i]);
               ans.push_back(i);
           }
       }
       
    
       // return problem exists
       
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        ob.findTwoElement(a, n);
       // cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends