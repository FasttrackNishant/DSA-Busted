#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)

{

    // creat adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        // yaha nodes 1 se satrt ho hai hai and ye pair hain
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // find all indegrees

    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree walon ko push kardo queue mein

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs

    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // count increament karde
        cnt++;
        // neighbour indegree update karde
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    // ab check karo valid hain ya nahi
    if (cnt == n)
    {
        return false;
    }
    else
        return true;
}
int main()
{
    int a;
    cout << endl;
    return 0;
}