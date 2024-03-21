#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

class Kruskal
{
private:
    int V;              // Number of vertices
    vector<Edge> edges; // Vector to store edges of graph
    vector<int> parent; // Parent array for union-find

public:
    Kruskal(int vertices) : V(vertices)
    {
        parent.resize(V);
        // Initialize parent array
        for (int i = 0; i < V; ++i)
            parent[i] = i;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    // Function to find the parent of a vertex using union-find algorithm
    int find(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;
        return find(parent[vertex]);
    }

    // Function to perform union of two subsets
    void unionSets(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        parent[xRoot] = yRoot;
    }

    // Function to apply Kruskal's algorithm and find minimum spanning tree
    void kruskalMST()
    {
        vector<Edge> result; // Vector to store the MST edges
        // Sort edges by weight
        sort(edges.begin(), edges.end(), compareEdges);

        int edgeCount = 0; // Counter to keep track of selected edges

        // Iterate through all edges
        for (const auto &edge : edges)
        {
            int srcParent = find(edge.src);
            int destParent = find(edge.dest);

            // If including this edge doesn't cause a cycle, add it to the result
            if (srcParent != destParent)
            {
                result.push_back(edge);
                unionSets(srcParent, destParent);
                ++edgeCount;
            }

            // Stop when V-1 edges are selected
            if (edgeCount == V - 1)
                break;
        }

        // Print the MST edges
        cout << "Minimum Spanning Tree Edges:\n";
        for (const auto &edge : result)
        {
            cout << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
        }
    }
};

int main()
{
    // Example graph represented as adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int V = graph.size(); // Number of vertices
    Kruskal kruskal(V);

    // Convert the adjacency matrix into edges
    for (int i = 0; i < V; ++i)
    {
        for (int j = i + 1; j < V; ++j)
        {
            if (graph[i][j] != 0)
            {
                kruskal.addEdge(i, j, graph[i][j]);
            }
        }
    }

    // Find and print the Minimum Spanning Tree
    kruskal.kruskalMST();

    return 0;
}
