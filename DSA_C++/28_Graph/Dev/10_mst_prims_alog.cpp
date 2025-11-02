#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list

    unordered_map<int, list<pair<int, int>>> adj;

    // yaha ek bat sure karlo ki node 1 se start ho rahi hain ya 0 se
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // ab 3 data structure banane hain

    vector<int> key(n + 1);
    // yaha n+1 isliye  as i am reperesenting the node with the same index
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {

        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // lets start the algo

    key[1] = 0; // yaha src node 1 se start ho rahi hain

    parent[1] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u; // iske basis per hum mst mein true mark karenge
               // find the mini wali node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true in mst
        mst[u] = true;

        // check its adjacent nodes

        for (auto it : adj[u])
        {

            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    // loop na hi 0 as no mapping for 0
    // se chalega nahi 1 se as 1 ka parent toh -1 hain
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}