
//cses.fi/problemset/task/1679/
#include <bits/stdc++.h>

using namespace std;


const int N =  1e5+4;
vector<int>adj[N];
int mark[N];
bool cycle = 0;
vector<int>topsort;

void dfs(int node)
{
    if(mark[node]==2)
    {
        return;
    }
    else if(mark[node]==1)
    {
        cycle = 1;
        return;
    }

    mark[node] = 1;

    for(auto u:adj[node])
    {
        dfs(u);
    }

    mark[node] = 2;
    topsort.push_back(node);
}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=n; ++i)
    {
        if(!mark[i]) dfs(i);
    }

    if(cycle==1) //cycle ase
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    for(int i=n-1; i>=0; --i)
    {
        cout<<topsort[i]<<' ';
    }
    cout<<endl;
}
