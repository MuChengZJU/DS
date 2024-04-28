/**
 * @file HW4.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief https://jnnls4etqn.feishu.cn/wiki/ZB1awtYcdiqQdFkQw35c8BWYnhg
 * @version 0.1
 * @date 2024-04-27
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief String data structure definition
 * 
 */
typedef struct {
    char* str;
    int length;
} String;

/**
 * @brief Node for string
 * @brief header node: chdata is "h", succ points to the first node
 */
typedef struct Node {
    char chdata;
    struct Node* succ;
    struct Node* next;
} Node;

/**
 * @brief Replace substring T in S with V. 
 * For example, Replace("Hello, world!", "world", "C language") will return "Hello, C language!"
 * 
 * @param S Source string to be replaced
 * @param T Substring to be replaced
 * @param V New substring to replace with
 */
void Replace(String* S, String T, String V) {
    int i, j, k;
    int pos = 0;
    int new_length = S->length;

    // Calculate and allocate new length
    for (i = 0; i <= S->length - T.length; i++) {
        if (strncmp(S->str + i, T.str, T.length) == 0) {
            new_length = new_length - T.length + V.length;
        }
    }
    char* new_str = (char*)malloc(new_length * sizeof(char));

    // Replace substring
    for (i = 0, j = 0; i < S->length; i++) {
        if (strncmp(S->str + i, T.str, T.length) == 0) { // Find T
            // Append V to new_str
            strcpy(new_str + j, V.str);
            j += V.length;
            i += T.length - 1;
        } else {
            // Copy source string to new_str
            new_str[j++] = S->str[i];
        }
    }

    // free(S->str);
    new_str[new_length] = '\0';
    S->str = new_str;
    S->length = new_length;
}

/**
 * @brief Get next pointer for KMP algorithm
 * 
 * @param pattern Pointer to head node of pattern string
 */
void getNext(Node *pattern) {
    Node *currNode = pattern->succ; // Jump off the head node TODO: from 1st or 2nd node
    Node *succNode = currNode->succ;
    currNode->next = currNode; // First node's next is itself
    Node* nextPtr = currNode->next;
    while (currNode->chdata != '\n') {
        if (currNode->chdata == nextPtr->chdata || nextPtr == pattern) {
            currNode->succ->next = nextPtr->succ;
            currNode = succNode; // Move to next node
        } else {
            nextPtr = nextPtr->next; // Recursive
        }
    }
}

int main() {
    // 4.17 Replace(&S, T, V).
    String S, T, V;
    S.str = "Hello, world! Good morning, world!";
    S.length = strlen(S.str);
    T.str = "world";
    T.length = strlen(T.str);
    V.str = "C language";
    V.length = strlen(V.str);

    Replace(&S, T, V);
    
    printf("New String: %s\n", S.str);

    // free(S.str); // No need to free S.str, because it is not malloced in this demo

    // 4.28
    // Creat pattern string
    Node *pattern = (Node *)malloc(sizeof(Node));
    Node *p = pattern;
    // head node
    p->chdata = 'h';
    p->succ = (Node *)malloc(sizeof(Node));
    p = p->succ;
    p->next = NULL;
    // input pattern string
    printf("Input pattern string: ");
    char ch;
    while ((ch = getchar()) != '\n') {
        p->chdata = ch;
        p->succ = (Node *)malloc(sizeof(Node));
        p = p->succ;
        p->next = NULL;
    }
    // end of pattern string
    p->chdata = '\n';
    p->succ = NULL;

    // getNext
    getNext(pattern);

    free(pattern);

    return 0;
}