#include<bits/stdc++.h>
using namespace std;
bool checkBipartiteHelper(int src, vector<vector<int>> &graph, vector<int> color)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // traverse all adjacent node
        for (auto it : graph[node])
        {
            if (color[it] == 0)
            {
                color[it] = 3 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(105, 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == 0)
        {
            if (!checkBipartiteHelper(i, graph, color))
            {
                return false;
            }
        }
    }
    return true;
}