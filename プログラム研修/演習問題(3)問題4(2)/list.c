/*===================================
リスト管理
作成日　４月２６日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "list.h"

/*=======================================
データをリストに追加する
---------------------------------------*/
void insert_list(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;
	wp = start;
	/*リストの最後尾に移動*/
	for(wp = start;wp->next != NULL;wp = wp->next){;}
	/*リスト最後尾にデータを追加*/
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	wkdata->next = NULL;
	wp->next = wkdata;
}

/*========================================
リスト表示
----------------------------------------*/
void view_list(LIST *start){
	LIST *wp;
	/*リストを表示*/
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d → ",wp->num);
	}
}


/*========================================
リストから数値を検索する
返り値：見つかった場合に真を返す
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