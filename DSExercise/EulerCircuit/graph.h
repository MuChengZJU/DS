#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g, int vertices);
void addEdge(Graph *g, int src, int dest);
bool isEulerian(Graph *g);
bool isConnected(Graph *g);
void findEulerCircuit(Graph *g, int startVertex);

int lab7(void);

#endif