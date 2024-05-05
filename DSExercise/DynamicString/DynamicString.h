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
 * @brief 
 * 
 * @return int 
 */
int labDynamicString(void);

int extractReplaceString(char *replaceString, char **substring);

char* format_string(char* format_str, char* substring[]);

#endif // _STRING_H_