/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�R�j
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define RANDOM_LIST_SIZE 10

struct cell{
	int num;		/*�v�f*/
	struct cell* next;	/*���̗v�f�ւ̃|�C���^*/
};
typedef struct cell LIST;


char char_temp[32];		/*��������͂Ƃ��Ď󂯎�邽��*/
int num_temp=0;			/*���l�ꎞ�ۊ�*/
int position=0;
int max_list=0;
int i;
