#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "..\MathComplex\Complex.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("����������ִ�еĲ���������");

        return 1;
    }
    
    if (strcmp(argv[1], "complex") == 0)
    {
        if (strcmp(argv[2], "AssignComplex") == 0)
        {
            Complex sComplex = {0.0f, 0.0f};
            AssignComplex(&sComplex, (float)atof(argv[3]), (float)atof(argv[4]));
            PrintComplex(sComplex);
        } 
        else if (strcmp(argv[2], "CreateComplex") == 0)
        {
            LPComplex pComplex = NULL;
            pComplex = CreateComplex();
            PrintComplex(*pComplex);
            DestroyComplex(&pComplex);
        }
        else if (strcmp(argv[2], "DestroyComplex") == 0)
        {
            LPComplex pComplex = NULL;
            pComplex = CreateComplex();
            DestroyComplex(&pComplex);
            printf("0x%p", (void *)pComplex);
        }
        else if (strcmp(argv[2], "GetReal") == 0)
        {
            if (argc < 5)
            {
                printf("������Ĳ��������Ĳ���������");
            
                return 2;
            }

            Complex sComplex = {0.0f, 0.0f};
            AssignComplex(&sComplex, (float)atof(argv[3]), (float)atof(argv[4]));
            printf("%.2f", GetReal(sComplex));
        }
        else if (strcmp(argv[2], "GetImage") == 0)
        {
            if (argc < 5)
            {
                printf("������Ĳ��������Ĳ���������");
            
                return 2;
            }

            Complex sComplex = {0.0f, 0.0f};
            AssignComplex(&sComplex, (float)atof(argv[3]), (float)atof(argv[4]));
            float fImage = 0.0f;
            GetImage(sComplex, &fImage);
            printf("%.2f", fImage);
        }
        else if (strcmp(argv[2], "AddComplex") == 0)
        {
            if (argc < 7)
            {
                printf("������Ĳ��������Ĳ���������");
            
                return 2;
            }

            Complex sComplex1 = {0.0f, 0.0f};
            Complex sComplex2 = {0.0f, 0.0f};
            Complex sComplexSum = {0.0f, 0.0f};
            AssignComplex(&sComplex1, (float)atof(argv[3]), (float)atof(argv[4]));
            AssignComplex(&sComplex2, (float)atof(argv[5]), (float)atof(argv[6]));
            AddComplex(sComplex1, sComplex2, &sComplexSum);
            PrintComplex(sComplexSum);
        }
        else
        {
            printf("��������Ч�Ĳ���������");

            return 3;
        }
     }

    return 0;
}