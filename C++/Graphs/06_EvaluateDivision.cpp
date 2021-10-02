#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<pair<string, double>>> l;

void dfs(string src, string dest, double tmp, double &sum, bool &found, map<string, bool> &vis)
{
    vis[src] = true;
    if (src == dest)
    {
        found = true;
        sum = tmp;
        return;
    }

    for (auto i : l[src])
    {
        if (vis.find(i.first) == vis.end())
            dfs(i.first, dest, tmp * i.second, sum, found, vis);
    }
}

vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &values, vector<vector<string>> &query)
{

    vector<double> ans;
    int n = eq.size();

    for (int i = 0; i < n; i++)
    {
        double w = values[i];
        double w1 = 1 / w;

        l[eq[i][0]].push_back({eq[i][1], w});
        l[eq[i][1]].push_back({eq[i][0], w1});
    }
    for (int i = 0; i < query.size(); i++)
    {

        map<string, bool> vis;

        if (l.find(query[i][0]) == l.end())
        {
            ans.push_back(-1.0);
            continue;
        }
        else
        {
            bool found = false;
            double sum = 0.0;
            dfs(query[i][0], query[i][1], 1.0, sum, found, vis);
            if (!found)
                ans.push_back(-1.0);
            else
                ans.push_back(sum);
        }
    }
    return ans;
}