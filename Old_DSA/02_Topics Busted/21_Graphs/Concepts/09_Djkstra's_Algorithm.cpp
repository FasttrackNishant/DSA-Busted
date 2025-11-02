#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // create adj list

    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // undirected graph hain

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // created distance array

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch top wali node

        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        // ab top wali ko remove kardo

        st.erase(st.begin());

        // neighbours ko traverse karo
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                // ab distance mil gaya but check karo ki set mein koi record hain ya nahi
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // agar mil gaya toh udade
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance ko update toh karo
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}