/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�R�j���S�i�P�j
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

int main(void){

	LIST hash_table[HASH_SIZE];

	/*�n�b�V���e�[�u����������*/
	init_hashtable(&hash_table);

	while(1){
	/*�o�^����*/
		printf("\n�o�^���鐔�l����͂��ĉ������B(q �Ńv���O�����I�����܂��B)\n-->");
		gets(char_temp);/*�������͎�t*/
		if(strcmp("q",char_temp) == 0){
			printf("�I�����܂��B\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/

		/*�n�b�V���e�[�u���֒l��}��*/
		insert_hashtable(hash_table,num_temp);
		/*���݂̃n�b�V���\��\��*/
		view_hashtable(hash_table);

	}
	return(0);
}

