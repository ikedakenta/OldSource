/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���P
�쐬���@�S���Q�O��
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include "Problem1.h"
void calc_bin(int num);
void error(int no);

int main(void){
	char *p;/*�����񑖍��p*/
	p = char_temp;
	printf("���l����͂��ĉ������B\n-->");
	gets(char_temp);/*������Ƃ��ē��͎�t*/	
	
	/* ������Ȃ�G���[ */
	while(*p != NULL){
		if(isalpha((*p)))
		{
			error(2);
		}
		p++;
	}
	
	/*�����񁨐��l�ϊ�*/
	num_temp	=	atoi(char_temp);
	
	/*���l�ł��ُ�l�̓��͂̓G���[*/
	if(num_temp > 65535 || num_temp < 0){
		error(1);
		return(0);
	}
	
	/*���ʕ\��*/
	printf("���͂��ꂽ���l%d�͂Q�i���Ŏ��̂悤�ɂȂ�܂��B\n",num_temp);
	calc_bin(num_temp);/*�Q�i���v�Z*/
	
	printf("\n�����L�[�������ƃv���O�������I�����܂��B\n");
	gets(char_temp);
	return(0);
}

/*====================================
�Q�i���ϊ��֐�
------------------------------------*/
void calc_bin(int num){
	int i,count=0;
	int int_temp[16];
	
	for(i=0;i<16;i++){/*0�Ŗ��߂�*/
		int_temp[i]  =  0;
	}
	
	for(i=0;i<16;i++){/*�Q���Z�ɂ��ϊ����*/
		int_temp[i]	=	(num % 2);
		num = num / 2;
		count++;
		if((num / 2) == 0){/*�Ō�̌��܂Ōv�Z���i�݂���ȏ㊄��Ȃ��Ȃ�����*/
			continue;/*continue���鎖�Ł@�v�Z���I����Ă����0�����Ă���*/
		}
	}
	
	for(i=count-1;i >= 0;i--){/*���ʂ̕\��*/
		printf("%d",int_temp[i]);
	}
}
/*====================================
�G���[�\��
------------------------------------*/
void error(int error_ID){
	switch (error_ID){
	case 1:
		printf("�G���[�F�͈͊O�̐��l�����͂���܂����B\n���͂͂O�`65535�̐��l�ɂ��ĉ������B");
		exit(1);
	case 2:
		printf("�G���[�F�����񂪓��͂���܂����B");
		exit(1);
	default:
		exit(1);
	}
}