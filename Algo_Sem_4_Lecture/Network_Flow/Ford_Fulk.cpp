#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define V 6 // Number of vertices in the graph

bool bfs(vector<vector<int>> &residualGraph, int s, int t, vector<int> &parent)
{
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && residualGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<int> parent(V);
    vector<vector<int>> residualGraph = graph; // Residual graph

    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent))
    {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}

    };

    int source = 0, sink = 5;
    cout << "Max Flow: " << fordFulkerson(graph, source, sink) << endl;
    return 0;
}
