

#include <iostream>
#include <bits/stdc++.h>

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

    vector<int> adj[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        for (auto u : adj[i])
            indegree[u]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            ans.push_back(i);
            q.push(i);
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
                ans.push_back(i);
                q.push(i);
            }
        }
    }
    if (ans.size() == n)
    {

        for (auto i : ans)
            cout << i << " ";
    }
    else
        cout << "IMPOSSIBLE";
    cout << "\n";
}