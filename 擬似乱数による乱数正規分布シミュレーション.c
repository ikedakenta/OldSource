/*
�v���O���~���O���K�ۑ�11
�J�����@Windows XP   Microsoft VisualC++6.0
		  Cygwin GNU C++
							P00011	�r�c�@����
----------------------------------------------------
���̃v���O�����ł͔��������闐���͈̔͂��w��ł�
���z�I�Ȑ��K���z�Ɣ�ׂċ[�������ł͂ǂ̒��x���_�l�Ƃ���邩�𑪒肷����̂ł���B

�v���O�����̎g����
�R�}���h���C���Ŏ��s����ۂɎ��̈�����^���Ă�邱�Ƃł����Ɏ��s�ł���B
*.exe ���ρ@�W���΍��@����������[�������̑����@�����̎�
��Fransuu.exe 0.0 1.0 100000 1

�R�}���h���C�����������^�����ɋN�������ꍇ�͊e�ݒ荀�ڒl���ォ����͂���B
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/
#include <ctype.h>/*��������*/
#include <math.h>/*���w�v�Z*/

/*���s������������悤��*/
int main(int argc,char *argv[])
{
	double heikin;          /* ���� */
	double hensa;           /* �W���΍� */
	long num_ransuu;        /* ����������^�������̑��� */
	unsigned int ranseed;   /* �����̎� */
	double riron1=0,riron2=0,riron3=0;/*���_�l�̌v�Z�Ɏg��*/
	int j;
#ifdef METHOD_A
	double x1,x2,y1,y2;/*�{�b�N�X�E�}���[�@�ɂĎg�p*/
#endif
#ifdef METHOD_B
	double b_ransuu;/*��l�������ϖ@�ɂĎg�p*/
	int i;/*for���ȂǂŎg�p����*/
#endif
	/***** �R�}���h���C������̃p�����[�^��� *****/
	if(argc >= 5)/*�p�����[�^��5�ȏ�̏ꍇ*/
	{
		heikin=atof(argv[argc-4]);        /* ���� */
		hensa=atof(argv[argc-3]);         /* �W���΍� */
		num_ransuu=atoi(argv[argc-2]);    /* ����������^�������̑��� */
		ranseed=atoi(argv[argc-1]);       /* �����̎� */
		if(num_ransuu <= 0)/*����������[�������̑����̐ݒ肪���������ꍇ*/
		{
			printf("����������[�������̑�����1�ȏ�ɂ��Ă��������B\n");
			exit(1);/*�ُ�I��*/
		}
		if(hensa <= 0.0)/*�W���΍��̐������������ꍇ*/
		{
			printf("�W���΍�0�ȏ�ɂ��Ă��������B\n");
			exit(1);/*�ُ�I��*/
		}
	}
	else/*�R�}���h���C������̓��͂��s�\���������ꍇ*/
	{
		printf("���̏��ԂŊe�ݒ荀�ڂ����߂Ă�������\n���ρ@�W���΍��@����������[�������̑����@�����̎��\n");
		scanf("%lf %lf %d %d",&heikin,&hensa,&num_ransuu,&ranseed);
	}
	
	printf("����=%g �W���΍�=%g �����̑���=%d\n�v�Z��............\n",heikin,hensa,num_ransuu);
	
	srand(ranseed);/* �����̎��ݒ�(�l�������Ȃ瓯�������n��ƂȂ�) */
	/* �����𐶐������Ȃ���f�[�^�̊������Z�o */    
	for(j=0;j<num_ransuu;j++){

#ifdef METHOD_A  /* �{�b�N�X�E�}���[�@ */
		x1=((double)rand()+1)/RAND_MAX;
		x2=((double)rand()+1)/RAND_MAX;
		y1=cos( (360*x2*3.14159265358979) /180.0)*sqrt((-2)*log(x1));

		/*�����ł�y1��������Α���͂ł���̂�y2�͌v�Z���珜�O����*/
		/*y2=sin( (360*x2*3.14159265358979) /180.0)*sqrt((-2)*log(x1));*/
		if(y1<=hensa   && y1>=-hensa  )riron1+=1;
		if(y1<=hensa*2 && y1>=-hensa*2)riron2+=1;
		if(y1<=hensa*3 && y1>=-hensa*3)riron3+=1;
#endif
		
#ifdef METHOD_B  /* ��l�������� */
		b_ransuu=0;
		for(i=0;i<12;i++){/*0�ȏ�1�ȉ��̈�l������12���Z*/
			b_ransuu+=((double)rand()/RAND_MAX);/*double�^�ɃL���X�g����K�v����*/
		}
		b_ransuu-=6;/*��������6����*/

		/*���K���z�̊������v�Z���邽�߂̕z��*/
		if(b_ransuu<=hensa&&b_ransuu>=-hensa)riron1+=1;
		if(b_ransuu<=hensa*2&&b_ransuu>=-hensa*2)riron2+=1;
		if(b_ransuu<=hensa*3&&b_ransuu>=-hensa*3)riron3+=1;
#endif

	}
	/*�����v�Z�y�ь^�̃L���X�g*/
	riron1/=num_ransuu;
	riron2/=num_ransuu;
	riron3/=num_ransuu;
    /* �Z�o���������̕\�� */
	printf("���σʂ���}1�ЁA�}2�ЁA�}3�Г��̃f�[�^���̊���\n"
		"---------------------------------------------------------------\n"
		"�@�@�@�@| �}�P�Ё@�@ �}�Q�Ё@�@ �}�R��\n"
		"�@�@�@�@|% .7f % .7f % .7f\n"
	        "���_�l��|% .7f % .7f % .7f\n",riron1,riron2,riron3,
	       (riron1-0.6827),(riron2-0.9545),(riron3-0.9973));
}
