// Node Depth Calculation
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
vector<int>adj[N];
int visited[N];
int depth[N];

void dfs(int node, int parent)
{
    visited[node] = 1;
    cout<<node<<endl;
    for(auto u:adj[node])
    {
        if(visited[u]==0)
        {
            depth[u] = depth[node]+1;
            dfs(u, node);

        }
    }
}


int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; ++i)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(auto u:adj[1]) cout<<u<<' ';

    dfs(1,0);
    for(int i=1; i<=n; ++i) cout<<i<<" -> "<<depth[i]<<endl;
}
