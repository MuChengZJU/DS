#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Tree Node
typedef struct Node {
    int key;
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

// Function to create a new node with a given key
Node* createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Function to print edges of the tree in (parent, child) format
void printEdges(Node *node) {
    if (node == NULL) return;

    Node *child = node->firstChild;
    while (child != NULL) {
        printf("(%d, %d)\n", node->key, child->key);
        printEdges(child);
        child = child->nextSibling;
    }
}

// Function to build the tree from input
Node* buildTree() {
    int key;
    scanf("%d", &key);
    if (key == 0) return NULL;

    Node *root = createNode(key);
    root->firstChild = buildTree();

    Node *current = root->firstChild;
    while (current != NULL) {
        current->nextSibling = buildTree();
        current = current->nextSibling;
    }

    return root;
}

int main() {
    while (1) {
        printf("请输入树的节点序列：\n");
        Node *root = buildTree();
        printf("树的所有边：\n");
        printEdges(root);
    }

    return 0;
}