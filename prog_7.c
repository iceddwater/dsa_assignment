// Dijkstra’s algorithm
#include <stdio.h>
#include <stdbool.h>

#define V 5      // Number of vertices
#define INF 9999 // Representing "Infinity"

// Find the node with the minimum distance that hasn't been visited yet
int findMinDistance(int dist[], bool visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Holds the shortest distance from src to i
    bool visited[V]; // True if node i is finalized

    // Initialize: all distances to Infinity, all nodes unvisited
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance to the source from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Pick the "closest" node from the unvisited set
        int u = findMinDistance(dist, visited);
        visited[u] = true;

        // Update distance values of the neighbors of the picked node
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if:
            // 1. There is an edge from u to v
            // 2. v is not visited
            // 3. The total path through u is shorter than the current dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the results
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    /* Example Graph (Weighted)
       (0)---2---(1)
        | \       |
        6  3      3
        |    \    |
       (3)---1---(2)
    */
    int graph[V][V] = {
        {0, 2, 3, 6, 0},
        {2, 0, 0, 0, 0},
        {3, 0, 0, 1, 0},
        {6, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);

    return 0;
}