/*
�v���O���~���O���K�ۑ�10
���C�t�Q�[���u���r�E�X�̗ցv�d�l
�J�����@Windows XP   Microsoft VisualC++6.0
P00011	�r�c�@����
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/

/*�V�~�����[�V����������ԁA������ڂ܂ŃV�~�����[�g���邩�w��*/
#define LOOP 115
#define SIZE 30/*�Ֆʂ̃T�C�Y*/
//#define gamen //�f�o�b�O�p��ʏo��

/*�v���g�^�C�v�錾*/
void init(void);
void next(void);
void write(void);

/*�O���[�o���ϐ��錾*/
char pat[SIZE+2][SIZE+2];/*�������z��ɂ��Ֆʊm��*/
char prepat[SIZE+2][SIZE+2];

int main(void){
	char gomi[10];
	init();/*�z�񏉊�������*/
	printf("�V�~�����[�V�������J�n���܂��B\n........�V�~�����[�V������\n");
	next();/*����V�~�����[�V����*/
	printf("�V�~�����[�V�������I�����܂����B\n");
	write();/*�t�@�C���ւ̏����o��*/
	printf("\n���ʂ��ulife.txt�v�֏������݂܂���\n");
	gets(gomi);
	return(0);
}


void init()/*������*/
{
	int i,j;
	i=5;/*��ԉE���̗v�f��y���W*/
	j=5;/*��ԉE���̗v�f��x���W*/
	
	prepat[i][j]		=1;
	prepat[i][j-1]		=1;
	prepat[i][j-2]		=1;
	prepat[i][j-3]		=1;
	prepat[i-1][j]		=1;
	prepat[i-2][j]		=1;
	prepat[i-3][j-1]	=1;
	prepat[i-1][j-4]	=1;
	
}

/*����V�~�����[�g*/
void next(){
	
	int i,j,l,count;
	
	for(l=0;l<LOOP;l++){/*#define LOOP�Ŏw�肵���񐔂�������V�~�����[�V����*/
		
		/*�[��������]���Ɏ���Ă������̂ł����𗘗p���ă��r�E�X�̗ւ���������*/
		for(i=1;i<SIZE;i++){/*�㉺�˂����Đڑ�*/
			prepat[i][SIZE+1]=prepat[SIZE+1-i][1];
			prepat[i][0]=prepat[SIZE+1-i][SIZE];
		}
		for(j=1;j<SIZE;j++){/*�P���ɏ㉺���Ȃ�*/
			prepat[SIZE+1][j]=prepat[1][j];
			prepat[0][j]=prepat[SIZE][j];
		}
		
		/*�����㔻�蕔��*/
		for(i=1;i<SIZE+1;i++){
			for(j=1;j<SIZE+1;j++){
			/*�t���O�𒲂׎��g�̎���ɉ������Ă���ڂ����邩�T��
				���݂̖ڂ��[�����̏ꍇ�A���r�E�X�̗ւɂȂ�悤�ɔ��肷�镔�����㉺�˂���*/
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
		for(i=0;i<SIZE+2;i++){
			for(j=0;j<SIZE+2;j++){
				prepat[i][j]=pat[i][j];
			}/*�V��������֍X�V����*/
		}
	}
}

/*�t�@�C���ւ̏�������*/
void write(void){
	
	FILE *fp;
	int i,j;
	fp=fopen("life.txt","w");
	for(i=1;i<SIZE;i++){
		for(j=1;j<SIZE;j++){
			if(prepat[i][j]==1)fprintf(fp,"��");/*�����Ă����*/
			else fprintf(fp,"�@");/*����ł���ڂ͋󔒂ŉ����\�����Ȃ�*/
		}
		fprintf(fp,"\n");/*��s���Ƃɉ��s*/
	}
	fclose(fp);
	
#ifdef gamen//�f�o�b�O�p��ʏo��////////////////////////////////////////////
	for(i=0;i<SIZE+1;i++){
		for(j=0;j<SIZE+1;j++){
			if(prepat[i][j]==1)printf("��");/*�����Ă����*/
			else printf("�@");/*����ł���ڂ͋󔒂ŉ����\�����Ȃ�*/
		}
		printf("\n");/*��s���Ƃɉ��s*/
	}
#endif///////////////////////////////////////////////////////////////////////
	
}