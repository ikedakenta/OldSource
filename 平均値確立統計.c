/*    �v���O���~���O���K�@��12��
[�f�[�^�̕��ϒl�̐M����]
�g�p��:a.out ���� �W���΍� �����̑��� �����̎� 
�J�����@Windows XP   Microsoft VisualC++6.0
Cygwin GNU C++
P00011	�r�c�@����
----------------------------------------------------
*/
#include <stdio.h>/*�W��*/
#include <stdlib.h>/*�W��*/
#include <string.h>/*�����񏈗�*/
#include <math.h>/*���w�v�Z����*/

int main(int argc,char *argv[])
{
	FILE *fp;
	double heikin,heikin_sum=0,sample_heikin=0,heikin_temp=0,sample_heikin_heikin;          /* ���� */
	double hensa,sample_hensa=0;           /* �W���΍� */
	long num_ransuu;        /* ����������^�������̑��� */
	unsigned int ranseed;   /* �����̎� */
	char gomi[10];//�f�o�b�O�p�ϐ�
	
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
	{
		int hist[3]={0,0,0};  /* �������Z�o���邽�߂̃J�E���^ */
		double ran1,ran2;     /* ���� */
		int i,m;
		double pai2=8.0*atan(1.0);  /* 2�� */
		double x1,x2,a,b,c=0;
		
		
		fp=fopen("data.txt","w");/*�t�@�C����������*/
		heikin_sum=0;/*�T���v�����ς��O�ɏ�����*/
		for(m=1;m<10000;m++){
			a=0,b=0,c=0,ran1=0,heikin_sum=0,sample_heikin=0,heikin_temp=0;
			num_ransuu=(m/2)*2; /* METHOD_A�̏ꍇ�͗��������������ɕύX */
			for(i=1;i<=num_ransuu;i++)
			{
				x1=((double)rand()+1.0)/((double)(RAND_MAX)+1.0);
				x2=((double)rand()+1.0)/((double)(RAND_MAX)+1.0);
				a=pai2*x2;
				b=sqrt(-2.0*log(x1));
				ran1=sin(a)*b*hensa+heikin;    /* ����1 */
				/*���ς̌v�Z*******************************************************/
				heikin_sum=heikin_sum+ran1;
				sample_heikin=heikin_sum/i;
				heikin_temp+=sample_heikin;
				/*�T���v�����ς̕��ςƕW���΍��̌v�Z*****************************************/
				c+=((ran1-sample_heikin)*(ran1-sample_heikin));
			}
			
			if(c<0){
				c=-c;
			}
			c/=i;
			sample_heikin_heikin=heikin_temp/num_ransuu;
			sample_hensa=sqrt(c);
			
			/* �Z�o���������̕\�� */
				fprintf(fp,"%d % 7.5f %7.5f %7.5f\n",m,sample_heikin_heikin,sample_hensa,(sample_hensa-((double)(5/(sqrt(m))))));
	if((m%1000)==0){
		printf("%d % 7.5f %7.5f %7.5f\n",m,sample_heikin_heikin,sample_hensa,(sample_hensa-((double)(5/(sqrt(m))))));
	}
		}
	}
	printf("�T���v�����ς̕���:%7.5f\n�T���v�����ς̕W���΍�:%7.5f\n��Please Enter anykey",sample_heikin,sample_hensa);
	gets(gomi);
	gets(gomi);//���͑҂��ɂ���B
	fclose(fp);
}