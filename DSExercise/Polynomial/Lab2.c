#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"

int polynomialCalcutation() {
    pPoly poly1 = createPoly();
    pPoly poly2 = createPoly();
    pPoly result = createPoly();

    printf("======Lab2 Polynomial======\n");
    printf("Please input the length of first polynomial:\n");
    int length;
    if(scanf("%d", &length) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Please input polynomial 1 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for(int i = 0; i < length; i++) {
        double coef;
        int exp;
        if(scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        insertTerm(poly1, coef, exp);
    }
    printf("Please input the length of second polynomial:\n");
    if(scanf("%d", &length) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Please input polynomial 2 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for(int i = 0; i < length; i++) {
        double coef;
        int exp;
        if(scanf("%lf %d", &coef, &exp) != 2) {
            printf("Invalid input\n");
            return 1;
        }
        insertTerm(poly2, coef, exp);
    }
    printf("The first polynomial is:\n");
    printPoly(poly1);
    printf("The second polynomial is:\n");
    printPoly(poly2);
    
    addPoly(poly1, poly2, result);
    printf("The result of addition is:\n");
    sortPoly(result);
    printPoly(result);
    destroyPoly(result);

    result = createPoly();
    subPoly(poly1, poly2, result);
    printf("The result of subtraction is:\n");
    sortPoly(result);
    printPoly(result);
    destroyPoly(result);

    result = createPoly();
    mulPoly(poly1, poly2, result);
    printf("The result of multiplication is:\n");
    sortPoly(result);
    printPoly(result);
    destroyPoly(result);

    system("pause");

    destroyPoly(poly1);
    destroyPoly(poly2);
    destroyPoly(result);

    // return 0;
}