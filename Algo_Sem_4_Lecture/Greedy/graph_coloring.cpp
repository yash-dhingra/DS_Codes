#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Graph
{
private:
    vector<vector<int>> adj; // adjacency matrix

public:
    Graph(const vector<vector<int>> &edges) : adj(edges) {}

    void greedyColoring()
    {
        int V = adj.size();              // number of vertices
        map<int, int> result;            // Map to store colors
        vector<bool> available(V, true); // To check available colors for each vertex

        // Assign the first color to the first vertex
        result[0] = 0;

        // Assign colors to remaining V-1 vertices
        for (int u = 1; u < V; u++)
        {
            // Mark all available colors as true
            for (int c = 0; c < V; c++)
                available[c] = true;

            // Traverse adjacent vertices and mark their colors as false
            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] && result.find(v) != result.end())
                    available[result[v]] = false;
            }

            // Find the first available color
            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr])
                    break;

            // Assign the found color
            result[u] = cr;
        }

        // Print the results
        for (int u = 0; u < V; u++)
            cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
};

int main()
{
    // Create a graph given in the example
    vector<vector<int>> edges = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    // Create graph object
    Graph g(edges);

    // Color the graph
    g.greedyColoring();

    return 0;
}
