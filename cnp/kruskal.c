#include <stdio.h>

#define MAX 100
#define INFINITY 999

struct edge
{
    int u, v, w;
} edges[MAX];

int parent[MAX], edge_count = 0;

int find(int i)
{
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void kruskal(int n)
{
    for (int i = 0, selected = 0, total_cost = 0; selected < n - 1; i++)
    {
        int u_set = find(edges[i].u), v_set = find(edges[i].v);
        if (u_set != v_set)
        {
            parent[u_set] = v_set;
            printf("\n%d <--> %d, cost = %d", edges[i].u + 1, edges[i].v + 1, edges[i].w);
            total_cost += edges[i].w;
            selected++;
        }
        if (selected == n - 1)
            printf("\nMinimum Spanning Tree cost = %d\n", total_cost);
    }
}

int main()
{
    int n;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (999 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        for (int j = 0; j < n; j++)
        {
            int w;
            scanf("%d", &w);
            if (i < j && w < INFINITY)
                edges[edge_count++] = (struct edge){i, j, w};
        }
    }

    for (int i = 0; i < edge_count - 1; i++)
        for (int j = 0; j < edge_count - i - 1; j++)
            if (edges[j].w > edges[j + 1].w)
            {
                struct edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    kruskal(n);

    return 0;
}
