#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long int ll;
const int M = 1e9+7;
const int N = 1e6+10;

stack<int> st;
int cnt = 0;

void dfs(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    for (auto i : adj[s]) {
        if (!visited[i]) {
            dfs(adj, i, visited);
        }
    }
    st.push(s);
}

void dfs_again(vector<vector<int>>& adj_t, int s, vector<bool>& visited, vector<int>& scc) {
    visited[s] = true;
    scc[s] = cnt;
    for (auto i : adj_t[s]) {
        if (!visited[i]) {
            dfs_again(adj_t, i, visited, scc);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 1st DFS to fill the stack with finishing times
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, i, visited);
        }
    }

    // Transpose the graph
    vector<vector<int>> adj_t(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto u : adj[i]) {
            adj_t[u].push_back(i);
        }
    }

    // Reset the visited array for the second DFS
    fill(visited.begin(), visited.end(), false);

    vector<int> scc(n + 1, 0);

    // Process all vertices in order defined by the stack
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            cnt++;
            dfs_again(adj_t, u, visited, scc);
        }
    }

    // Output the number of SCCs
    cout << cnt << "\n";

    // Output the SCC assignment for each node
    for (int i = 1; i <= n; i++) {
        cout << scc[i] << " ";
    }
    cout << "\n";

    return 0;
}
