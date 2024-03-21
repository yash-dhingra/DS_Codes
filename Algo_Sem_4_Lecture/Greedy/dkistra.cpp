#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>> &graph, int source)
{
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Output shortest distances
    for (int i = 0; i < n; ++i)
        cout << "Shortest distance from source to " << i << " is: " << dist[i] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m; // Number of vertices and edges respectively

    vector<vector<pii>> graph(n);

    // Input edges and weights
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Uncomment this line for undirected graph
    }

    int source;
    cin >> source; // Input source vertex

    dijkstra(graph, source);

    return 0;
}
