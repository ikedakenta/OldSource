/*
bit�t�B�[���h�̑��x�v���v���O����
�J�����@Windows XP   Microsoft VisualC++6.0
GNU C++
P00011	�r�c�@����
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/
#include <ctype.h>/*��������*/
#include <time.h>/*���ԏ���*/

/*�V�~�����[�V���������*/
#define LOOP 10000
/*�V�~�����[�V�������镑��̑傫��LOOP��SIZE_STARAT�̒l�ɂ���Č��܂�*/
#define SIZE 2000
#define jikan //�f�o�b�O�p���Ԍv��
struct bitset{
	unsigned int test0 : 1;
	unsigned int test1 : 1;
	unsigned int test2 : 1;
	unsigned int test3 : 1;
	unsigned int test4 : 1;
	unsigned int test5 : 1;
	unsigned int test6 : 1;
	unsigned int test7 : 1;
};

int main(void){
	int i,j,l;
	char test[8][SIZE];
	struct bitset data[SIZE];
	
#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	clock_t time1,time2,time3;
	double keika;
	char gomi[10];
#endif ///////////////////////////////////////////////////////////////////////
	
	/*������*///////////////////////////////////////////////////////////
	for (i=0;i<8;i++){
		for(j=0;j<SIZE;j++){
			test[i][j]=0;
		}
	}
	for(i=0;i<SIZE;i++){
		data[i].test0=0;
		data[i].test1=0;
		data[i].test2=0;
		data[i].test3=0;
		data[i].test4=0;
		data[i].test5=0;
		data[i].test6=0;
		data[i].test7=0;
	}
#ifdef jikan
	time1=clock();/*���ԑ���*/
#endif
	/*������샋�[�v*////////////////////////////////////////////////
	for(l=0;l<LOOP;l++){
		for(i=0;i<8;i++){
			for(j=0;j<SIZE;j++){
				test[i][j]=1;
			}
		}
	}
#ifdef jikan
	time2=clock();
#endif
	/*������샋�[�v*////////////////////////////////////////////////
	for(l=0;l<LOOP;l++){
		for(i=0;i<SIZE;i++){
			data[i].test0=1;
			data[i].test1=1;
			data[i].test2=1;
			data[i].test3=1;
			data[i].test4=1;
			data[i].test5=1;
			data[i].test6=1;
			data[i].test7=1;
		}
	}
#ifdef jikan
	time3=clock();
#endif
	
	
#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	keika=time2-time1;
	printf("�ʏ�z��R�s�[���� �@�@�@���v���ԁF%f\n",keika/1000.0);
	keika=time3-time2;
	printf("bit�t�B�[���h�R�s�[�����@���v���ԁF%f\n",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	
	return(0);
}
