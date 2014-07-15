/*===================================
２００６年度プログラム研修
演習課題（３）問題４（１）
作成日　４月２６日
作成者　池田　健太
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

	/*ハッシュテーブルを初期化*/
	init_hashtable(&hash_table);

	while(1){
	/*登録処理*/
		printf("\n登録する数値を入力して下さい。(q でプログラム終了します。)\n-->");
		gets(char_temp);/*文字入力受付*/
		if(strcmp("q",char_temp) == 0){
			printf("終了します。\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*文字列→数値変換*/

		/*ハッシュテーブルへ値を挿入*/
		insert_hashtable(hash_table,num_temp);
		/*現在のハッシュ表を表示*/
		view_hashtable(hash_table);

	}
	return(0);
}

