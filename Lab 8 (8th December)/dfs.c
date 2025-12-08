#include <stdio.h>
#include <stdlib.h>

void dfs(int **graph, int vertices, int start) {
    int *visited = (int *)malloc(vertices * sizeof(int));
    int *stack = (int *)malloc(vertices * sizeof(int));
    int top = -1;
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    stack[++top] = start;
    visited[start] = 1;
    while (top >= 0) {
        int node = stack[top--];
        printf("%d ", node);
        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    free(visited);
    free(stack);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges (V E): ");
    scanf("%d %d", &vertices, &edges);
    int **graph = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) graph[i][j] = 0;
    }
    printf("Enter the edges (u v) for %d edges:\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    dfs(graph, vertices, start);
    for (int i = 0; i < vertices; i++) free(graph[i]);
    free(graph);
    return 0;
}
