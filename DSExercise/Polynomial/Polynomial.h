#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct PolyNode{
    double coef;
    int exp;
    struct PolyNode *next;
} PolyNode, *pPoly;

pPoly createPoly();

void destroyPoly(pPoly poly);

void insertTerm(pPoly poly, double coef, int exp);

void addPoly(pPoly poly1, pPoly poly2, pPoly result);

void subPoly(pPoly poly1, pPoly poly2, pPoly result);

void mulPoly(pPoly poly1, pPoly poly2, pPoly result);

void printPoly(pPoly poly);

#endif // POLYNOMIAL_H