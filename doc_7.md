Dijkstra’s algorithm finds the shortest distance from a starting node to every other node in a weighted graph. It works on a Greedy principle: always pick the "closest" unvisited node and see if you can find a shortcut to its neighbors.

Program Flow:
1. Initialize all the other nodes weight to be infinity except source node  at zero.

2. Keep notes of nodes with shortest path.

3. The Shortcut Check:

i. We stand at the current "closest" node (let's say node u).

ii. We look at all its neighbors (v).

iii. We ask: "Is the distance to u + the weight of the edge u->v smaller than the distance I currently have written down for v?"

iv. If yes, we erase the old distance and write down the new, shorter one. This is called Relaxation.

Why V - 1 in the main loop?
Because by the time we have finalized $V-1$ nodes, the very last node must already be at its shortest distance by default—there are no other paths left to check.

Time complexity: O(V^2)
Space complexity: O(V)

Output:
Vertex   Distance from Source (0)
0        0
1        2
2        3
3        4
4        9999