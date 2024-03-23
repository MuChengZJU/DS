#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

int reverseLinkedList(pLinkedList head) {
    pLinkedList prev = NULL;
    pLinkedList current = head->next;
    pLinkedList next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;

    return 0;
}

int printLinkedList(pLinkedList head) {
    pLinkedList current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}

pLinkedList createLinkedList() {
    pLinkedList head = (pLinkedList)malloc(sizeof(LLNode));
    if (head == NULL) {
        printf("Failed to allocate memory for head.\n");
        return NULL;
    }
    head->next = NULL;
    head->data = 0;
    return head;
}

int insertNode(pLinkedList head, int data) {
    head->data++;
    pLinkedList current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    pLinkedList new_node = (pLinkedList)malloc(sizeof(LLNode));
    if (new_node == NULL) {
        printf("Failed to allocate memory for new_node.\n");
        return 1;
    }
    new_node->data = data;
    new_node->next = NULL;
    current->next = new_node;
    return 0;
}

int deleteNode(pLinkedList head, int data) {
    pLinkedList current = head;
    pLinkedList prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

int freeLinkedList(pLinkedList head) {
    pLinkedList current = head;
    while (current != NULL) {
        pLinkedList next_node = current->next;
        free(current);
        current = next_node;
    }
    return 0;
}