/*===================================
�n�b�V���@
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "hash.h"

/*========================================
�n�b�V���e�[�u���̏�����
----------------------------------------*/
void init_hashtable(LIST *hash_table){
	int i = 0;
	/* �n�b�V���\�擪��next�|�C���^��NULL�ŏ��������Ă��� */
	for(i = 0;i<HASH_SIZE;i++){
		hash_table[i].next = NULL;
	}
}

/*========================================
�n�b�V���l�����߂�
�@�\�F�f���Ŋ������l��Ԃ�
----------------------------------------*/
int hash_calc(int val){
	int hash_val = 0;
	hash_val = val % HASH_SIZE;/*�n�b�V���T�C�Y�Ŋ������]������߂�*/
	return hash_val;
}

/*========================================
�n�b�V���\�փf�[�^��o�^����
----------------------------------------*/
void insert_hashtable(LIST *hash_table,int val){
	int hash_val = 0;
	hash_val = hash_calc(val);/*�n�b�V���l�����߂�*/

	/*�f�[�^���n�b�V���\�ɓo�^*/
	insert_list(&hash_table[hash_val],val);

}

/*========================================
�n�b�V���\��\������
----------------------------------------*/
void view_hashtable(LIST *hash_table){
	int i = 0;
	for(i = 0;i<HASH_SIZE;i++){
		printf("\n%2d: ",i);
		view_list(&hash_table[i]);
	}	
}

/*========================================
�n�b�V���\���琔�l����������
�Ԃ�l�F���������ꍇ�ɐ^��Ԃ�
----------------------------------------*/
int search_hashtable(LIST *hash_table,int val){
	int hash_val = 0;
	hash_val = hash_calc(val);/*�n�b�V���l�����߂�*/

	return search_list(&hash_table[hash_val],val);

}