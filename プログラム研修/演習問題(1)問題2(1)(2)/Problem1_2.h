/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�P�j�i�Q�j
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct cell{
	int num;		/*�v�f*/
	struct cell *next;	/*���̗v�f�ւ̃|�C���^*/
};
typedef struct cell LIST;


char char_temp[32];		/*��������͂Ƃ��Ď󂯎�邽��*/
int num_temp;			/*���l�ꎞ�ۊ�*/