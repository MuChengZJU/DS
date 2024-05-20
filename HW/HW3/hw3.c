#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100 // Maximum length of the character sequence
#define MAX_FIBONACCI 514 // Maximum value of the Fibonacci sequence

/**
 * Checks if a given sequence is a palindrome.
 *
 * @param sequence The sequence to check.
 * @return True if the sequence is a palindrome, false otherwise.
 */
bool isPalindrome(char sequence[]) {
    int length = 0;
    while (sequence[length] != '@') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    // From both ends, check if the characters are equal
    while (start < end) {
        if (sequence[start] != sequence[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

/**
 * Calculates and prints the first k Fibonacci numbers using a circular queue.
 *
 * @param k The number of Fibonacci numbers to calculate and print.
 * @return 0 indicating successful execution of the function.
 */
int kFibonacci(int k) {
    int queue[k];
    for (int i = 0; i < k; i++) {
        queue[i] = 0;
    }
    queue[1] = 1;
    
    // Circular Queue is not full
    if (!queue[k-1]) {
        for (int i = 2; i < k; i++) {
            for (int j = 0; j < i; j++) {
                queue[i] += queue[j];
            }
        }
    }

    // Circular Queue is full
    while (queue[k-1] <= MAX_FIBONACCI) {
        // Print the first element
        printf("%d ", queue[0]);

        // Calculate the next element
        int temp = 0;
        for (int i = 0; i < k; i++) {
            temp += queue[i];
        }

        // Shift the elements
        for (int i = 0; i < k-1; i++) {
            queue[i] = queue[i+1];
        }
        queue[k-1] = temp;
    }

    // Print the rest
    for (int i = 0; i < k; i++) {
        if (queue[i] <= MAX_FIBONACCI) {
            printf("%d ", queue[i]);
        } else {
            break;
        }
    }
    return 0;
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
                case 1: // 3.31
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
                case 2: // 3.32
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