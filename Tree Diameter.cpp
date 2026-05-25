//cses.fi/problemset/task/1131

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
    // int dx = farthest_dist;
    // cout<<"x = "<<x<<endl;

    farthest_node = x;
    farthest_dist = 0;
    fun(x,-1,0);
    int y = farthest_node;
    // cout<<"Y = "<<y<<endl;
    int dy = farthest_dist;

    cout<<dy<<endl;
}
