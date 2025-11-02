#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction -> 0 undirected
        // direction -> 1 directed

        // ab u se v tak edge banao
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int a;
    cout << "Enter the number of nodes " << endl;
    cin >> a;

    int b;
    cout << "Enter the number of edges " << endl;
    cin >> b;

    Graph g;

    for (int i = 0; i < b; i++)
    {
        int u, v;
        cin >> u >> v;
        // created an graph and it is undirected
        g.addEdge(u, v, 1);
    }

    // printinh graph
    g.printadjlist();
    cout
        << endl;
    return 0;
}