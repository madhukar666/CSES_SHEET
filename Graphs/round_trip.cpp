#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

bool dfs(int s, int n, vector<int> adj[], vector<bool> &vis, vector<int> &path, int parent)
{

    vis[s] = true;
    path.push_back(s);

    for (auto i : adj[s])
    {
        if (vis[i] == false)
        {
            if (dfs(i, n, adj, vis, path, s) == true)
            {
                return true;
            }
        }
        else if (i != parent)
        {
            path.push_back(i);
            return true;
        }
    }
    path.pop_back();
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {

        vector<int> a(2);
        cin >> a[0] >> a[1];
        edges.push_back(a);
    }

    vector<int> adj[n + 1];

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> vis(n + 1, false);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            vector<int> path;
            flag = dfs(i, n, adj, vis, path, -1);
            if (flag == true)
            {

                vector<int> cycle;
                cycle.push_back(path.back());
                int start = cycle[0];
                path.pop_back();
                while (path.back() != start)
                {
                    cycle.push_back(path.back());
                    path.pop_back();
                }
                cycle.push_back(start);

                cout << cycle.size() << "\n";

                for (auto i : cycle)
                    cout << i << " ";
                cout << "\n";
                break;
            }
        }
    }
    if (flag == false)
        cout << "IMPOSSIBLE" << "\n";
}