/*===================================
ヘッダ情報
ハッシュ法
作成日　４月２６日
作成者　池田　健太
------------------------------------*/
#include "list.h"

#define HASH_SIZE 13 /*ハッシュテーブルの大きさ*/
#ifndef TRUE
#define TRUE 1
#define FALSE -1
#endif

/*プロトタイプ*/
int hash_calc(int val);
void insert_hashtable(LIST *hash_table,int val);
void view_hashtable(LIST *hash_table);
void init_hashtable(LIST *hash_table);
int search_hashtable(LIST *hash_table,int val);