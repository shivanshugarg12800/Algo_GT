#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], bool *visited, int i, vector<int> &stack)
{
    visited[i] = true;
    for (auto nbr : graph[i])
    {
        if (!visited[nbr])
        {
            dfs(graph, visited, nbr, stack);
        }
    }
    // function call is complete
    // push it to the stack
    stack.push_back(i);
}
void dfs_2(vector<int> graph[], int i, bool *visited)
{
    visited[i] = true;
    cout << i << " ";
    for (auto nbr : graph[i])
    {
        if (!visited[nbr])
        {
            dfs_2(graph, nbr, visited);
        }
    }
}

void kosarajuAlgorithm(vector<int> graph[], vector<int> rev_graph[], int n)
{
    bool visited[n];
    memset(visited, 0, n);
    vector<int> stack;
    // step-1: store the vertices in the vector acc. to the finished time
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i, stack);
        }
    }

    // we have the ordering in stack
    // step-2: reverese the graph.. already done
    // step-3: do dfs acc to the ordering given in the stack
    // reset the visited array
    memset(visited, 0, n);
    char component_name = 'A';
    for (int x = stack.size() - 1; x >= 0; x--)
    {
        int node = stack[x];
        if (!visited[node])
        {
            // there is node starting from this node
            cout << "Component" << component_name << "-->";
            dfs_2(rev_graph, node, visited);
            cout << endl;
            component_name++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    vector<int> rev_graph[n];

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    kosarajuAlgorithm(graph, rev_graph, n);

    return 0;
}