

#include <iostream>
#include <bits/stdc++.h>
#define yy cout << "YES" << "\n"
#define nn cout << "NO" << "\n"

using namespace std;

typedef long long int ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> topologicalSort(int n, vector<int> adj[], vector<int> &indegree)
{

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {

        if (indegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty())
    {

        int u = q.front();
        q.pop();

        for (auto i : adj[u])
        {

            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> topo_sort = topologicalSort(n, adj, indegree);

    vector<int> p(n + 1, -1);
    vector<int> distance(n + 1, INT_MIN);

    distance[1] = 0;

    for (auto u : topo_sort)
    {
        if (distance[u] != INT_MIN)
        {
            for (auto v : adj[u])
            {
                if (distance[v] < distance[u] + 1)
                {
                    distance[v] = distance[u] + 1;
                    p[v] = u;
                }
            }
        }
    }

    if (distance[n] == INT_MIN)
        cout << "IMPOSSIBLE" << "\n";
    else
    {

        vector<int> path;

        int x = n;
        while (x != -1)
        {
            path.push_back(x);
            x = p[x];
        }
        reverse(path.begin(), path.end());

        cout << distance[n] + 1 << "\n";

        for (auto i : path)
            cout << i << " ";
        cout << "\n";
    }
}