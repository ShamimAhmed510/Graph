
//cses.fi/problemset/task/1667
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0; i<m; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[n+1];
    memset(visited,0,sizeof(visited));
    int dist[n+1];
    memset(dist,0,sizeof(dist));
    int previous[n+1];
    memset(previous,0,sizeof(previous));


    queue<int>q;
    q.push(1);
    visited[1] = 1;
    dist[1] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto v:adj[node])
        {
            if(visited[v]==0)
            {
                visited[v] = 1;
                dist[v] = dist[node]+1;
                previous[v] = node;
                q.push(v);

            }
        }
    }

    if(visited[n]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int>path;

    int current = n;
    path.push_back(n);
    while(current!=1)
    {
        current = previous[current];
        path.push_back(current);
    }

    cout<<path.size()<<endl;

    for(int i=path.size()-1; i>=0; --i)
    {
        cout<<path[i]<<' ';
    }

    cout<<endl;
}
