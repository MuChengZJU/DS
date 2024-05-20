/**
 * @file seqlist.h
 * @brief Definition of the SeqList data structure and related functions.
 */

#ifndef SEQLIST_H
#define SEQLIST_H

/**
 * @def SEQLIST_INIT_LENGTH
 * @brief Initial length of the SeqList.
 */
#define SEQLIST_INIT_LENGTH 100

/**
 * @def SEQLIST_INCREMENT
 * @brief Increment size when the SeqList is full.
 */
#define SEQLIST_INCREMENT 10

/**
 * @struct SeqList
 * @brief Structure representing the sequential list.
 */
typedef struct {
    int *pElements; /**< Pointer to the array storing the INT elements */
    int length;     /**< How many elements */
    int capacity;   /**< Max length*/
} SeqList, *PSeqList;

/**
 * @brief Creates a new SeqList.
 * @return Pointer to the newly created SeqList.
 */
PSeqList createSeqList();

/**
 * @brief Destroys a SeqList and releases memory.
 * @param[in,out] pSeqList Pointer to the pointer of the SeqList.
 */
void destroySeqList(PSeqList *pSeqList);

/**
 * @brief Performs sequential search in the SeqList to find the specified element.
 *
 * This function sequentially searches the SeqList for the specified element. If the element is found, it returns the index
 * of the element. If the element is not found, it returns the index of the closest smaller element and sets the flag
 * to indicate that the element does not exist in the SeqList.
 *
 * @param[in] pSeqList Pointer to the SeqList.
 * @param[in] element Element to search for.
 * @param[out] pExists Pointer to a flag indicating whether the element exists in the SeqList. 1 if exists, 0 if not exists.
 * @return The index of the element if found, or the index of the closest smaller element if not found.
 */
int sequentialSearchElement(PSeqList pSeqList, int element, int* pExists);

/**
 * @brief Performs binary search in the SeqList to find the specified element.
 *
 * This function performs binary search in the SeqList for the specified element. If the element is found, it returns the index
 * of the element. If the element is not found, it returns the index of the closest smaller element and sets the flag
 * to indicate that the element does not exist in the SeqList.
 *
 * @param[in] pSeqList Pointer to the SeqList.
 * @param[in] element Element to search for.
 * @param[out] pExists Pointer to a flag indicating whether the element exists in the SeqList. 1 if exists, 0 if not exists.
 * @return The index of the element if found, or the index of the closest smaller element if not found.
 */
int binarySearchElement(PSeqList pSeqList, int element, int* pExists);

/**
 * @brief  Inserts an element at a specified index in the SeqList, shifting existing elements from that index onwards to the right.
 * @param[in] pSeqList Pointer to the SeqList.
 * @param[in] index Index at which the element should be inserted. Elements at index and beyond will be shifted one position to the right.
 * @param[in] element Element to insert.
 * @return 0 if successful, or -1 if failed.
 */
int insertElement(PSeqList pSeqList, int index, int element);

/**
 * @brief Deletes an element at a specified index from the SeqList.
 * @param[in] pSeqList Pointer to the SeqList.
 * @param[in] index Index of the element to delete.
 * @return 0 if successful, or -1 if failed.
 */
int deleteElement(PSeqList pSeqList, int index);


/**
 * @brief Prints the elements of a sequential list.
 *
 * This function prints the elements of a sequential list to the console.
 *
 * @param pSeqList Pointer to the sequential list.
 * @return The number of elements printed.
 */
int printSeqList(PSeqList pSeqList);

/**
 * @brief Generates a random sequential list.
 *
 * This function generates a sequential list of a specified length with random values.
 *
 * @param length The length of the sequential list to generate.
 * @return A pointer to the generated sequential list.
 */
PSeqList generateRandomSeqList(int length);

#endif /* SEQLIST_H */