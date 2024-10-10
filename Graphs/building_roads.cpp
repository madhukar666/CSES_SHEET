#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<int> adj[100001];
bool visited[100001];
void dfs(ll s)
{
    visited[s] = true;

    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            dfs(u);
        }
    }
}
int main()
{

    ll V, E;
    cin >> V >> E;

    for (ll i = 0; i < E; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll count = 0;
    vector<ll> ans;
    for (ll i = 1; i <= V; i++)
    {
        if (visited[i] == false)
        {
            count++;
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << count - 1 << "\n";
    ll size = ans.size();
    for (ll i = 1; i < size; i++)
    {
        cout << ans[i - 1] << " " << ans[i] << "\n";
    }
}