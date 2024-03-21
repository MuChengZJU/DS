#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"

int MathComplex() 
{
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psRes = NULL;

	// 为指针psRes分配内存空间
	//psRes = (LPComplex)malloc(sizeof(Complex));
	psRes = CreateComplex();
	if (psRes == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========复数四则运算器===========\n");
	printf("\n");
	// 接收用户输入，构建第一个复数
	printf("请输入第一个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	if(sscanf(buffer, "%f %f", &fReal, &fImage) != 2) {
		printf("输入的不是一个有效的复数！按任意键返回主菜单\n");
		fgets(buffer, 100, stdin);
		return 1;
	}
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("你输入的第一个复数是：");
    PrintComplex(sCpx1);
    printf("\n\n");

	// 接收用户输入，构建第一个复数
	printf("请输入第二个复数的实部和虚部：");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if(sscanf(buffer, "%f %f", &fReal, &fImage) != 2) {
		printf("输入的不是一个有效的复数！按任意键返回主菜单\n");
		fgets(buffer, 100, stdin);
		return 1;
	}
	AssignComplex(&sCpx2, fReal, fImage);

    printf("你输入的第二个复数是：");
    PrintComplex(sCpx2);
    printf("\n\n");

	// // 四则运算菜单和选择
	// int choice;
	// printf("请选择你要进行的运算：\n");
	// printf("1. 加法\n");
	// printf("2. 减法\n");
	// printf("3. 乘法\n");
	// printf("4. 除法\n");
	// scanf("%d", &choice);

	// switch (choice)
	// {
	// case 1:
	// 	// 计算两个复数的和
	// 	AddComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 2:
	// 	// 计算两个复数的差
	// 	SubComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 3:
	// 	// 计算两个复数的积
	// 	MulComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 4:
	// 	// 计算两个复数的商
	// 	DivComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// default:
	// 	printf("请输入有效的序号！\n");
	// 	break;
	// }

	// 输出加减乘除的结果
 	printf("两个复数的和是：");
	AddComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("两个复数的差是：");
	SubComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("两个复数的积是：");
	MulComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("两个复数的商是：");
	switch(DivComplex(sCpx1, sCpx2, psRes)) {
		case 0:
			PrintComplex(*psRes);
			printf("\n");
			break;
		case 1:
			printf("错误：psRes空指针\n");
			break;
		case 2:
			printf("除数不能为0！\n");
			break;
	}

		// 释放psRes指向的内存空间
	//free(psRes);
	DestroyComplex(&psRes);

	system("pause");

	return 0;
}