#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;
    list<int> *l; // pointer to the array of lists
public:
    // constructor
    Graph(int v)
    {
        this->v = v;
        this->l = new list<int>[v + 1];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);  directed graph
    }

        //--------------------KAHN'S ALGORITHM  ------------ this is using bfs----------------------------
    void topologicalSort_BFS(int n)
    {
        // calculate indegrees of all the vertices
        int indegree[n] = {0};
        for (int i = 0; i < n; i++)
        {
            for (auto node : l[i])
            {
                indegree[node]++;
            }
        }

        // bfs traversal
        queue<int> vertices;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                vertices.push(i);
            } // push all the nodes with zero indegree to start with
        }

        while (!vertices.empty())
        {
            int curr = vertices.front();
            cout << curr << " ";
            vertices.pop();
            for (auto nbr : l[curr])
            {
                // reduce the indegree of each neighbouring node
                indegree[nbr]--;
                // if the indegree of the nbr becomes zero push
                if (indegree[nbr] == 0)
                    vertices.push(nbr);
            }
        }
    }
};