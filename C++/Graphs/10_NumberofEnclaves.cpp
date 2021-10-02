void dfsHelper(int i, int j, int n, int m, vector<vector<int>> &board, vector<vector<int>> &dir)
{
    board[i][j] = -1;
    for (int d = 0; d < 4; d++)
    {
        int x = i + dir[d][0];
        int y = j + dir[d][1];

        if (x >= 0 and y >= 0 and x < n and y < m and board[x][y] == 1)
            dfsHelper(x, y, n, m, board, dir);
    }
}

int numEnclaves(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();

    if (n == 0 or m == 0)
        return -1;

    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 1)
            dfsHelper(i, 0, n, m, board, dir);
        if (board[i][m - 1] == 1)
            dfsHelper(i, m - 1, n, m, board, dir);
    }

    for (int j = 0; j < m; j++)
    {

        if (board[0][j] == 1)
            dfsHelper(0, j, n, m, board, dir);

        if (board[n - 1][j] == 1)
            dfsHelper(n - 1, j, n, m, board, dir);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
                count++;
        }
    }
    return count;
}