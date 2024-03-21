/**
 * @file hw2.c
 * @author MuCheng (QuChuanyang@zju.edu.cn)
 * @brief https://jnnls4etqn.feishu.cn/wiki/KDrWwEJCYi6ViUkwOGmc6mIjnae?from=from_copylink
 * @version 0.1
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "stdio.h"
#include "SeqList\SeqList.h"

int problem_2_11(void);

int problem_2_12(void);

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char *argv[]) {
  problem_2_11();
  return 0;
}

int problem_2_11() {
  int choiceGeneration = 0;
  do {
    printf("----- Problem 2.11 -----\n");
    printf("Please Select How to Generate the SeqList:\n");
    printf("1. Manually\n");
    printf("2. Randomly\n");
    printf("0. EXIT\n");

    scanf("%d", &choiceGeneration);
    PSeqList pSeqList;
    
    if (choiceGeneration == 0) {
      printf("Exiting...\n");
      break;
    }
    switch (choiceGeneration) {
      case 1:
      {
        int flagOrder = 1;
        pSeqList = createSeqList();
        if (pSeqList == NULL) {
          printf("Failed to create SeqList.\n");
          return -1;
        }

        printf("Please Input the Length of the SeqList:\n");
        scanf("%d", &pSeqList->length);
        printf("Please Input the Elements of the SeqList:\n");
        for (int i = 0; i < pSeqList->length; i++) {
          scanf("%d", &pSeqList->pElements[i]);
        }

        // Check if the SeqList is in non-sticktly increasing order
        for (int i = 1; i < pSeqList->length; i++) {
          if(pSeqList->pElements[i] < pSeqList->pElements[i-1]) {
            flagOrder = 0;
            break;
          } else {
            flagOrder = 1;
          }
        }
        if (flagOrder) {
          printf("Successfully Created the Non-Sticktly Increasing Ordered SeqList.\n");
          break;
        } else {
          printf("The SeqList Contains Descending Portions or Illeagal, Please Check Your Input.\n");
          printf("Here's What You Entered:\n");
          printSeqList(pSeqList);
          printf("\nPress Any Key to Exit\n");
          char buffer[100];
          fgets(buffer, 100, stdin);
          break;
        }
      }
      case 2:
      {
        int randomSeqListLength;
        printf("Please Input the Length of the SeqList:\n");
        scanf("%d", &randomSeqListLength);
        pSeqList = generateRandomSeqList(randomSeqListLength);
        break;
      }
      default:
        printf("Invalid choiceGeneration.\n");
        break;
        }

    int element = 0;
    printf("Please Input the Integar to Insert:\n");
    scanf("%d", &element);

    int choiceSearch = 0;
    printf("Please Select the Search Method:\n");
    printf("1. Sequential Search\n");
    printf("2. Binary Search\n");
    scanf("%d", &choiceSearch);

    int insertIndex;
    int searchExists = 0;
    int *pExists = &searchExists;

    switch (choiceSearch)
    {
    case 1:
      insertIndex = sequentialSearchElement(pSeqList, element, pExists);
      break;
    case 2:
      insertIndex = binarySearchElement(pSeqList, element, pExists);
      break;
    default:
      printf("Invalid Search Choice.\n");
      break;
    }

    if(insertElement(pSeqList, insertIndex, element)) {
      printf("Failed to Insert the Element.\n");
    } else {
      printf("Successfully Inserted the Element.\n");
      printf("Here's the Updated SeqList:\n");
      printSeqList(pSeqList);
    }


  }while(choiceGeneration);

}

int problem_2_12() {
  
}