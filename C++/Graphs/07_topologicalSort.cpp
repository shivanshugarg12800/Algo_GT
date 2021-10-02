void topoSortHelper(vector<int> adj[], vector<bool> &visited, list<int> &l, int start)
{

    visited[start] = true;
    for (auto x : adj[start])
    {
        if (!visited[x])
            topoSortHelper(adj, visited, l, x);
    }
    l.push_front(start);
}

//Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    list<int> l;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topoSortHelper(adj, visited, l, i);
    }
    vector<int> vec;
    for (auto it : l)
    {
        vec.push_back(it);
    }
    return vec;
}