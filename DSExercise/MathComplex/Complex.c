#include "stdio.h"
#include "stdlib.h"
#include "Complex.h"
#include "math.h"

// 销毁复数
LPComplex CreateComplex()
{
	// 为复数分配内存空间
	return (LPComplex)malloc(sizeof(Complex));
}

// 销毁复数
void DestroyComplex(LPComplex *psCpx)
{
	free(*psCpx);
	*psCpx = NULL;
}

// 构造复数，其实部和虚部分别被赋以参数 fReal 和 fImage 的值
int AssignComplex( Complex *psCpx, float fReal, float fImage )
{
	if (psCpx == NULL)
		return 1;

	psCpx->fReal = fReal;
	psCpx->fImage = fImage;
	
	return 0;
}

// 获取复数的实部值
float GetReal( Complex sCpx )
{
	return sCpx.fReal;
}

// 获取复数的虚部值
int GetImage(Complex sCpx, float* fImage)
{
	if (fImage == NULL)
		return 1;

	*fImage = sCpx.fImage;

	return 0;
}

// 计算两个复数的和
int AddComplex(Complex sCpx1, Complex sCpx2, Complex* psSum)
{
	if (psSum == NULL)
		return 1;

	psSum->fReal = sCpx1.fReal + sCpx2.fReal;
	psSum->fImage = sCpx1.fImage + sCpx2.fImage;

	return 0;
}

// 计算两个复数的差
int SubComplex(Complex sCpx1, Complex sCpx2, Complex* psSub)
{
	if (psSub == NULL)
		return 1;

	psSub->fReal = sCpx1.fReal - sCpx2.fReal;
	psSub->fImage = sCpx1.fImage - sCpx2.fImage;

	return 0;
}

// 计算两个复数的积
int MulComplex(Complex sCpx1, Complex sCpx2, Complex* psMul)
{
	if (psMul == NULL)
		return 1;

	psMul->fReal = sCpx1.fReal * sCpx2.fReal - sCpx1.fImage * sCpx2.fImage;
	psMul->fImage = sCpx1.fReal * sCpx2.fImage + sCpx1.fImage * sCpx2.fReal;

	return 0;
}

// 计算两个复数的商
int DivComplex(Complex sCpx1, Complex sCpx2, Complex* psDiv)
{
	if (psDiv == NULL)
		return 1;

	float fDenominator = sCpx2.fReal * sCpx2.fReal + sCpx2.fImage * sCpx2.fImage;
	if (fDenominator == 0)
		return 2;


	psDiv->fReal = (sCpx1.fReal * sCpx2.fReal + sCpx1.fImage * sCpx2.fImage) / fDenominator;
	psDiv->fImage = (sCpx1.fImage * sCpx2.fReal - sCpx1.fReal * sCpx2.fImage) / fDenominator;

	return 0;
}

// 打印复数
void PrintComplex(Complex sCpx)
{
    float fReal = GetReal(sCpx);
    float fImage = 0.0f;
    GetImage(sCpx, &fImage);
    
	if (fReal == 0 && fImage == 0)
		// 复数的实部、虚部同时为0，0 + 0i
		printf("%.2f", 0.0f);
	else if (fImage == 0)
	{
		// 仅复数的虚部为0, x + 0i
		printf("%.2f", fReal);
	}
	else if (fReal == 0)
	{
		// 仅复数的实部为0，0 + xi
		printf("%.2fi", fImage);
	}
	else
	{
		// 复数的实部、虚部均不为0，x + yi
		printf("%.2f", fReal);

		if (fImage > 0)
		{
			printf(" + %.2fi", fImage);
		}
		else
		{
			printf(" - %.2fi", fabs(fImage));
		}
	}
	
}