/*
���C�t�Q�[��
�J�����@Windows XP   Microsoft VisualC++6.0
VineLinux    GNU C++
�����œ���m�F�ς�
�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@P00011	�r�c�@����
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/
#include <ctype.h>
#include <time.h>

/*�V�~�����[�V����������ԁA������ڂ܂ŃV�~�����[�g���邩�w��*/
#define LOOP 100
/*����������`�̑傫��*/
#define SIZE_START 5
/*�V�~�����[�V�������镑��̑傫��LOOP��SIZE_STARAT�̒l�ɂ���Č��܂�*/
#define SIZE_MATRIX (2*LOOP+2*SIZE_START)
#define jikan        /*�f�o�b�O�p�Ɏ��ԑ��肷��ꍇ*/

/*�v���g�^�C�v�錾*/
char **malloc_2d();
void ini(char **,char **);
void next(char **,char **);
void write(char **);
void free_2d(char **);
char main(void){
		
#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	clock_t time1,time2;
	double keika=0;
	char gomi[10];
	time1=clock();
#endif ///////////////////////////////////////////////////////////////////////
	char **pat,**prepat;
	/*�������m��*/
	prepat=malloc_2d();
	pat=malloc_2d();
	ini(prepat,pat);/*������*/
	printf("�V�~�����[�V�������J�n���܂��B\n........�V�~�����[�V������\n");
	next(prepat,pat);/*�V�~�����[�V�����֐�*/
	write(prepat);/*���ʂ��t�@�C���֏o��*/
	/*�����������*/
	free_2d(pat);
	free_2d(prepat);
	
#ifdef jikan /*�f�o�b�O�p���ԑ���*/////////////////////////////////////////////
	time2=clock();
	keika=time2-time1;
	printf("���v���ԁF%f",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	return(0);
}


/*�������m��*/
char **malloc_2d(){
	int i;
	char **p1,*p2;
	
	if((p1=(char **)malloc(SIZE_MATRIX*sizeof(char *)))==NULL){
		printf("�������m�ێ��s\n");
		exit(-1);
	}
	if((p2=(char *)malloc(SIZE_MATRIX*SIZE_MATRIX*sizeof(char)))==NULL){
		printf("�������m�ێ��s\n");
		exit(-1);
	}
	for(i=0;i<SIZE_MATRIX;i++)
		p1[i]=p2+SIZE_MATRIX*i;
	return p1;
}

/*�������֐�*/
void ini(char **prepat,char **pat){
	int i,j,m;
	char *p1,*p2;
	i=j=SIZE_MATRIX/2;/*i��^�񒆂ɂ���*/
	p1=&prepat[0][0];
	p2=&pat[0][0];
	for(m=0;m<SIZE_MATRIX*SIZE_MATRIX;m++){
			*(p1++)=*(p2++)=0;
	}
	/*�y���g�I�~�m�Ƃ��ď�����*/
	prepat[i][j]		=1;
	prepat[i-1][j]		=1;
	prepat[i][j-1]		=1;
	prepat[i+1][j]		=1;
	prepat[i-1][j+1]	=1;
}

void next(char **prepat,char **pat){
	
	int i,j,m,n,l,count;
	/*�Ֆʂ̒��S�A�������F�߂���\��������͈͂��w�肷��*/
	m=SIZE_MATRIX/2-SIZE_START;
	n=SIZE_MATRIX/2+SIZE_START;
	
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

/*�t�@�C���������݊֐�*/
void write(char **prepat){
	
	FILE *fp;
	int i,j,m,n;
	/*�t�@�C��������V�~�����[�V�����̎��Ɠ����悤��
	�V�~�����[�V�������ʂ��m�F�ł���̂�
	�K�v�\���Ȃ����͈̔͂��w�肵�ď�������B*/
	m=SIZE_MATRIX/2-SIZE_START-LOOP;
	n=SIZE_MATRIX/2+SIZE_START+LOOP;
	
	printf("�V�~�����[�V�������I�����܂����B\n");
	fp=fopen("life.txt","w");
	for(i=m;i<n;i++){
		fprintf(fp,"\n");/*��s���Ƃɉ��s*/
#ifdef gamen
		printf("\n");
#endif
		for(j=m;j<n;j++){
			if(prepat[i][j]==1)fprintf(fp,"+");/*�����Ă����*/
			else fprintf(fp," ");/*����ł���ڂ͋󔒂ŉ����\�����Ȃ�*/
		}
	}
	fclose(fp);
	printf("\n���ʂ��ulife.txt�v�֏������݂܂����B\n");
}

/*���������*/
void free_2d(char **point){
	free(point[0]);
	free(point);
}
