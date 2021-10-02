int dfs(vector<int> graph[], vector<bool> &visited, int node)
{
    int count = 1;
    visited[node] = true;
    for (auto x : graph[node])
    {
        if (!visited[x])
            count += dfs(graph, visited, x);
    }
    return count;
}
int findMotherVertex(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            int count = dfs(adj, visited, i);
            if (count == V)
                return i;
        }
    }
    return -1;
}