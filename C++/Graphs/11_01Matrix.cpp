vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (auto it : dir)
        {
            int x = p.first + it[0];
            int y = p.second + it[1];
            if (x >= 0 and y >= 0 and x < n and y < m and ans[x][y] == -1)
            {
                q.push({x, y});
                ans[x][y] = ans[p.first][p.second] + 1;
            }
        }
    }

    return ans;
}