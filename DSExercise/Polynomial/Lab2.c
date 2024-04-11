#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

int inputPoly(pPoly poly1, pPoly poly2);

int polynomialCalcutation() {
    // Init Polynomials
    pPoly poly1 = createPoly();
    pPoly poly2 = createPoly();

    // Input Polynomials
    if(inputPoly(poly1, poly2)) {
        return 1;
    }
    printf("First polynomial :\n");
    printPoly(poly1);
    printf("Second polynomial :\n");
    printPoly(poly2);
    
    // Addition
    pPoly result = createPoly();
    addPoly(poly1, poly2, result);
    printf("Addition :\n");
    printPoly(result);
    destroyPoly(result);

    // Subtract
    result = createPoly();
    subPoly(poly1, poly2, result);
    printf("Subtraction :\n");
    printPoly(result);
    destroyPoly(result);

    // Multiply
    result = createPoly();
    mulPoly(poly1, poly2, result);
    printf("Multiplication :\n");
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
    printf("Please input first polynomial ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for (int i = 0; i < length; i++) {
        if (scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        else {
            addTerm(poly1, coef, exp);
        }
    }

    // Input second polynomial
    printf("Please input the length of second polynomial:\n");
    if (scanf("%d", &length) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Please input second polynomial ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for (int i = 0; i < length; i++) {
        if (scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        else {
            addTerm(poly2, coef, exp);
        }
    }

    return 0;
}