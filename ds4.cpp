#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

class Graph {
    int n; // Number of cities
    vector<vector<pii>> adjList; // Adjacency list

public:
    Graph(int nodes) {
        n = nodes;
        adjList.resize(n);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({weight, v});
        adjList[v].push_back({weight, u}); // Undirected graph
    }

    void primMST(int start) {
        vector<bool> visited(n, false);
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, start});
        int mstCost = 0;

        while (!minHeap.empty()) {
            pii topElement = minHeap.top(); // Get the top element
            minHeap.pop();

            int cost = topElement.first;
            int u = topElement.second;

            if (visited[u]) continue; // Skip if already visited
            visited[u] = true;
            mstCost += cost;

            for (size_t i = 0; i < adjList[u].size(); i++) {
                int weight = adjList[u][i].first;
                int v = adjList[u][i].second;
                if (!visited[v]) {
                    minHeap.push({weight, v});
                }
            }
        }

        cout << "Total Minimum Travel Cost: " << mstCost << endl;
    }
};

int main() {
    int n = 4; // Number of cities
    Graph g(n);

    // Adding edges representing distances between interview locations
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 20);
    g.addEdge(1, 2, 35);
    g.addEdge(1, 3, 25);
    g.addEdge(2, 3, 30);

    int startCity = 0;
    g.primMST(startCity); // Call function with correct parameter

    return 0;
}
