#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        //parent is -1 and rank = 1;
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        // path compression
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
    void Union_set(int x, int y)
    {
        // by rank optimisation
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
int minCostToMake(int n, vector<int> &well, vector<vector<int>> &pipes)
{

    for (int i = 0; i < n; i++)
    {
        pipes.push_back({well[i], 0, i + 1});
    }
    sort(pipes.begin(), pipes.end());

    DSU s(n + 1);
    int ans = 0;
    for (auto edge : pipes)
    {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        // take that edge in MST if it doesn't form cycle
        if (s.find(x) != s.find(y))
        {
            s.Union_set(x, y);
            ans += w;
        }
    }
    return ans;
}
int32_t main()
{

    int n, a, b, c, p;
    int num, count, ans, result = 0;
    cin >> n >> p;
    vector<int> well(n);
    vector<vector<int>> pipes(p, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> well[i];
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b >> c;
        pipes[i][0] = c;
        pipes[i][1] = a;
        pipes[i][2] = b;
    }

    cout << minCostToMake(n, well, pipes);

    return 0;
}
