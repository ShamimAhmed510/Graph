//BFS
//shortest path using bfs

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0; i<m; ++i)
    {
        int u,v;
        cin>>u>>v;
        // adj[u].push_back(make_pair(v,w));
        // adj[v].push_back(make_pair(u,w));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int visited[n+1];
    int level[n+1];
    for(int i=0; i<=n; ++i) visited[i] = 0;

    queue<int> q;
    //queue.push() -> pichone push
    //queue.front() -> shamne k ase
    //queue.pop() -> shamner jon k ber kore dey
    int source = 3;
    q.push(source);
    visited[source] = 1;
    level[source] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<' ';
        for(auto u:adj[node])
        {
            if(!visited[u])
            {
                //ekhono eita visit kori nai
                //line er shesh e push korbo
                visited[u] = 1;
                level[u] = level[node]+1;
                q.push(u);
            }
        }

    }

    cout<<endl;
    cout<<level[6]-1<<endl;

}
