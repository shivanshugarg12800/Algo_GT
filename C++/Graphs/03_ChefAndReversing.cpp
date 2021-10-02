#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    int n;
    vector<pair<int, int>> *l;

public:
    graph(int n)
    {
        this->n = n;
        l = new vector<pair<int, int>>[n];
    }
    void addEdge(int x, int y, int dir)
    {
        l[x].push_back({y, dir});
    }

    int numReverse(int n)
    {
        vector<int> visited(n, -1);
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        int count = 0;
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop_front();
            if (visited[node.first] == -1)
            {
                visited[node.first] = node.second;
            }

            for (auto nbr : l[node.first])
            {
                if (visited[nbr.first] == -1)
                {
                    if (nbr.second == 0)
                        q.push_front({nbr.first, node.second});
                    else
                        q.push_back({nbr.first, node.second + 1});
                }
            }
        }
        return visited[n - 1];
    }
};
void solve()
{

    int n, e;
    cin >> n >> e;
    graph g(n);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x - 1, y - 1, 0);
        g.addEdge(y - 1, x - 1, 1);
    }

    cout << g.numReverse(n) << endl;
}

int32_t main()
{

    solve();

    return 0;
}
