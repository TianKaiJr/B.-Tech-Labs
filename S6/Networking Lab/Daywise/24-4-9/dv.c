#include <stdio.h>

#define MAX_NODES 20
#define INFINITY 999999

int costMatrix[MAX_NODES][MAX_NODES], n;

struct routers
{
    int distance[MAX_NODES];
    int adjNodes[MAX_NODES];
} node[MAX_NODES];

// Function to display the distance vector routing table
void displayRoutingTable()
{
    int i, j;
    printf("\nDistance Vector Routing Table:\n");
    for (i = 0; i < n; ++i)
    {
        printf("\nRouter %d\n", i + 1);
        for (j = 0; j < n; ++j)
        {
            printf("Node %d via %d : Distance %d\n", j + 1, node[i].adjNodes[j] + 1, node[i].distance[j]);
        }
        printf("\n");
    }
}

// Function to read the cost matrix
void readCostMatrix()
{
    int i, j;
    printf("\nEnter cost matrix\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &costMatrix[i][j]);
            // Distance from node X to itself is 0
            if (i == j)
                costMatrix[i][j] = 0;
            // Initialize distance vector and adjacent node array
            node[i].distance[j] = costMatrix[i][j];
            node[i].adjNodes[j] = j;
        }
    }
}

// Function to update distance vectors based on Bellman-Ford algorithm
void updateDistanceVectors()
{
    int i, j, k;
    for (k = 0; k < n-2; ++k)
    {
        printf("\nIteration %d:\n", k + 1);
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                // Update distance vector using Bellman-Ford algorithm
                if (node[i].distance[j] > costMatrix[i][k] + node[k].distance[j])
                {
                    node[i].distance[j] = costMatrix[i][k] + node[k].distance[j];
                    node[i].adjNodes[j] = k;
                }
            }
        }
        // Display distance vector after each iteration
        printf("After iteration %d:\n", k + 1);
        displayRoutingTable();
    }
}

int main()
{
    printf("Number of nodes: ");
    scanf("%d", &n);
    readCostMatrix();

    // Before distance vector routing table
    printf("\nBefore Distance Vector Routing Table:\n");
    displayRoutingTable();

    // Update distance vectors using Bellman-Ford algorithm
    updateDistanceVectors();

    return 0;
}

