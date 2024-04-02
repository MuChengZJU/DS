#include "Polynomial.h"
#include <stdio.h>
#include <stdlib.h>

pPoly createPoly() {
    pPoly poly = (pPoly)malloc(sizeof(PolyNode));
    if (poly == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    poly->next = NULL;
    return poly;
}

void destroyPoly(pPoly poly) {
    pPoly p = poly->next;
    while (p != NULL) {
        pPoly q = p;
        p = p->next;
        free(q);
    }
    free(poly);
}

void insertTerm(pPoly poly, double coef, int exp) {
    if (coef == 0) {
        return;
    }

    // Init Pointer and Find the Last Term
    pPoly p = poly;
    while (p->next != NULL) {
        p = p->next;
    }

    // Insert New Term
    pPoly newTerm = (pPoly)malloc(sizeof(PolyNode));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->coef = coef;
    newTerm->exp = exp;
    newTerm->next = NULL;
    p->next = newTerm;
}

void addPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;
    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {
            insertTerm(r, q->coef, q->exp);
            q = q->next;
        } else if (p->exp > q->exp) {
            insertTerm(r, p->coef, p->exp);
            p = p->next;
        } else {
            insertTerm(r, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        insertTerm(r, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        insertTerm(r, q->coef, q->exp);
        q = q->next;
    }

}

void subPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;
    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {
            insertTerm(r, -q->coef, q->exp);
            q = q->next;
        } else if (p->exp > q->exp) {
            insertTerm(r, p->coef, p->exp);
            p = p->next;
        } else {
            insertTerm(r, p->coef - q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        insertTerm(r, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        insertTerm(r, -q->coef, q->exp);
        q = q->next;
    }

    result = r;

}

void mulPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;
    while (p != NULL) {
        q = poly2->next;
        while (q != NULL) {
            insertTerm(r, p->coef * q->coef, p->exp + q->exp);
            q = q->next;
        }
        p = p->next;
    }
    result = r;
}

void printPoly(pPoly poly) {    
    pPoly p = poly->next;

    // Empty polynomial
    if (p == NULL) {
        printf("0\n");
        return;
    }

    // First term
    if (p->exp == 0) {
        printf("%.2f", p->coef);
    } else if (p->exp == 1) {
        printf("%.2fx", p->coef);
    } else {
        printf("%.2fx^%d", p->coef, p->exp);
    }

    // Rest terms
    p = p->next;
    while (p != NULL) {
        if (p->exp == 0) {
            printf(" %+.2f", p->coef);
        } else if (p->exp == 1) {
            printf(" %+.2fx", p->coef);
        } else {
            printf(" %+.2fx^%d", p->coef, p->exp);
        }
        p = p->next;
    }
    printf("\n");
}

void sortPoly(pPoly poly) {
    pPoly p = poly->next;
    pPoly q = p->next;
    while (p != NULL) {
        while (q != NULL) {
            if (p->exp < q->exp) {
                // Swap
                double tempCoef = p->coef;
                int tempExp = p->exp;
                p->coef = q->coef;
                p->exp = q->exp;
                q->coef = tempCoef;
                q->exp = tempExp;
            }
            q = q->next;
        }
        p = p->next;
    }
}