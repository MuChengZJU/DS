#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

int inputPoly(pPoly poly1, pPoly poly2);

int polynomialCalcutation() {
    // Init Polynomials
    pPoly poly1 = createPoly();
    pPoly poly2 = createPoly();

    inputPoly(poly1, poly2);
    sortPoly(poly1);
    sortPoly(poly2);

    printf("The first polynomial is:\n");
    printPoly(poly1);
    printf("The second polynomial is:\n");
    printPoly(poly2);
    
    pPoly result = createPoly();
    addPoly(poly1, poly2, result);
    printf("The result of addition is:\n");
    // sortPoly(result); // result should be already sorted
    printPoly(result);
    destroyPoly(result);

    result = createPoly();
    subPoly(poly1, poly2, result);
    printf("The result of subtraction is:\n");
    // sortPoly(result);
    printPoly(result);
    destroyPoly(result);

    result = createPoly();
    mulPoly(poly1, poly2, result);
    printf("The result of multiplication is:\n");
    // sortPoly(result);
    printPoly(result);
    destroyPoly(result);

    system("pause");

    destroyPoly(poly1);
    destroyPoly(poly2);

    // return 0;
}

int inputPoly(pPoly poly1, pPoly poly2) {
    // Variables
    int length;
    double coef;
    int exp;

    // User Prompt
    printf("======Lab2 Polynomial======\n");

    // Input first polynomial
    printf("Please input the length of first polynomial:\n");
    if (scanf("%d", &length) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Please input polynomial 1 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for (int i = 0; i < length; i++) {
        if (scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        insertTerm(poly1, coef, exp);
    }

    // Input second polynomial
    printf("Please input the length of second polynomial:\n");
    if (scanf("%d", &length) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Please input polynomial 2 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for (int i = 0; i < length; i++) {
        if (scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        insertTerm(poly2, coef, exp);
    }

    return 0;
}