#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义邻接表节点
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// 定义邻接表
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// 定义图
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// 创建邻接表节点
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 创建图
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// 添加边到图
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 深度优先搜索辅助函数
bool DFSUtil(Graph* graph, int v, int j, bool* visited) {
    visited[v] = true;

    // 如果找到目标顶点，返回true
    if (v == j) {
        return true;
    }

    // 遍历邻接表
    AdjListNode* crawl = graph->array[v].head;
    while (crawl != NULL) {
        int adjVertex = crawl->dest;
        if (!visited[adjVertex]) {
            if (DFSUtil(graph, adjVertex, j, visited)) {
                return true;
            }
        }
        crawl = crawl->next;
    }
    return false;
}

// 判别是否存在从顶点v到顶点j的路径
bool isPathExist(Graph* graph, int v, int j) {
    if (v == j) {
        return false; // 不考虑自环
    }

    // 创建访问数组
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    // 调用DFS辅助函数
    bool result = DFSUtil(graph, v, j, visited);

    // 释放访问数组
    free(visited);

    return result;
}

// 主函数测试
int main() {
    // 创建一个图
    int V = 4;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    int v = 1, j = 3;
    if (isPathExist(graph, v, j)) {
        printf("从顶点%d到顶点%d存在路径\n", v, j);
    } else {
        printf("从顶点%d到顶点%d不存在路径\n", v, j);
    }

    return 0;
}