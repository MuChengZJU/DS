#include "stdio.h"
#include "stdlib.h"
#include "Polynomial/Polynomial.h"
#include "Expression/Expression.h"

#define MAX_BUFF_SIZE (256)

void PrintMenu();
int MathComplex();
int polynomialCalcutation();

int main(int argc, char* argv[]) 
{
    char chBuffer[MAX_BUFF_SIZE];
    char chKey = '0';
    
	do {
        PrintMenu();

		fgets(chBuffer, MAX_BUFF_SIZE, stdin);
		sscanf(chBuffer, "%c", &chKey, 1);

        switch (chKey)
        {
        case '0':
            break;

        case '1':
        case '3':
            break;

        case '2':
            system("cls");
            MathComplex();        
            break;

        case '4':
            // system("cls");
            polynomialCalcutation();
            break;

        case '5':
            if (Expression() != 0) {
                system("pause");
            }
            break;
        
        default:
            printf("\n��������Ч����ţ�\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

    return 0;
}

void PrintMenu()
{
    // system("cls");
	printf("===========���ݽṹ���㷨���������ϰ��===========\n\n");
    printf("--1. ʵ������������\n");
    printf("--2. ��������������\n");
    printf("--3. ���Ա���ϰ\n");
    printf("--4. ����ʽ����\n");
    printf("--5. ջ���ʽ��ֵ\n");
    printf("--0. �˳�\n\n");
	printf("=============================================\n\n");
    printf("���������ѡ������ִ�еı����ϰ: ");
}
