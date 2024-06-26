/**
 * @file LinkedList.c
 * @author MuCheng (QuChuanyang@ZJU.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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

int compareLists(pLinkedList A, pLinkedList B) {
    pLinkedList A_prime = A->next;
    pLinkedList B_prime = B->next;

    while (A_prime != NULL && B_prime != NULL) {
        if (A_prime->data < B_prime->data) {
            return -1; // A < B
        } else if (A_prime->data > B_prime->data) {
            return 1; // A > B
        }

        A_prime = A_prime->next;
        B_prime = B_prime->next;
    }

    if (A_prime == NULL && B_prime == NULL) {
        return 0; // A = B
    } else if (A_prime == NULL && B_prime != NULL) {
        return -1; // A < B
    } else {
        return 1; // A > B
    }
}

int inputLinkedList(pLinkedList head) {
    int data;
    while (scanf("%d", &data) != EOF) {
        insertNode(head, data);
    }
    return 0;

    // char buffer[100];
    // int data;
    // printf("Please input the data for the LinkedList:\n");
    // printf("1");
    // fgets(buffer, 100, stdin);
    // printf("1");
    // while (sscanf(buffer, "%d", &data) == 1) {
    //     printf("1");
    //     insertNode(head, data);
    //     fgets(buffer, 100, stdin);
    // }

    return 0;
}
