/**
 * @file String.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-05
 * 
 * 
 */

#ifndef _STRING_H_
#define _STRING_H_

/**
 * @brief Construct a sentence containing an indefinite number of digits enclosed in curly braces, such as {0}, {1}, {2}, then prompt the user to input strings, and replace the digits including the curly braces in order, thereby constructing a new sentence.
 * 
 * @return int 
 */
int labDynamicString(void);

/**
 * @brief Turn the replaceString into substrings and return the number of substrings.
 * 
 * @param replaceString A long string. The substrings are separated by gSplitString. And "" is used to represent the substring. 
 * @param substring Store the substrings. Seperate the substrings by '\0'.
 * @return int 
 */
int extractReplaceString(char *replaceString, char **substring);

/**
 * @brief Insert the substrings into the format_str.
 * 
 * @param format_str 
 * @param substring 
 * @param numSubstrings 
 * @return char* 
 */
char* formatString(char* format_str, char* substring[], int numSubstrings);

#endif // _STRING_H_