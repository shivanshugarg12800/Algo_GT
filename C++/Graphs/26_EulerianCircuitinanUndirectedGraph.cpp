bool isEularCircuitExist(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            ans[it]++;
        }
    }
    int cnt = 0;
    for (auto it : ans)
        if (it % 2 != 0)
            cnt++;
    return cnt == 0 ? true : false;
}