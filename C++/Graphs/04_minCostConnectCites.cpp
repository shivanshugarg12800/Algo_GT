#include <bits/stdc++.h>
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
    //	Write your code here.
    vector<pair<int, int>> *l = new vector<pair<int, int>>[n + 1];
    for (auto it : connections)
    {
        l[it[0]].push_back({it[1], it[2]});
        l[it[1]].push_back({it[0], it[2]});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    int ans = 0;
    int count = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        int node = p.second;
        int wgt = p.first;
        if (visited[node])
            continue;
        visited[node] = true;
        count++;
        ans += wgt;
        for (auto nbr : l[node])
        {
            if (!visited[nbr.first])
            {
                q.push({nbr.second, nbr.first});
            }
        }
    }
    return count == n ? ans : -1;
}