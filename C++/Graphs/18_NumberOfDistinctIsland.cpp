vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<string> dirChar{"U", "D", "R", "L"};
string island = "";
void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    grid[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1)
        {
            island += dirChar[k];
            dfs(grid, x, y, n, m);
            // check for the backward call
            island += "B";
        }
    }
}

int numberofDistinctIslands(vector<vector<int>> &grid)
{
    // write your code here
    int n = grid.size();
    int m = grid[0].size();

    set<string> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, n, m);
                s.insert(island);
                island = "";
            }
        }
    }
    return s.size();
}