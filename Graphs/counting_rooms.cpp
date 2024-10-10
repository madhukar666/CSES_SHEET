#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char grid[1001][1001];
bool visited[1001][1001];

int N, M;

bool isvalid(int i, int j)
{
    if (i < 1 || i > N || j < 1 || j > M || grid[i][j] == '#')
        return false;
    return true;
}

void dfs(int i, int j)
{
    visited[i][j] = true;
    if (isvalid(i, j + 1) && visited[i][j + 1] == false)
        dfs(i, j + 1);
    if (isvalid(i, j - 1) && visited[i][j - 1] == false)
        dfs(i, j - 1);
    if (isvalid(i + 1, j) && visited[i + 1][j] == false)
        dfs(i + 1, j);
    if (isvalid(i - 1, j) && visited[i - 1][j] == false)
        dfs(i - 1, j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (grid[i][j] == '.' && visited[i][j] == false)
            {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << "\n";
}