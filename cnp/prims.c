#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100 // Maximum number of vertices

int N; // Number of vertices in the graph

// Graph represented as an adjacency matrix
int graph[MAX_N][MAX_N];

// Array to keep track of included vertices in MST
bool included[MAX_N];

int total_cost = 0; // Variable to store total cost of MST

// Recursive function to perform Prim's algorithm
void prim(int included_count)
{
    // Base case: if all vertices are included, return
    if (included_count == N)
        return;

    int min = INT_MAX;  // Initialize minimum weight to a large value
    int u = -1, v = -1; // Variables to store the indices of the minimum edge

    // Find the minimum weight edge from included vertices to not included vertices
    for (int i = 0; i < N; i++)
    {
        if (included[i])
        { // If vertex i is included in MST
            for (int j = 0; j < N; j++)
            {
                // If vertex j is not included, edge exists, and not a self-loop
                if (!included[j] && graph[i][j] != 999 && graph[i][j] != 0)
                {
                    if (graph[i][j] < min)
                    {
                        min = graph[i][j]; // Update minimum weight
                        u = i;
                        v = j;
                    }
                }
            }
        }
    }

    if (u != -1 && v != -1)
    {
        // Include vertex v in MST
        included[v] = true;
        printf("Edge (%d, %d) with weight %d\n", u, v, graph[u][v]);
        total_cost += graph[u][v]; // Add edge weight to total cost
    }

    // Recur for the next vertex
    prim(included_count + 1);
}

int main()
{
    // Read the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &N);

    // Read the adjacency matrix
    printf("Enter the adjacency matrix (use 0 for self loops and 999 for no edge):\n");
    for (int i = 0; i < N; i++)
    {
        included[i] = false; // Initialize included array
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Start from vertex 0
    included[0] = true;
    printf("Edges in the minimum spanning tree:\n");
    prim(1); // Start the recursive Prim's algorithm

    // Print the total cost
    printf("Total cost of the MST is %d\n", total_cost);

    return 0;
}
