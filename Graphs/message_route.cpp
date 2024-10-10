#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long int ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Edge case: no edges and multiple nodes
    if (m == 0 && n > 1)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    vector<int> adj[n + 1];

    // Reading the edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Adding both directions for an undirected graph
        if (u != v)
        { // Ignore self-loops
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> dist(n + 1, INT_MAX); // Distance array initialized to a large value
    vector<int> parent(n + 1, -1);    // To store the parent node for path reconstruction

    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1] = 1; // Start at node 1, distance is 1

    // BFS for shortest path
    while (!q.empty())
    {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        // Explore neighbors
        for (auto node : adj[u])
        {
            if (dist[node] == INT_MAX)
            {
                dist[node] = d + 1;
                parent[node] = u;
                q.push({node, d + 1});
            }
        }
    }

    // If a path to node `n` exists
    if (dist[n] != INT_MAX)
    {
        cout << dist[n] << "\n"; // Print shortest distance

        vector<int> path;
        int u = n;

        // Reconstruct path from node `n` to node `1`
        while (u != -1)
        {
            path.push_back(u);
            u = parent[u];
        }

        // Reverse and print the path
        reverse(path.begin(), path.end());
        for (auto node : path)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
    else
    {
        // If no path exists
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}