#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> gr[], bool *visited, vector<int> &stack)
{
    visited[node] = true;
    for (auto x : gr[node])
    {
        if (!visited[x])
            dfs(x, gr, visited, stack);
    }
    stack.push_back(node);
}

void dfs2(int node, vector<int> rev[], bool *visited, vector<int> &temp)
{
    visited[node] = true;
    temp.push_back(node);
    for (auto x : rev[node])
    {
        if (!visited[x])
            dfs2(x, rev, visited, temp);
    }
}

void kosarajuAlgo(int n, vector<int> gr[], vector<int> rev[])
{
    bool visited[n] = {false};
    vector<int> stack;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, gr, visited, stack);
    }
    memset(visited, false, n);
    reverse(stack.begin(), stack.end());
    set<int> s;
    for (auto x : stack)
    {
        if (!visited[x])
        {
            vector<int> temp;

            dfs2(x, rev, visited, temp);

            if (temp.size() >= 3)
                for (auto it : temp)
                    s.insert(it);

            temp.clear();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(i) != s.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int N = 1e5 + 1;
    vector<int> gr[N], rev[N];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        gr[x].push_back(y);
        rev[y].push_back(x);
    }
    kosarajuAlgo(n, gr, rev);
}
