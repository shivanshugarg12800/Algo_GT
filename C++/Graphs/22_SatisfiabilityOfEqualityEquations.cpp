int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return parent[x] = x;
    return parent[x] = find(parent[x], parent);
}

bool equationsPossible(vector<string> &equations)
{
    vector<int> parent(26, 0);
    for (int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }

    for (auto it : equations)
    {
        int x = find(it[0] - 'a', parent);
        int y = find(it[3] - 'a', parent);

        if (it[1] == '=')
            parent[x] = y;
    }
    for (auto it : equations)
    {
        int x = find(it[0] - 'a', parent);
        int y = find(it[3] - 'a', parent);

        if (it[1] == '!' and x == y)
            return false;
    }
    return true;
}