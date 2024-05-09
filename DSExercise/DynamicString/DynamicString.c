/**
 * @file String.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief https://jnnls4etqn.feishu.cn/wiki/YieawGhKcicGnWkNMngcRkPdntd
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "DynamicString.h"

#define MAX_INPUT_STRING 1000
#define MAX_SUBSTRING 999
char* gSplitString = ",";

int labDynamicString(void)
{
    char inputString[MAX_INPUT_STRING];
    char replaceString[MAX_INPUT_STRING];
    char *substrings[MAX_SUBSTRING] = {NULL};
    int numSubstrings = 0;
    // User input
    printf("Please input a string with {}: \n");
    fgets(inputString, sizeof(inputString), stdin);
    printf("Please input substring to replace with: \n");
    fgets(replaceString, sizeof(replaceString), stdin);
    if (replaceString[strlen(replaceString) - 1] == '\n') {
        replaceString[strlen(replaceString) - 1] = '\0';
    }// Remove the newline character

    // Get the substrings and its number
    numSubstrings = extractReplaceString(replaceString, substrings);    

    // // Print the substrings
    // for (int i = 0; i < numSubstrings; i++) {
    //     printf("substring[%d] = %s\n", i, substrings[i]);
    // }

    char* outputString = formatString(inputString, substrings, numSubstrings);
    
    if (outputString == NULL) {
        printf("Please check index.\n");
        return -1;
    } else {
        printf("Output string: %s\n", outputString);
        return 0;
    }
}

int extractReplaceString(char *replaceString, char **substrings) {
    int count = 0;
    char *token = NULL;
    char *copyReplaceString = malloc(strlen(replaceString) + 1);
    if (copyReplaceString == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    strcpy(copyReplaceString, replaceString); // Copy the replaceString to copyReplaceString
    
    // Split the replaceString by ","
    token = strtok(copyReplaceString, gSplitString);
    while (token != NULL) {
        // Allocate memory for each substring
        substrings[count] = malloc(strlen(token) + 1);
        if (!substrings[count]) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        strcpy(substrings[count], token);

        // //Remove double quotes if they exist
        // if (token[0] == '"') {
        //     // Calculate the length of the new string
        //     size_t new_len = strlen(token) - 2;
            
        //     // Allocate memory for the new string
        //     substrings[count] = (char *)malloc(new_len + 1);
        //     if (substrings[count] == NULL) {
        //         perror("malloc failed");
        //         exit(EXIT_FAILURE);
        //     }

        //     // Copy the substring without the double quotes
        //     strncpy(substrings[count], token + 1, new_len);
        //     substrings[count][new_len] = '\0'; // End the string with '\0'
        // } else {
        //     // If there are no double quotes, just copy the token
        //     substrings[count] = strdup(token);
        //     if (substrings[count] == NULL) {
        //         perror("strdup failed");
        //         exit(EXIT_FAILURE);
        //     }
        // }
        count++;
        token = strtok(NULL, gSplitString);
    }
    free(copyReplaceString);
    return count;
}

char* formatString(char* formatString, char* substring[], int numSubstrings) {
    // Calculate the length of the output string
    int substringsLength = 0;
    for (int i = 0; i < numSubstrings; i++) {
        substringsLength += strlen(substring[i]);
    }
    char* outputString = (char*)malloc(strlen(formatString) + substringsLength + 1);
    int i, j, index;
    char tempString[100];

    strcpy(outputString, ""); // Clear the output string
    for (i = 0; formatString[i] != '\0'; i++) {
        if (formatString[i] == '{') {
            int leftBrace = i;
            int rightBrace = 0;
            char indexString[3]; // Max index is 999
            i++;
            for (j = 0; formatString[i] != '}'; i++, j++) {
                indexString[j] = formatString[i];
            }
            rightBrace = i;
            index = atoi(indexString);

            // Check if the index is valid
            if (index < 0 || index >= numSubstrings) {
                printf("Invalid index %d\n", index);
                return NULL;
            }

            sprintf(tempString, "%s", substring[index]);
            strcat(outputString, tempString);
        } else {
            strncat(outputString, &formatString[i], 1);
        }
    }
    return outputString;
}