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
            printf("\n请输入有效的序号！\n\n");
            system("pause");
            break;
        }
	} while (chKey != '0');

    return 0;
}

void PrintMenu()
{
    // system("cls");
	printf("===========数据结构与算法分析编程练习集===========\n\n");
    printf("--1. 实数四则运算器\n");
    printf("--2. 复数四则运算器\n");
    printf("--3. 线性表练习\n");
    printf("--4. 多项式运算\n");
    printf("--5. 栈表达式求值\n");
    printf("--0. 退出\n\n");
	printf("=============================================\n\n");
    printf("请输入序号选择你想执行的编程练习: ");
}
