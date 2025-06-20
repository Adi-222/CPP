// LAB Assignment 5
// using c programm9ing language,implement the Dijkstra's algorithm to find the shortest path in a graphfrom a fixed node.Anyalse the time complexity of the given aqlgorithm.




#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[], int* counter) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        (*counter)++;
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int* counter) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        (*counter)++;
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int counter = 0;

    for (int i = 0; i < V; i++) {
        counter++;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        counter++;
        int u = minDistance(dist, sptSet, &counter);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            counter++;
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                counter++;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, &counter);
    printf("Total number of operations: %d\n", counter);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
