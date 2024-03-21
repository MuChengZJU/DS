#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"

int MathComplex() 
{
	Complex sCpx1 = { 0.0f, 0.0f };
	Complex sCpx2 = { 0.0f, 0.0f };
	LPComplex psRes = NULL;

	// Ϊָ��psRes�����ڴ�ռ�
	//psRes = (LPComplex)malloc(sizeof(Complex));
	psRes = CreateComplex();
	if (psRes == NULL)
		return 1;

	float fReal, fImage;
	char buffer[100];

	printf("===========��������������===========\n");
	printf("\n");
	// �����û����룬������һ������
	printf("�������һ��������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	if(sscanf(buffer, "%f %f", &fReal, &fImage) != 2) {
		printf("����Ĳ���һ����Ч�ĸ�������������������˵�\n");
		fgets(buffer, 100, stdin);
		return 1;
	}
	if (AssignComplex(&sCpx1, fReal, fImage) == 1)
		return 1;

    printf("������ĵ�һ�������ǣ�");
    PrintComplex(sCpx1);
    printf("\n\n");

	// �����û����룬������һ������
	printf("������ڶ���������ʵ�����鲿��");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f %f", &fReal, &fImage);
	if(sscanf(buffer, "%f %f", &fReal, &fImage) != 2) {
		printf("����Ĳ���һ����Ч�ĸ�������������������˵�\n");
		fgets(buffer, 100, stdin);
		return 1;
	}
	AssignComplex(&sCpx2, fReal, fImage);

    printf("������ĵڶ��������ǣ�");
    PrintComplex(sCpx2);
    printf("\n\n");

	// // ��������˵���ѡ��
	// int choice;
	// printf("��ѡ����Ҫ���е����㣺\n");
	// printf("1. �ӷ�\n");
	// printf("2. ����\n");
	// printf("3. �˷�\n");
	// printf("4. ����\n");
	// scanf("%d", &choice);

	// switch (choice)
	// {
	// case 1:
	// 	// �������������ĺ�
	// 	AddComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 2:
	// 	// �������������Ĳ�
	// 	SubComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 3:
	// 	// �������������Ļ�
	// 	MulComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// case 4:
	// 	// ����������������
	// 	DivComplex(sCpx1, sCpx2, psRes);
	// 	break;
	// default:
	// 	printf("��������Ч����ţ�\n");
	// 	break;
	// }

	// ����Ӽ��˳��Ľ��
 	printf("���������ĺ��ǣ�");
	AddComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("���������Ĳ��ǣ�");
	SubComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("���������Ļ��ǣ�");
	MulComplex(sCpx1, sCpx2, psRes);
	PrintComplex(*psRes);
	printf("\n");

	printf("�������������ǣ�");
	switch(DivComplex(sCpx1, sCpx2, psRes)) {
		case 0:
			PrintComplex(*psRes);
			printf("\n");
			break;
		case 1:
			printf("����psRes��ָ��\n");
			break;
		case 2:
			printf("��������Ϊ0��\n");
			break;
	}

		// �ͷ�psResָ����ڴ�ռ�
	//free(psRes);
	DestroyComplex(&psRes);

	system("pause");

	return 0;
}