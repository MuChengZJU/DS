#include <stdio.h>
#include <stdbool.h>
#include "Queue/Queue.h"

#define MAX_LENGTH 100
#define MAX_FIBONACCI 114

bool isPalindrome(char sequence[]) {
    int length = 0;
    while (sequence[length] != '@') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (sequence[start] != sequence[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int kFibonacci(int k) {
    CircularQueue *queue;
    initQueue(queue, k);
    enqueue(queue, 0);
    enqueue(queue, 1);
    
}

int main() {
    int choice = 0;

    do {
        printf("---------------------------\n");
        printf("Choose a task to perform: \n");
        printf("1. Check if a character sequence is a palindrome.\n");
        printf("2. k-order Fibonacci Sequence.\n");
        printf("0. Exit.\n");

        scanf("%d", &choice);
            switch (choice) {
                case 0:
                    return 0;
                case 1:
                {
                    char sequence[MAX_LENGTH];
                    printf("Enter a character sequence (end with '@'): \n");
                    scanf("%s", sequence);

                    if (isPalindrome(sequence)) {
                        printf("The sequence is a palindrome.\n");
                    } else {
                        printf("The sequence is not a palindrome.\n");
                    }

                    break;
                }
                case 2:
                {
                    int k;
                    printf("Enter k (k >= 2): \n");
                    scanf("%d", &k);
                    kFibonacci(k);
                    printf("\n");
                    
                    break;
                }
                default:
                    printf("Invalid choice.\n");
                    break;
            }
    } while (choice);

    return 0;
}