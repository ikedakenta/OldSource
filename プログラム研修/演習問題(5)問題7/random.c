/*===================================
�����_����������
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "random.h"

/*=======================================
�����_���Ȑ����𐶐�����
�A���d���������l�͐������Ȃ�
---------------------------------------*/
void create_random_num(int size,int *random_num){
	int i=0,j=0;
	int temp_num=0;
	
	srand( (unsigned)time( NULL ) );/*���ݎ������g�������W�F�l���[�^��������*/
	printf("\n�����_�������F");
	
	
	random_num[0] = (rand() % RANDOM_MAX) + 1;
	   for(i=1;i<size;i++){/*�����_���ȃ��X�g�𐶐�����*/
		   temp_num = (rand() % RANDOM_MAX) + 1;/*1�`RANDOM_MAX�̃����_���Ȑ��l�𐶐�*/
		   for(j=0;j<i;j++){
			   if(random_num[j] == temp_num){/*�d�����鐔�l�����ɔz����ɑ��݂��Ă������蒼��*/
				   i--;
				   break;
			   }
		   }
		   if(i == j){/* �Ō�܂ŏd�����Ȃ������� */
				random_num[i] = temp_num;
				printf("%d, ",random_num[i]);
		   }
	   }
}
