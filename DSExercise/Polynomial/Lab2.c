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
    scanf("%d", &length);
    printf("Please input polynomial 1 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for(int i = 0; i < length; i++) {
        double coef;
        int exp;
        scanf("%lf %d", &coef, &exp);
        insertTerm(poly1, coef, exp);
    }
    printf("Please input the length of second polynomial:\n");
    scanf("%d", &length);
    printf("Please input polynomial 2 ( Coef0 Exp0 Coef1 Exp1 ...):\n");
    for(int i = 0; i < length; i++) {
        double coef;
        int exp;
        scanf("%lf %d", &coef, &exp);
        insertTerm(poly2, coef, exp);
    }

    addPoly(poly1, poly2, result);
    printf("The result of addition is:\n");
    printPoly(result);

    subPoly(poly1, poly2, result);
    printf("The result of subtraction is:\n");
    printPoly(result);

    mulPoly(poly1, poly2, result);
    printf("The result of multiplication is:\n");
    printPoly(result);

    system("pause");

    destroyPoly(poly1);
    destroyPoly(poly2);
    destroyPoly(result);

    // return 0;
}