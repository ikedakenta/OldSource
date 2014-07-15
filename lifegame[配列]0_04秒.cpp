/*
���C�t�Q�[��
�J�����@Windows XP   Microsoft VisualC++6.0
          Vine Linux   GCC
		�����ɂ����ē���m�F�ς�
								P00011	�r�c�@����
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/
#include <ctype.h>/*��������*/
#include <time.h>/*���ԏ���*/

/*����������`�̑傫��*/
#define SIZE_START 5
/*�V�~�����[�V����������ԁA������ڂ܂ŃV�~�����[�g���邩�w��*/
#define LOOP 100
/*�V�~�����[�V�������镑��̑傫��LOOP��SIZE_STARAT�̒l�ɂ���Č��܂�*/
#define SIZE (2*LOOP+2*SIZE_START)

#define jikan //�f�o�b�O
/*�v���g�^�C�v�錾*/
void init(void);
void next(void);
void write(void);

/*�O���[�o���ϐ��錾*/
char pat[SIZE][SIZE];/*�������z��ɂ��Ֆʊm��*/
char prepat[SIZE][SIZE];

int main(void){
#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	clock_t time1,time2;
	double keika;
	char gomi[10];
#endif ///////////////////////////////////////////////////////////////////////

	time1=clock();
	init();/*�z�񏉊�������*/
	printf("�V�~�����[�V�������J�n���܂��B\n........�V�~�����[�V������\n���΂炭���҂����������B\n");
	next();/*����V�~�����[�V����*/
	printf("�V�~�����[�V�������I�����܂����B\n���ʂ��t�@�C���ɏ�������ł��܂��B\n");
	write();/*�t�@�C���ւ̏����o��*/
	printf("\n�������݂��I�����܂����B\n���ʂ́ulife.txt�v�ɏo�͂��܂���\n");
	#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	time2=clock();
	keika=time2-time1;
	printf("���v���ԁF%f",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	return(0);
}


void init()/*������*/
{
	int i,j;
	i=j=SIZE/2;/*i��^�񒆂ɂ���*/
	/*�y���g�I�~�m�Ƃ��ď�����*/
	prepat[i][j]		=1;
	prepat[i-1][j]		=1;
	prepat[i][j-1]		=1;
	prepat[i+1][j]		=1;
	prepat[i-1][j+1]	=1;
}

/*����V�~�����[�g*/
void next(){
	
	int i,j,m,n,l,count;
	/*�Ֆʂ̒��S�A�������F�߂���\��������͈͂��w�肷��*/
	m=SIZE/2-SIZE_START;
	n=SIZE/2+SIZE_START;
	
	for(l=0;l<LOOP;l++){/*#define LOOP�Ŏw�肵���񐔂�������V�~�����[�V����*/
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
				/*�t���O�𒲂׎��g�̎���ɉ������Ă���ڂ����邩�T��*/
				count=0;/*���񏉊���*/
				count=prepat[i-1][j-1]+prepat[i][j-1]
					+prepat[i+1][j-1]+prepat[i-1][j]+prepat[i+1][j]
					+prepat[i-1][j+1]+prepat[i][j+1]+prepat[i+1][j+1];
				/* ���ړ_��0�̏ꍇ�A�������͂̓_���R�_����Β��ړ_�͂P�ɂȂ� */
				/* �����ł͂Ȃ��Ē��ړ_��1�̏ꍇ�A�������͂̓_��4�_�ȏ゠�邢�� */
				/* 2�_��菭�Ȃ���΁A�ߖ����邢�͉ߑa�ɂ�蒍�ړ_��0�ɂȂ� */
				if(prepat[i][j]==0){/*���g������ł���Ƃ�*/
					if(count==3){
						pat[i][j]=1;/*����ɐ����Ă���ڂ�3����Ύ��g��������*/
					}
				}
				else if(prepat[i][j]==1){/*���g�������Ă���Ƃ�*/
					if(count!=2 && count!=3){
						pat[i][j]=0;/*����ɐ����Ă���ڂ�4�ȏ��������2�����̏ꍇ�A���g�͎���*/
					}
					else{
						pat[i][j]=1;
					}
				}
			}
		}
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
			/*�͈͂����߂ĕK�v�ȕ��������R�s�[���Ă���̂�
			�A�h���X����ӂɕ���ł��Ȃ��B
				���̂��߃|�C���^���g���Ȃ��̂ŕ��ʂɔz��̗v�f�����X�ɃR�s�[*/
				prepat[i][j]=pat[i][j];
			}/*�V��������֍X�V����*/
		}
		m--;/*����͈͂��L����*/
		n++;
	}
}

/*�t�@�C���ւ̏�������*/
void write(void){
	
	FILE *fp;
	int i,j,m,n;
	/*�t�@�C��������V�~�����[�V�����̎��Ɠ����悤��
	�V�~�����[�V�������ʂ��m�F�ł���̂�
	�K�v�\���Ȃ����͈̔͂��w�肵�ď�������B*/
	m=SIZE/2-SIZE_START-LOOP;
	n=SIZE/2+SIZE_START+LOOP;
	
	fp=fopen("life.txt","w");
	for(i=m;i<n;i++){
		fprintf(fp,"\n");/*��s���Ƃɉ��s*/
		for(j=m;j<n;j++){
			if(prepat[i][j]==1)fprintf(fp,"+");/*�����Ă����*/
			else fprintf(fp," ");/*����ł���ڂ͋󔒂ŉ����\�����Ȃ�*/
		}
	}
	fclose(fp);
}