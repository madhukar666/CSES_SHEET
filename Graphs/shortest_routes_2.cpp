#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    // Initialize the cost matrix with LLONG_MAX (representing infinity)
    vector<vector<ll>> cost(n + 1, vector<ll>(n + 1, LLONG_MAX));

    // Input edges
    for (ll i = 0; i < m; i++)
    {
        ll a, b, d;
        cin >> a >> b >> d;
        cost[a][b] = min(cost[a][b], d); // In case of multiple edges, take the minimum
        cost[b][a] = min(cost[b][a], d); // Undirected graph
    }

    // Set diagonal to 0 (distance from a node to itself)
    for (ll i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }

    // Floyd-Warshall Algorithm to find shortest paths
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (cost[i][k] < LLONG_MAX && cost[k][j] < LLONG_MAX)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    // Process queries
    for (ll i = 0; i < q; i++)
    {
        ll u, v;
        cin >> u >> v;
        ll distance = cost[u][v];
        if (distance == LLONG_MAX)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << distance << "\n";
        }
    }

    return 0;
}
