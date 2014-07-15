/*===================================
ハッシュ法
作成日　４月２６日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "hash.h"

/*========================================
ハッシュテーブルの初期化
----------------------------------------*/
void init_hashtable(LIST *hash_table){
	int i = 0;
	/* ハッシュ表先頭のnextポインタをNULLで初期化しておく */
	for(i = 0;i<HASH_SIZE;i++){
		hash_table[i].next = NULL;
	}
}

/*========================================
ハッシュ値を求める
機能：素数で割った値を返す
----------------------------------------*/
int hash_calc(int val){
	int hash_val = 0;
	hash_val = val % HASH_SIZE;/*ハッシュサイズで割った余りを求める*/
	return hash_val;
}

/*========================================
ハッシュ表へデータを登録する
----------------------------------------*/
void insert_hashtable(LIST *hash_table,int val){
	int hash_val = 0;
	hash_val = hash_calc(val);/*ハッシュ値を求める*/

	/*データをハッシュ表に登録*/
	insert_list(&hash_table[hash_val],val);

}

/*========================================
ハッシュ表を表示する
----------------------------------------*/
void view_hashtable(LIST *hash_table){
	int i = 0;
	for(i = 0;i<HASH_SIZE;i++){
		printf("\n%2d: ",i);
		view_list(&hash_table[i]);
	}	
}

/*========================================
ハッシュ表から数値を検索する
返り値：見つかった場合に真を返す
----------------------------------------*/
int search_hashtable(LIST *hash_table,int val){
	int hash_val = 0;
	hash_val = hash_calc(val);/*ハッシュ値を求める*/

	return search_list(&hash_table[hash_val],val);

}