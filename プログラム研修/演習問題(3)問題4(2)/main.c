/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�R�j���S�i�Q�j
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "main.h"
#include "list.h"
#include "hash.h"
#include "random.h"

int main(void){
	
	LIST hash_table[HASH_SIZE];
	
	/*�n�b�V���e�[�u����������*/
	init_hashtable(hash_table);
	
	/*�����_���Ȑ�����𐶐�����*/
	create_random_num(LIST_MAX,random_num);
	
	/*�n�b�V���\�ɓo�^����*/
	for(i=0;i<LIST_MAX;i++){
		insert_hashtable(hash_table,random_num[i]);
	}
	
	while(1){
		/*���݂̃n�b�V���\��\��*/
		view_hashtable(hash_table);

		/*�o�^����*/
		printf("\n�������鐔�l����͂��ĉ������B(q �Ńv���O�����I�����܂��B)\n-->");
		gets(char_temp);/*�������͎�t*/
		if(strcmp("q",char_temp) == 0){
			printf("�I�����܂��B\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/
		
		/*�n�b�V���\���琔�l������*/
		if(search_hashtable(hash_table,num_temp) == TRUE){
			printf("�� %d�͑��݂��܂��B\n",num_temp);
		}else{
			printf("�~ %d�͑��݂��܂���B\n",num_temp);
		}
		
	}
	return(0);
}

