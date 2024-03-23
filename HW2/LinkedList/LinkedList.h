#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LLNode{
    int data;
    struct LLNode *next;
} LLNode, *pLinkedList;

pLinkedList createLinkedList();

int insertNode(pLinkedList head, int data);

int deleteNode(pLinkedList head, int data);

int reverseLinkedList(pLinkedList head);

int printLinkedList(pLinkedList head);

int freeLinkedList(pLinkedList head);

#endif