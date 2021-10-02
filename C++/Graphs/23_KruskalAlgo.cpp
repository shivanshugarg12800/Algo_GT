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

class Graph
{
    vector<vector<int>> edgeList;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
    }
    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y}); // we prefer this way as in built sort is based on the zeroth index
    }
    int kruskals_MST()
    {
        // sort the edge list one the basis of weight
        sort(edgeList.begin(), edgeList.end());

        // init DSU
        DSU s(v);
        int ans = 0;
        for (auto edge : edgeList)
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
};

int main()
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    while (e--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    cout << g.kruskals_MST() << endl;
}