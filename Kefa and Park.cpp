//codeforces.com/contest/580/problem/C

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int cat[100005];
int n,m;
int ans = 0;

void dfs(int node, int parent, int val)
{
    //val hocche current node er parent er consecutiveness value

    if(cat[node]==0) val = 0;
    else val = val+1;
    //val hocche current node er consecutiveness value

    if(val>m) return;

    for(auto u:adj[node])
    {
        if(u==parent) continue;

        dfs(u, node, val);
    }

    //current node leaf ki na
    if( node != 1 and (int)adj[node].size() == 1) ans++;
}


int main()
{
    cin>>n>>m;

    for(int i=1; i<=n; ++i) cin>>cat[i];

    for(int i=0; i<n-1; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1,0);

    cout<<ans<<endl;



}

