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

// void insertTerm(pPoly poly, double coef, int exp) {
//     if (coef == 0) {
//         return;
//     }

//     // Init Pointer and Find the Last Term
//     pPoly p = poly;
//     while (p->next != NULL) {
//         p = p->next;
//     }

//     // Insert New Term
//     pPoly newTerm = (pPoly)malloc(sizeof(PolyNode));
//     if (newTerm == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newTerm->coef = coef;
//     newTerm->exp = exp;
//     newTerm->next = NULL;
//     p->next = newTerm;
// }

void addPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;
    while (p->next != NULL && q->next != NULL) {
        if (p->exp < q->exp) {
            addTerm(r, q->coef, q->exp);
            q = q->next;
        } else if (p->exp > q->exp) {
            addTerm(r, p->coef, p->exp);
            p = p->next;
        } else {
            addTerm(r, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        addTerm(r, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        addTerm(r, q->coef, q->exp);
        q = q->next;
    }

}

void subPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;
    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {
            addTerm(r, -q->coef, q->exp);
            q = q->next;
        } else if (p->exp > q->exp) {
            addTerm(r, p->coef, p->exp);
            p = p->next;
        } else {
            addTerm(r, p->coef - q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        addTerm(r, p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        addTerm(r, -q->coef, q->exp);
        q = q->next;
    }

    result = r;

}

void mulPoly(pPoly poly1, pPoly poly2, pPoly result) {
    pPoly p = poly1->next;
    pPoly q = poly2->next;
    pPoly r = result;

    double tempCoef;
    int tempExp;

    while (p != NULL) {

        q = poly2->next;
        while (q != NULL) {
            r = result;
            tempCoef = p->coef * q->coef;
            tempExp = p->exp + q->exp;

            addTerm(r, tempCoef, tempExp);
        
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
        printf("%.6f", p->coef);
    } else if (p->exp == 1) {
        printf("%.6fx", p->coef);
    } else {
        printf("%.6fx^%d", p->coef, p->exp);
    }

    // Rest terms
    p = p->next;
    while (p != NULL) {
        if (p->exp == 0) {
            printf(" %+.6f", p->coef);
        } else if (p->exp == 1) {
            printf(" %+.6fx", p->coef);
        } else {
            printf(" %+.6fx^%d", p->coef, p->exp);
        }
        p = p->next;
    }
    printf("\n");
}

void addTerm(pPoly poly, double coef, int exp) {
    pPoly p = poly;

    // To find the term before the term to be inserted. 
    while (p->next != NULL && p->next->exp >= exp) {
        p = p->next;
    }

    // If the term already exists, add the coefficients.
    if (p->exp == exp) {
        p->coef += coef;
    } else { // Otherwise, insert the new term.
        pPoly newTerm = (pPoly)malloc(sizeof(PolyNode));
        if (newTerm == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        newTerm->coef = coef;
        newTerm->exp = exp;
        newTerm->next = p->next;
        p->next = newTerm;
    }

}
