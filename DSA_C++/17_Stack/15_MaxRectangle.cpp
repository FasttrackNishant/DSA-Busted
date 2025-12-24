class Solution {
  public:
  
     vector<int> prevSmaller(int n, vector<int>& nums) {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(int n, vector<int>& nums) {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev = prevSmaller(n, heights);
        vector<int> next = nextSmaller(n, heights);

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (next[i] == -1) {
                next[i] = n;
            }

            int breadth = next[i] - prev[i] - 1;
            int length = heights[i];

            int area = breadth * length;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
    
    
    int maxArea(vector<vector<int>> &mat) {
    
        int n = mat.size();
        int m = mat[0].size();
        
        // calcuate ans for the first row
        int area = largestRectangleArea(mat[0]);
        
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                // row update by prev val
                if(mat[i][j] != 0)
                    mat[i][j] += mat[i-1][j];
                else
                    mat[i][j] = 0;
            }
            
            area = max(area ,largestRectangleArea(mat[i]));
        }
        
        return area;
        
    }
};  