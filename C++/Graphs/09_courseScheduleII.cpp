#include <bits/stdc++.h>
using namespace std;
list<int> *l;
vector<int> findOrder(int n, vector<vector<int>> &arr)
{
    l = new list<int>[n];
    for (auto it : arr)
    {
        l[it[0]].push_back(it[1]);
    }
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : l[i])
            indegree[it]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : l[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() != n)
        return {};
    reverse(ans.begin(), ans.end());
    return ans;
}