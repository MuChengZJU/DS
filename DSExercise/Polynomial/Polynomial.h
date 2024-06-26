#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/**
 * @struct PolyNode
 * @brief Structure representing a node in a polynomial.
 * @brief Because of insertTerm, the first node is a dummy node.
 * @brief So that every time init the polynomial, SHOULD start with poly->next.
 */
typedef struct PolyNode{
    double coef; /**< Coefficient of the term */
    int exp; /**< Exponent of the term */
    struct PolyNode *next; /**< Pointer to the next node */
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


/**
 * @brief Add a term to the polynomial. If the term already exists, add the coefficients. *Maintain the order*.
 * 
 * @param poly The polynomial to add the term to. 
 * @param coef The coefficient of the term to add.
 * @param exp The exponent of the term to add.
 */
void addTerm(pPoly poly, double coef, int exp);

#endif // POLYNOMIAL_H