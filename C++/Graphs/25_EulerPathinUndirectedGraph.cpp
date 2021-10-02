int eulerPath(int N, vector<vector<int>> graph)
{
    // code here
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 1)
            {
                ans[i]++;
                ans[j]++;
                graph[j][i] = 0;
            }
        }
    }
    int oddCount = 0;
    for (auto it : ans)
    {
        if (it % 2 != 0)
            oddCount++;
    }
    return (oddCount == 2 or oddCount == 0) ? 1 : 0;
}