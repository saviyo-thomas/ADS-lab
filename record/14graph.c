/* 14. Implementation of graphs and graph traversals (BFS & DFS) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; // For undirected graph
}

void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1) return 0;
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1) return 0;

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter start vertex for traversal: ");
    if (scanf("%d", &start) != 1) return 0;

    BFS(&g, start);
    DFS(&g, start);

    return 0;
}