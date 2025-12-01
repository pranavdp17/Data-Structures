bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int *deg = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) deg[i] = 0;
    for (int i = 0; i < edgesSize; i++) {
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }
    int **g = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g[i] = malloc(deg[i] * sizeof(int));
        deg[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        g[u][deg[u]++] = v;
        g[v][deg[v]++] = u;
    }
    if (source == destination) return true;
    bool *vis = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) vis[i] = false;
    int *q = malloc(n * sizeof(int));
    int f = 0, r = 0;
    q[r++] = source;
    vis[source] = true;
    while (f < r) {
        int x = q[f++];
        for (int i = 0; i < deg[x]; i++) {
            int y = g[x][i];
            if (!vis[y]) {
                if (y == destination) return true;
                vis[y] = true;
                q[r++] = y;
            }
        }
    }
    return false;
}