/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�S�j
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define LIST_MAX 20

struct cell{
	int num;		/*�v�f*/
	struct cell* next;	/*���̗v�f�ւ̃|�C���^*/
};
typedef struct cell LIST;

void insert(LIST *start,int val);
void view_list(LIST *start,int no);
void create_random_num(int size,int *random_num);

char char_temp[32];		/*��������͂Ƃ��Ď󂯎�邽��*/
int num_temp=0;			/*���l�ꎞ�ۊ�*/
int random_num[LIST_MAX];
int i=0,no=0;

