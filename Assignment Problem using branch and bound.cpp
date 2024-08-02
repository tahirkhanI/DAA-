#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4
struct Node {
    int path[N];  
    bool assigned[N]; 
    int cost; 
    int workerID;
    int taskID;  
};
int calculateCost(int costMatrix[N][N], int path[N], int workerID, int taskID) {
    int cost = 0;
    for (int i = 0; i <= workerID; i++) {
        cost += costMatrix[i][path[i]];
    }
    return cost;
}
struct Node createNode(int path[N], bool assigned[N], int cost, int workerID, int taskID) {
    struct Node node;
    for (int i = 0; i < N; i++) {
        node.path[i] = path[i];
        node.assigned[i] = assigned[i];
    }
    node.cost = cost;
    node.workerID = workerID;
    node.taskID = taskID;
    return node;
}
void branchAndBound(int costMatrix[N][N], struct Node currentNode, int minCost) {
    if (currentNode.workerID == N - 1) {
        if (currentNode.cost < minCost) {
            printf("Minimum cost: %d\n", currentNode.cost);
            printf("Assignment:\n");
            for (int i = 0; i < N; i++) {
                printf("Worker %d assigned to task %d\n", i, currentNode.path[i]);
            }
            return;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!currentNode.assigned[i]) {
            int newPath[N];
            bool newAssigned[N];
            for (int j = 0; j < N; j++) {
                newPath[j] = currentNode.path[j];
                newAssigned[j] = currentNode.assigned[j];
            }
            newPath[currentNode.workerID + 1] = i;
            newAssigned[i] = true;
            int newCost = calculateCost(costMatrix, newPath, currentNode.workerID + 1, i);
            struct Node newNode = createNode(newPath, newAssigned, newCost, currentNode.workerID + 1, i);
            branchAndBound(costMatrix, newNode, minCost);
        }
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int minCost = INT_MAX;
    int initialPath[N] = {-1, -1, -1, -1};
    bool initialAssigned[N] = {false, false, false, false};
    struct Node initialNode = createNode(initialPath, initialAssigned, 0, -1, -1);

    branchAndBound(costMatrix, initialNode, minCost);

    return 0;
}

