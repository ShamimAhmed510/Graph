#include <bits/stdc++.h>
using namespace std;
//https://cses.fi/problemset/task/1668/
const int N = 1e5 + 5;
vector<int> adj[N];
int color[N];
bool possible = true;

void dfs(int node, int c)
{
    color[node] = c;

    for (int u : adj[node])
    {
        if (color[u] == 0)
        {
            dfs(u, 3 - c);
        }
        else if (color[u] == color[node])
        {
            possible = false;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 0)
        {
            dfs(i, 1);
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << color[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
