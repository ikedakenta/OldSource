/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�Q�j���R�i�P�j�i�Q�j�i�R�j�i�S�j�i�T�j
�쐬���@�S���Q�T��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "Problem2_1.h"
#include "tree.h"

int main(void)
{
	TREE *root = NULL;
	/*�����_���Ȑ�����𐶐�����*/
	create_random_num(LIST_MAX,random_num);
	
	for(i=0;i<LIST_MAX;i++){
		insert(&root,random_num[i]);/*�m�[�h�ɒǉ�����*/
		//print_tree(root);
		//getch();
	}

	/*�c���[�\��*/
	printf("\n=========== �����\�� =============\n");
	print_tree(root);
	
	printf("\n=========== �K�w�\�� =============\n");
	view_tree(root);
	
	while(1){
		/*��������*/
		printf("\n�c���[���猟�����鐔�l����͂��ĉ������B(q �Ńv���O�����I�����܂��B)\n-->");
		gets(char_temp);/*�������͎�t*/
		if(strcmp("q",char_temp) == 0){
			printf("�I�����܂��B\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/
		
		/*�ړI�̐��l���c���[����T��*/
		if(search(root,num_temp) != NULL){
			printf("�� %d�̓c���[�ɑ��݂��܂��B",num_temp);/*���ʕ\��*/
		}else{
			printf("�~ %d�̓c���[�ɑ��݂��܂���B",num_temp);
		};
	}
	return (0);
}

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
