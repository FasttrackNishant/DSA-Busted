

class Solution {
public:
    int distance (int x1 , int y1)
    {
        int dist =  x1*x1 + y1*y1;
        return dist;

    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n =  points.size();
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> ans;

        int index = 0;
        for(auto it : points)
        {
            int first = it[0];
            int second = it[1];
        
            int dist = distance(first,second);
            cout<<dist<<endl;
            pq.push({dist,index});

            if(pq.size() > k)
                pq.pop();

            index++;
        }
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            ans.push_back(points[top.second]);
        }

        return ans;
    }
};