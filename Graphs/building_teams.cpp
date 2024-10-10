#include <iostream>
#include <bits/stdc++.h>
#define yy cout << "YES" << "\n"
#define nn cout << "NO" << "\n"

using namespace std;

typedef long long int ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

bool flag;
void dfs(int s, vector<int> adj[], int n, vector<int> &color, int c)
{

    color[s] = c;

    for (auto i : adj[s])
    {

        if (color[i] == -1)
        {

            if (c == 1)
                dfs(i, adj, n, color, 2);
            else
                dfs(i, adj, n, color, 1);
        }
        else if (color[i] == c)
        {
            flag = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    flag = true;
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

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {

        if (color[i] == -1)
            dfs(i, adj, n, color, 1);
    }
    if (flag)
    {
        for (int i = 1; i <= n; i++)
            cout << color[i] << " ";
    }
    else
        cout << "IMPOSSIBLE";
    cout << "\n";
}