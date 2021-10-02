int find(int x, vector<int> &parent)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = find(parent[x], parent);
}
void unionSet(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int h1 = find(x, parent);
    int h2 = find(y, parent);
    if (h1 != h2)
    {
        if (rank[h1] < rank[h2])
        {
            parent[h1] = h2;
            rank[h2] += rank[h1];
        }
        else
        {
            parent[h2] = h1;
            rank[h1] += rank[h2];
        }
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    vector<int> ans;

    int n = edges.size();
    vector<int> parent(n + 1, -1);
    vector<int> rank(n + 1, 1);
    for (auto edge : edges)
    {
        int x = find(edge[0], parent);
        int y = find(edge[1], parent);

        if (x != y)
        {
            unionSet(x, y, parent, rank);
        }
        else
        {
            ans.push_back(edge[0]);
            ans.push_back(edge[1]);
        }
    }
    int c = ans.size();
    return {ans[c - 2], ans[c - 1]};
}