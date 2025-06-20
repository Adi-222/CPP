// LAB Assignment 7
//A. write the pseudo code for the floyd-warshall algorithm
//B. Implement the algorithm in c 
//C. Anyalse the complexity of the algorithm.



#include <stdio.h>
#define INF 99999 
#define V 4       
int cnt =0;
void floydWarshall(int graph[V][V]) {
    int dist[V][V]; 

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    
    for (int k = 0; k < V; k++) {
       
        for (int i = 0; i < V; i++) {
            
            for (int j = 0; j < V; j++) {
                cnt++;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%s", "INF");
            else
                printf("%d", dist[i][j]);
        }
        printf("\n");

        

       
    }
    printf("\n");
        printf("\n");
        printf("\n");
     printf("%d the counter count is  ",cnt);
}

int main() {
    
    int graph[V][V] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0,0, 0, 0},
        {0, 0,0, 0}
    };

    floydWarshall(graph);
    return 0;
}
