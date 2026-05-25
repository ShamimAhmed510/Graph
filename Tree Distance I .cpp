
//cses.fi/problemset/task/1132

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int farthest_node, farthest_dist;

void fun(int node, int parent, int dist) //farthest node, distance
{
    //node hocche current node
    //dist root theke current node er distance

    if(dist > farthest_dist)
    {
        farthest_node = node;
        farthest_dist = dist;
    }

    for(auto u:adj[node])
    {
        if(u==parent) continue;
        fun(u, node, dist+1);
    }
}

int arr1[200005];
int arr2[200005];
bool f = 0;

void dfs(int node, int parent, int dist)
{
    if(f==0) arr1[node] = dist;
    if(f==1) arr2[node] = dist;

    for(auto u:adj[node])
    {
        if(u==parent) continue;

        dfs(u, node, dist+1);
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; ++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    farthest_node = 1;
    farthest_dist = 0;
    fun(1,-1,0);
    int x = farthest_node;

    farthest_node = x;
    farthest_dist = 0;
    fun(x,-1,0);
    int y = farthest_node;

    //x ar y endpoint 2 ta peye gesi

    //x theke shobgular distance arr1 e
    f = 0;
    dfs(x,-1,0);

    //y theke shobgular distance arr2 e
    f = 1;
    dfs(y,-1,0);

    for(int i=1; i<=n; ++i)
    {
        cout<<max(arr1[i],arr2[i])<<' ';
    }
    cout<<endl;
    return 0;
}

