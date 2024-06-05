#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    memset(g->adjMatrix, 0, sizeof(g->adjMatrix));
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest]++;
    g->adjMatrix[dest][src]++;
}

bool isConnected(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    int i;

    for (i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[i][0] != 0) {
            break;
        }
    }

    if (i == g->numVertices) {
        return true;
    }

    dfs(g, i, visited);

    for (i = 0; i < g->numVertices; i++) {
        if (!visited[i] && g->adjMatrix[i][0] != 0) {
            return false;
        }
    }

    return true;
}

void dfs(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true;
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

bool isEulerian(Graph *g) {
    if (!isConnected(g)) {
        return false;
    }

    for (int i = 0; i < g->numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j]) {
                degree += g->adjMatrix[i][j];
            }
        }
        if (degree % 2 != 0) {
            return false;
        }
    }
    return true;
}

void findEulerCircuit(Graph *g, int startVertex) {
    int stack[MAX_VERTICES];
    int circuit[MAX_VERTICES];
    int top = 0, circuitIndex = 0;

    stack[top++] = startVertex;

    while (top > 0) {
        int vertex = stack[top - 1];
        int i;

        for (i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[vertex][i]) {
                break;
            }
        }

        if (i == g->numVertices) {
            circuit[circuitIndex++] = vertex;
            top--;
        } else {
            stack[top++] = i;
            g->adjMatrix[vertex][i]--;
            g->adjMatrix[i][vertex]--;
        }
    }

    printf("Euler Circuit: ");
    for (int i = circuitIndex - 1; i >= 0; i--) {
        printf("%d ", circuit[i]);
    }
    printf("\n");
}

int lab7() {
    Graph g;
    int numVertices, numEdges, src, dest;

    printf("Enter the number of vertices: ");
    while (scanf("%d", &numVertices) != 1 || numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid input. Enter a positive integer less than or equal to %d: ", MAX_VERTICES);
        while (getchar() != '\n'); // 清除输入缓冲区
    }
    initGraph(&g, numVertices);

    printf("Enter the number of edges: ");
    while (scanf("%d", &numEdges) != 1 || numEdges < 0) {
        printf("Invalid input. Enter a non-negative integer: ");
        while (getchar() != '\n'); // 清除输入缓冲区
    }

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge (source destination): ");
        while (scanf("%d %d", &src, &dest) != 2 || src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            printf("Invalid input. Enter two integers between 0 and %d: ", numVertices - 1);
            while (getchar() != '\n'); // 清除输入缓冲区
        }
        addEdge(&g, src, dest);
    }

    if (isEulerian(&g)) {
        printf("The graph is Eulerian.\n");
        findEulerCircuit(&g, 0);
    } else {
        printf("The graph is not Eulerian.\n");
    }

    return 0;
}