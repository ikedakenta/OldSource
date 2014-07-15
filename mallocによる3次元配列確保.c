/*	-------------�v���O���~���O���K�U�ۑ� 6-----------
�J����	Windows2000	MicrosoftVisualC++6.0	�r�c�@����	*/
#include <stdio.h>/*�W���w�b�_*/
#include <stdlib.h>/**/
#include <string.h>/**/

#define DIM1 640
#define DIM2 480
#define DIM3 3

typedef unsigned char UCHAR;

UCHAR ***malloc_uchar3D(int ,int,int);
void free_uchar3D(UCHAR ***);
void error1(char *);

int main()
{
	char gomi[10];
	int i;
	int dim1,dim2,dim3;
	UCHAR ***org,***res;
	
	org=malloc_uchar3D(DIM1,DIM2,DIM3);
	res=malloc_uchar3D(DIM1,DIM2,DIM3);
	
	/***** �z��̏����� *****/
	printf("�z��̏�������\n");
	for(dim1=0;dim1<DIM1;dim1++)
		for(dim2=0;dim2<DIM2;dim2++)
			for(dim3=0;dim3<DIM3;dim3++)
				org[dim1][dim2][dim3]=(UCHAR)((dim1+dim2+dim3)%256);
			
			/***** �z��̃R�s�[(1000��R�s�[����) *****/
			/*
			for(i=0;i<1000;i++)
			for(dim1=0;dim1<DIM1;dim1++)
				for(dim2=0;dim2<DIM2;dim2++)
					for(dim3=0;dim3<DIM3;dim3++)
						res[dim1][dim2][dim3]=org[dim1][dim2][dim3];
*/
					for(i=0;i<1000;i++){
					int n;
					UCHAR *p1,*p2;
					p1=&org[0][0][0];
					p2=&res[0][0][0];
					for(n=0;n<DIM1*DIM2*DIM3;n++)
					*(p2++)=*(p1++);
					}
					
					/***** �z��̃`�F�b�N *****/
					for(dim1=0;dim1<DIM1;dim1++)
						for(dim2=0;dim2<DIM2;dim2++)
							for(dim3=0;dim3<DIM3;dim3++)
								if(res[dim1][dim2][dim3] != (UCHAR)((dim1+dim2+dim3)%256))
								{
									printf("�s�������N�����܂����B(%d %d %d)\nPlease EnterKey......",dim1,dim2,dim3);
									exit(1);
								}
								free_uchar3D(org);
								free_uchar3D(res);
}

UCHAR ***malloc_uchar3D(int dim1,int dim2,int dim3)
{
    int i,j;
    UCHAR ***c1,**c2,*c3;
	
    if((c1 = (UCHAR ***)malloc(dim1*sizeof(UCHAR **))) == NULL)
		error1("�������m�ێ��s");
	if((c2 = (UCHAR **)malloc(dim1*dim2*sizeof(UCHAR*))) == NULL)
		error1("�������m�ێ��s");
	if((c3 = (UCHAR *)malloc(dim1*dim2*dim3*sizeof(UCHAR))) == NULL)
		error1("�������m�ێ��s");

	for (j=0;j<dim2*dim1;j++)
		c2[j]=c3+dim3*j;
	for (i=0;i<dim1;i++)
		c1[i]=c2+(dim2*i+j);

	for(i=0;i<dim1;i++)
		for(j=0;j<dim2;j++)
			c1[i][j]=c3+(dim3*i+j)+dim2
    return c1;
}
/*���������*/
void free_uchar3D(UCHAR ***point)
{
	free(point[0][0]);
	free(point[0]);
	free(point);
}
/*�G���[�֐�*/
void error1(char *message)
{
	printf("%s\n",message);
	exit(1);
}

