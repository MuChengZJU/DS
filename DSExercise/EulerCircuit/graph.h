/**
 * @file graph.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-06
 * 
 * 
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

/**
 * @brief Init graph
 * 
 * @param g 
 * @param vertices 
 */
void initGraph(Graph *g, int vertices);

/**
 * @brief Add edge to graph
 * 
 * @param g 
 * @param src 
 * @param dest 
 */
void addEdge(Graph *g, int src, int dest);

/**
 * @brief  Check if the graph is Eulerian
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool isEulerian(Graph *g);

/**
 * @brief Check if the graph is connected
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool isConnected(Graph *g);


/**
 * @brief Find Euler Circuit in graph
 * 
 * @param g 
 * @param startVertex 
 */
void findEulerCircuit(Graph *g, int startVertex);

/**
 * @brief Lab 7 main function
 * 
 * @return int 
 */
int lab7(void);

#endif