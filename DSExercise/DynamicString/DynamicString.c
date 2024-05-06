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
#include "DynamicString.h"

#define MAX_INPUT_STRING 1000
#define MAX_SUBSTRING 999

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

    // Get the substrings and its number
    numSubstrings = extractReplaceString(replaceString, substrings);    

    // // Print the substrings
    // for (int i = 0; i < numSubstrings; i++) {
    //     printf("substring[%d] = %s\n", i, substrings[i]);
    //     free(substrings[i]);;
    // }

    char* output_str = format_string(inputString, substrings);
    printf("Output string: %s\n", output_str);

    return 0;
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
    token = strtok(copyReplaceString, ",");
    while (token != NULL) {
        // Allocate memory for each substring
        substrings[count] = malloc(strlen(token) + 1);
        if (!substrings[count]) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        strcpy(substrings[count], token);

        //Remove double quotes if they exist
        if (token[0] == '"') {
            // 计算不包含双引号的字符串长度
            size_t new_len = strlen(token) - 2;
            
            // 为新的字符串分配内存
            substrings[count] = (char *)malloc(new_len + 1);
            if (substrings[count] == NULL) {
                perror("malloc failed");
                exit(EXIT_FAILURE);
            }

            // 复制不包含双引号的字符串
            strncpy(substrings[count], token + 1, new_len);
            substrings[count][new_len] = '\0'; // 确保字符串以空字符结尾
        } else {
            // 如果 token 不以双引号开始，直接复制整个 token
            substrings[count] = strdup(token);
            if (substrings[count] == NULL) {
                perror("strdup failed");
                exit(EXIT_FAILURE);
            }
        }
        count++;
        token = strtok(NULL, ",");
    }
    free(copyReplaceString);
    return count;
}

char* format_string(char* format_str, char* substring[]) {
    char* output_str = (char*)malloc(strlen(format_str) + 1);
    int i, j, index;
    char temp_str[100];

    strcpy(output_str, "");
    for (i = 0; format_str[i] != '\0'; i++) {
        if (format_str[i] == '{') {
            i++;
            index = format_str[i] - '0';
            sprintf(temp_str, "%s", substring[index]);
            strcat(output_str, temp_str);
        } else {
            strncat(output_str, &format_str[i], 1);
        }
    }
TODO:
    return output_str;
}