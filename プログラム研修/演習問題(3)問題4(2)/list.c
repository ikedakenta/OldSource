/*===================================
���X�g�Ǘ�
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "list.h"

/*=======================================
�f�[�^�����X�g�ɒǉ�����
---------------------------------------*/
void insert_list(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;
	wp = start;
	/*���X�g�̍Ō���Ɉړ�*/
	for(wp = start;wp->next != NULL;wp = wp->next){;}
	/*���X�g�Ō���Ƀf�[�^��ǉ�*/
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	wkdata->next = NULL;
	wp->next = wkdata;
}

/*========================================
���X�g�\��
----------------------------------------*/
void view_list(LIST *start){
	LIST *wp;
	/*���X�g��\��*/
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d �� ",wp->num);
	}
}


/*========================================
���X�g���琔�l����������
�Ԃ�l�F���������ꍇ�ɐ^��Ԃ�
----------------------------------------*/
int search_list(LIST *start,int val){
	LIST *wp;
		for(wp = start;wp != NULL;wp = wp->next){
			if(wp->num == val){
				return TRUE;
			}
	}
		return FALSE;
}