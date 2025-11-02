#include <bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector < vector<int> & edges)
{

    vector<int> dist(n + 1, 1e9);
    {
        dist[src] = 0;

        for (int i = 0; i < = n; i++)
        {
            // traverse on edge list
            for (int j = 0; j < m; j++)
            {

                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2]
            }
        }
    }
}

int main()
{
    int a;
    cout << endl;
    return 0;
}