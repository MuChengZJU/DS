#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �����ڽӱ�ڵ�
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// �����ڽӱ�
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// ����ͼ
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// �����ڽӱ�ڵ�
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// ����ͼ
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// ��ӱߵ�ͼ
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// �������������������
bool DFSUtil(Graph* graph, int v, int j, bool* visited) {
    visited[v] = true;

    // ����ҵ�Ŀ�궥�㣬����true
    if (v == j) {
        return true;
    }

    // �����ڽӱ�
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

// �б��Ƿ���ڴӶ���v������j��·��
bool isPathExist(Graph* graph, int v, int j) {
    if (v == j) {
        return false; // �������Ի�
    }

    // ������������
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    // ����DFS��������
    bool result = DFSUtil(graph, v, j, visited);

    // �ͷŷ�������
    free(visited);

    return result;
}

// ����������
int main() {
    // ����һ��ͼ
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
        printf("�Ӷ���%d������%d����·��\n", v, j);
    } else {
        printf("�Ӷ���%d������%d������·��\n", v, j);
    }

    return 0;
}