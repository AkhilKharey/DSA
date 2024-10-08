#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices
#define INF 999 // Representation of infinity (no edge)

// Structure to represent an edge
typedef struct
{
    int u, v, weight; // Vertices u and v connected by this edge and its weight
} Edge;

Edge edges[MAX]; // Array to store all edges
int parent[MAX]; // Array for Union-Find
int N, E = 0;    // Number of vertices and edges

// Function to find the root of a set
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void union_sets(int u, int v)
{
    int u_root = find(u);
    int v_root = find(v);
    parent[v_root] = u_root;
}

// Comparison function for qsort to sort edges by weight
int compare(const void *a, const void *b)
{
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

int main()
{
    int graph[MAX][MAX];
    int i, j, total_cost = 0;

    // Read number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &N);

    // Read adjacency matrix
    printf("Enter adjacency matrix (use 0 for self loops and 999 for no edge):\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &graph[i][j]);

    // Initialize parent array for Union-Find
    for (i = 0; i < N; i++)
        parent[i] = i;

    // Create edge list from adjacency matrix
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        { // Avoid duplicates
            if (graph[i][j] != 0 && graph[i][j] != INF)
            {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    printf("Edges in the Minimum Spanning Tree:\n");

    // Kruskal's Algorithm
    for (i = 0; i < E; i++)
    {
        int u_root = find(edges[i].u);
        int v_root = find(edges[i].v);

        // If including this edge doesn't form a cycle
        if (u_root != v_root)
        {
            printf("Edge (%d, %d) with weight %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total_cost += edges[i].weight;
            union_sets(u_root, v_root);
        }
    }

    printf("Total cost of the MST is %d\n", total_cost);

    return 0;
}
