This program demonstrates how to represent an undirected graph using an Adjacency Matrix and how to traverse it using two fundamental algorithms: Depth-First Search (DFS) and Breadth-First Search (BFS).

We use a 2D array adj[MAX][MAX] where:adj[i][j] = 1 indicates an edge exists between node i and node j.Since the graph is undirected, the matrix is symmetric ($adj[i][j] = adj[j][i]$).

Algorithms:

Depth-First Search (DFS)

i. Strategy: Goes as deep as possible down one branch before backtracking.

ii. Tool used: Recursion (which utilizes the System Stack).

iii. Best for: Exploring every corner of a graph or solving puzzles/mazes.

B. Breadth-First Search (BFS)
i. Strategy: Explores all immediate neighbors first (layer by layer).

ii. Tool used: Queue (First-In, First-Out).

iii. Best for: Finding the shortest path between two nodes in an unweighted graph.

**Program Flow**
i. The adjacency matrix is cleared (all zeros).

ii. Edges are added by setting specific matrix coordinates to 1.

iii. DFS Execution:

Starts at a source node.

Marks the node as "visited."

Recursively visits the first unvisited neighbor it finds.

iv. BFS Execution:

Starts at a source node and adds it to a Queue.

While the queue isn't empty:

Pulls a node out, prints it.

Finds all its unvisited neighbors and adds them to the queue.

Time and space complexity: O(V^2)

Output:
DFS (The Deep Diver): 0 1 4 2 3 
BFS (The Wide Searcher): 0 1 2 3 4
 
