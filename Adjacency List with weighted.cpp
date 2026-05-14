#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Standard C++ way
    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if graph is directed

        // adj[u].push_back(make_pair(v,w));
        // adj[v].push_back(make_pair(u,w)); // ebabe o push kora jay

    }

    for(int i = 1; i <= n; ++i)
    {
        cout << i << " -> { ";

        for(auto [j, w] : adj[i])
        {
            cout << "{" << j << ", " << w << "} ";
        }

        cout << "}" << endl;
    }

    return 0;
}
