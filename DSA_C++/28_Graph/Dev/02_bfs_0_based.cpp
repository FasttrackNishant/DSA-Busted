#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

/*
input : 
    5 6
    0 1
    0 2
    1 3
    1 4
    2 4
    3 4

*/

void bfs(int V , int E , vector<pair<int,int>> &edgeList, int index)
{

    // created adj list from the edge list
    unordered_map<int,list<int>> adjList;
    for(int i = 0 ;i < E ; i++)
    {
       int u = edgeList[i].first;
       int v = edgeList[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    unordered_map<int,bool> visited;
    visited[index] = true;
    queue<int> q;

    q.push(index);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(auto neighbours : adjList[node])
        {
            if(!visited[neighbours]){
                q.push(neighbours);
                visited[neighbours] = true;
            }
        }
    }
    cout << endl;
}


int main() {

    int V , E ;

    cout<<"Enter vertices"<<endl;
    cin>>V;

    cout<<"Enter edges"<<endl;
    cin>>E;

    vector<pair<int,int>> edgeList;
    int temp = E;
    while(temp--)
    {
        int u , v;
        cin>>u >>v;
        edgeList.push_back({u,v});
    }

    for(int i = 0 ; i < E ; i++)
    {
        cout<<edgeList[i].first<<" ";
        cout<<edgeList[i].second<<endl;
    }

    bfs(V,E,edgeList,0);
    
    return 0;
}