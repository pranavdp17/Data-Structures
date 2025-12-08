#include <stdio.h>
#include <stdlib.h>

void bfs(int **graph, int vertices, int start) {
    int *visited = (int *)malloc(vertices * sizeof(int));
    int *queue = (int *)malloc(vertices * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    free(visited);
    free(queue);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges (V E): ");
    scanf("%d %d", &vertices, &edges);
    int **graph = (int **)malloc(vertices * sizeof(int *));
    printf("Enter the edges (u v) for %d edges:\n", edges);
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) graph[i][j] = 0;
    }
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(graph, vertices, start);
    for (int i = 0; i < vertices; i++) free(graph[i]);
    free(graph);
    return 0;
}
