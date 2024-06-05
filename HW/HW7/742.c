#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// 定义邻接表节点
typedef struct AdjListNode {
    int dest;
    int weight;
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
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
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
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 获取最小距离顶点
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra算法
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V]; // 最短距离数组
    bool sptSet[V]; // 最短路径树集合

    // 初始化
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    // 找到从源点到所有顶点的最短路径
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        // 更新u的邻接顶点的距离值
        AdjListNode* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->dest;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + crawl->weight < dist[v]) {
                dist[v] = dist[u] + crawl->weight;
            }
            crawl = crawl->next;
        }
    }

    // 打印结果
    printf("顶点\t距离\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// 主函数测试
int main() {
    // 创建一个图
    int V = 9;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}