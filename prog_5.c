// BFS and DFS
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int adj[MAX][MAX]; // The Matrix
bool visited[MAX];

// BFS Queue helpers
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// DFS - Go deep using recursion
void DFS(int v, int n) {
    printf("%d ", v);
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

// BFS - Go wide using a queue
void BFS(int start, int n) {
    for(int i = 0; i < n; i++) visited[i] = false; // Reset visited array

    enqueue(start);
    visited[start] = true;

    while (front <= rear && front != -1) {
        int v = dequeue();
        if (v == -1) break;
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Now we have 5 nodes (0 to 4)

    // Reset matrix to 0
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;

    // Connections
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[0][3] = adj[3][0] = 1;
    adj[1][4] = adj[4][1] = 1;

    printf("DFS (The Deep Diver): ");
    for(int i = 0; i < n; i++) visited[i] = false;
    DFS(0, n); 

    printf("\nBFS (The Wide Searcher): ");
    BFS(0, n);
    printf("\n");

    return 0;
} 
