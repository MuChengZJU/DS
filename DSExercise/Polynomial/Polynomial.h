#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct PolyNode{
    double coef;
    int exp;
    struct PolyNode *next;
} PolyNode, *pPoly;

/**
 * @brief Creates a new polynomial.
 * 
 * @return A pointer to the newly created polynomial.
 */
pPoly createPoly();

/**
 * @brief Destroys a polynomial and frees the memory.
 * 
 * @param poly The polynomial to destroy.
 */
void destroyPoly(pPoly poly);

/**
 * @brief Inserts a term into the polynomial.
 * 
 * @param poly The polynomial to insert the term into.
 * @param coef The coefficient of the term.
 * @param exp The exponent of the term.
 */
void insertTerm(pPoly poly, double coef, int exp);

/**
 * @brief Adds two polynomials and stores the result in another polynomial.
 * 
 * @param poly1 The first polynomial.
 * @param poly2 The second polynomial.
 * @param result The polynomial to store the result in.
 */
void addPoly(pPoly poly1, pPoly poly2, pPoly result);

/**
 * @brief Subtracts one polynomial from another and stores the result in another polynomial.
 * 
 * @param poly1 The polynomial to subtract from.
 * @param poly2 The polynomial to subtract.
 * @param result The polynomial to store the result in.
 */
void subPoly(pPoly poly1, pPoly poly2, pPoly result);

/**
 * @brief Multiplies two polynomials and stores the result in another polynomial.
 * 
 * @param poly1 The first polynomial.
 * @param poly2 The second polynomial.
 * @param result The polynomial to store the result in.
 */
void mulPoly(pPoly poly1, pPoly poly2, pPoly result);

/**
 * @brief Prints the polynomial.
 * 
 * @param poly The polynomial to print.
 */
void printPoly(pPoly poly);

void sortPoly(pPoly poly);

#endif // POLYNOMIAL_H