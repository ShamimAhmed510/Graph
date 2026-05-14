//checking if a graph is a tree or not
//n nodes n-1 edges
//connected

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

    if(m!= n-1)
    {
        cout<<"IT is not a tree"<<endl;
        return 0;
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

    bool flag = 1;
    for(int i=1; i<=n; ++i)
    {
        if(visited[i]==0)
        {
            flag = 0;
            break;
        }
    }

    if(flag == 0) cout<<"IT IS NOT A TREE"<<endl;
    else cout<<"IT IS A TREE"<<endl;


}
