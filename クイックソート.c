/*	-------------�v���O���~���O���K�U�ۑ� 4-----------
�J����	Windows2000	MicrosoftVisualC++6.0	�r�c�@����	*/
#include <stdio.h>/*�W���w�b�_*/
#include <stdlib.h>/**/
#include <string.h>/**/
#define DATA 5000/*�����f�[�^�̑傫��*/
#define TXT "data.txt" /*�ǂݍ��ސ���t�@�C���̏ꏊ*/

int *intsort(int a[],int n0,int nn);
void swap(int *pa,int*pb);

void main(void){
		  /*---------------------------------�ϐ���`---------------------------------------------*/
				int i,j,data[DATA];
				char gomi[10];/*gets(f)�̂Ƃ��Ɏg�������̃S�~�ϐ�*/
				FILE *fp;/*�t�@�C�����o�͑���p�|�C���^*/
				/*---------------------------�t�@�C���ǂݍ���----------------------------------------*/
				printf("�uTXT�v���琔���ǂݍ��݂܂�\n");
				fp=fopen(TXT,"r");
				i=0;
				for (;;){
					if(fscanf(fp,"%d",&data[i])==EOF)break;/*�t�@�C�������s�ǂ��data[]�ɓ����A�t�@�C���̏I����break*/
					i++;
				}
				fclose(fp);
				/*[Quiksort]�Ăяo��*/
				intsort(data,0,DATA-1);
				/*-------------------------------------���ʂ̃f�B�X�v���C�ւ̏o��--------------------------------------*/
				for (i=0;i<=DATA-1;i++){
					printf("%d ",data[i]);
				}
				/*------------------------�o�͌��ʂ��t�@�C���փG�N�X�|�[�g---------------------------*/
				fp=fopen("kekka.txt","w");
				for(i=0;i<=DATA-1;i++){
					fprintf(fp,"%d\n",data[i]);
				}
				fclose(fp);
				printf("[QuikSort] �ɂ�萔�����ёւ������ʂ�\n�ukekka.txt�v�ɏo�͂��܂����B\n");
}
/*------------------------------------Quicksort�v���O����-------------------------------------*/
int *intsort(int a[],int n0,int nn)
{
				int t;
				int i,j;
				if(nn-n0==1){/*��ׂ�z��v�f���ׂ̂Ƃ�*/
					if(a[n0]<a[nn])swap(&a[n0],&a[nn]);
				}
				else if(nn-n0>1){/*��ׂ�z��v�f���܂�����Ă��鎞*/
					t=a[(n0+nn)/2];
					i=n0-1;
					j=nn+1;
					while(i<j){
						while(a[++i]>t);
						while(a[--j]<t);
						if(i<j)swap(&a[i],&a[j]);
						else if(i==j){
							intsort(a,n0,i-1);
							intsort(a,i+1,nn);
						}
						else{
							intsort(a,n0,j);
							intsort(a,i,nn);
						}
					}
				}
				return a;
}
/*-------------�f�[�^�̌��������̃v���O����---------------------------*/
void swap(int *pa,int *pb){
				int temp;
				temp=*pa;
				*pa=*pb;
				*pb=temp;
}
