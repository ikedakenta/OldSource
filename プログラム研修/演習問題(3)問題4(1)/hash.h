/*===================================
�w�b�_���
�n�b�V���@
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include "list.h"

#define HASH_SIZE 13 /*�n�b�V���e�[�u���̑傫��*/

/*�v���g�^�C�v*/
int hash_calc(int val);
void insert_hashtable(LIST *hash_table,int val);
void view_hashtable(LIST *hash_table);
void init_hashtable(LIST *hash_table);
