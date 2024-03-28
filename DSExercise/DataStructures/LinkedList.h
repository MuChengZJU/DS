#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file LinkedList.h
 * @brief Header file for a linked list implementation.
 */

/**
 * @struct LLNode
 * @brief Structure representing a node in the linked list.
 */
typedef struct LLNode{
    int data; /**< Data stored in the node */
    struct LLNode *next; /**< Pointer to the next node */
} LLNode, *pLinkedList;

/**
 * @brief Creates an empty linked list.
 * @return Pointer to the head of the linked list.
 */
pLinkedList createLinkedList();

/**
 * @brief Inserts a new node with the given data into the linked list.
 * @param head Pointer to the head of the linked list.
 * @param data Data to be inserted.
 * @return 1 if the insertion is successful, 0 otherwise.
 */
int insertNode(pLinkedList head, int data);

/**
 * @brief Deletes the first occurrence of a node with the given data from the linked list.
 * @param head Pointer to the head of the linked list.
 * @param data Data to be deleted.
 * @return 1 if the deletion is successful, 0 otherwise.
 */
int deleteNode(pLinkedList head, int data);

/**
 * @brief Reverses the order of nodes in the linked list.
 * @param head Pointer to the head of the linked list.
 * @return 1 if the reversal is successful, 0 otherwise.
 */
int reverseLinkedList(pLinkedList head);

/**
 * @brief Prints the elements of the linked list.
 * @param head Pointer to the head of the linked list.
 * @return 1 if the printing is successful, 0 otherwise.
 */
int printLinkedList(pLinkedList head);

/**
 * @brief Frees the memory allocated for the linked list.
 * @param head Pointer to the head of the linked list.
 * @return 1 if the freeing is successful, 0 otherwise.
 */
int freeLinkedList(pLinkedList head);

/**
 * @brief Compares two linked lists for equality.
 * @param A Pointer to the head of the first linked list.
 * @param B Pointer to the head of the second linked list.
 * @return 1 if the linked lists are equal, 0 otherwise.
 */
int compareLists(pLinkedList A, pLinkedList B);

/**
 * @brief Takes user input to populate the linked list.
 * @param head Pointer to the head of the linked list.
 * @return 1 if the input is successful, 0 otherwise.
 */
int inputLinkedList(pLinkedList head);

#endif