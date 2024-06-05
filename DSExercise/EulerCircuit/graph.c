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
    scanf("%d", &numVertices);
    initGraph(&g, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
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