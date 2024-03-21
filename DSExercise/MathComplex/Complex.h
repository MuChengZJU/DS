// ���帴�����ݽṹ
typedef struct tagComplex
{
	float fReal;
	float fImage;
} Complex, *LPComplex;

// ��������
LPComplex CreateComplex();

// ���ٸ���
void DestroyComplex(LPComplex *psCpx);

// ��������ֵ
int AssignComplex(Complex *psCpx, float fReal, float fImage);

// ��ȡ������ʵ��ֵ
float GetReal(Complex sCpx);

// ��ȡ�������鲿ֵ
int GetImage(Complex sCpx, float *pImage);

// �������������ĺ�
int AddComplex(Complex sCpx1, Complex sCpx2, Complex *psSum);

// �������������Ĳ�
int SubComplex(Complex sCpx1, Complex sCpx2, Complex *psSub);

// �������������Ļ�
int MulComplex(Complex sCpx1, Complex sCpx2, Complex *psMul);

// ����������������
int DivComplex(Complex sCpx1, Complex sCpx2, Complex *psDiv);

// ��ӡ����
void PrintComplex(Complex sCpx1);