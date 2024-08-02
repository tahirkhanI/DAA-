#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices

void printSolution(int path[]) {
    printf("Solution Exists: Following is one Hamiltonian Cycle\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included.
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the cycle
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle.
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;  // Backtrack
        }
    }
    return false;
}

bool hamiltonianCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Start at vertex 0

    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);
    return 0;
}

