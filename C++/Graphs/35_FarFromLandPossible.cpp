int bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int n)
{
    int maxDist = 0;
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int a = x + dir[k][0];
            int b = y + dir[k][1];
            if (a >= 0 and b >= 0 and a < n and b < n and grid[a][b] == 0)
            {
                grid[a][b] = grid[x][y] + 1;
                maxDist = max(maxDist, grid[a][b]);
                q.push({a, b});
            }
        }
    }
    return maxDist - 1;
}

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    return bfs(grid, q, n);
}