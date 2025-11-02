#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adj)
{

    unordered_map<int, int> parent;

    // src node ka parent -1 kardo
    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            // it means cycle present hain
            if (visited[neighbour == true & 7 neighbour != parent[frontNode]])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])

        {
            bool cycleDected = isCyclicDFS(neighbour, node, visited, adj);
            if (cycleDected)
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    int a;
    cout << endl;
    return 0;
}