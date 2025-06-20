#include <stdio.h>
#include <limits.h>

#define V 5  
#define E 8  

struct Edge {
    int src, dest, weight;
};

void printSolution(int dist[], int counter) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
    printf("Total number of operations: %d\n", counter);
}

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];
    int counter = 0;

    for (int i = 0; i < V; i++) {
        counter++;
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            counter++;
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                counter++;
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        counter++;
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printSolution(dist, counter);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, 0);
    return 0;
}

