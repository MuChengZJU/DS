/**
 * @file SeqList.c
 * @author MuCheng (QuChuanyang@ZJU.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "SeqList.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

PSeqList createSeqList() {
    PSeqList pSeqList = (PSeqList)malloc(sizeof(SeqList));
    if (pSeqList == NULL) {
        return NULL;
    }
    pSeqList->length = 0;
    pSeqList->capacity = SEQLIST_INIT_LENGTH;
    pSeqList->pElements = (int*)malloc(sizeof(int) * pSeqList->capacity);
    return pSeqList;
}

void destroySeqList(PSeqList *pSeqList) {
    if (pSeqList == NULL || *pSeqList == NULL) {
        return;
    }
    free((*pSeqList)->pElements);
    free(*pSeqList);
    *pSeqList = NULL;
}

int sequentialSearchElement(PSeqList pSeqList, int element, int* pExists) {
    int index = 0;
    *pExists = 0;

    // Sequential search process
    for(index = 0; index < pSeqList->length; index++) {
        if (pSeqList->pElements[index] == element) {
            *pExists = 1;
            return index;
        }
        if (pSeqList->pElements[index] > element && pSeqList->pElements[index-1] < element) {
            *pExists = 0;
            return index - 1;
        }
    }
}

int binarySearchElement(PSeqList pSeqList, int element, int* pExists) {
    int leftIndex = 0;
    int rightIndex = pSeqList->length - 1;
    int midIndex =  (leftIndex + rightIndex) / 2;
    int ret = -1;

    while(ret == -1) {
        // Break conditions
        if(pSeqList->pElements[midIndex] == element) {
            *pExists = 1;
            ret = midIndex;
            break;
        }
        else if(midIndex == leftIndex) {
            *pExists = 0;
            ret = midIndex;
            break;
        }

        // Binary search recursion
        if(pSeqList->pElements[midIndex] > element) {
            rightIndex = midIndex;
        }
        else {
            leftIndex = midIndex;
        }
        midIndex = (leftIndex + rightIndex) / 2;
    }

    return ret;
}

int insertElement(PSeqList pSeqList, int index, int element) {
    //Check if index is leagal
    if(index < 0 || index > pSeqList->length) {
        return -1;
    }
    if(pSeqList->length >= pSeqList->capacity) {
        //Reallocate memory
        pSeqList->capacity += SEQLIST_INCREMENT;
        pSeqList->pElements = (int*)realloc(pSeqList->pElements, pSeqList->capacity * sizeof(int));
        if(pSeqList->pElements == NULL) {
            return -1;
        }
    }
    
    //Shift elements to the right
    for(int i = pSeqList->length; i > index + 1; i--) {
        pSeqList->pElements[i] = pSeqList->pElements[i-1];
    }
    pSeqList->pElements[index+1] = element;
    pSeqList->length++;

    return 0;
}

int deleteElement(PSeqList pSeqList, int index) {
    //Check if index is leagal
    if(index < 0 || index >= pSeqList->length) {
        return -1;
    }

    //Shift elements to the left
    for(int i = index; i < pSeqList->length - 1; i++) {
        pSeqList->pElements[i] = pSeqList->pElements[i+1];
    }
    pSeqList->length--;

    return 0;
}

int printSeqList(PSeqList pSeqList) {
    for(int i = 0; i < pSeqList->length; i++) {
        printf("%d ", pSeqList->pElements[i]);
    }
    printf("\n");
    return 0;
}

PSeqList generateRandomSeqList(int length) {
  PSeqList pSeqList = createSeqList();
  if (pSeqList == NULL) {
    printf("Failed to create SeqList.\n");
    return NULL;
  }
  pSeqList->length = length;
  pSeqList->pElements[0] = rand() % 100; // Set the first element randomly

  for (int i = 1; i < length; i++) {
    pSeqList->pElements[i] = pSeqList->pElements[i-1] + rand() % 100; // Set the next element as the previous element plus a random value
  }

  printf("Successfully Generated the Non-Strictly Increasing Ordered Random SeqList:\n");
  printSeqList(pSeqList);
  return pSeqList;
}