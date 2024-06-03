#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int k;
    struct Node *f;
    struct Node *n;
} Node;

Node* cn(int k) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->k = k;
    n->f = NULL;
    n->n = NULL;
    return n;
}

void pe(Node *n) {
    if (n == NULL) return;

    Node *c = n->f;
    while (c != NULL) {
        printf("(%d, %d)\n", n->k, c->k);
        pe(c);
        c = c->n;
    }
}

Node* bt() {
    int k;
    scanf("%d", &k);
    if (k == 0) return NULL;

    Node *n = cn(k);
    n->f = bt();

    Node *cur = n->f;
    while (cur != NULL) {
        cur->n = bt();
        cur = cur->n;
    }

    return n;
}

int main() {
    printf("请输入树的节点序列：\n");
    Node *r = bt();
    printf("树的所有边：\n");
    pe(r);
    return 0;
}

