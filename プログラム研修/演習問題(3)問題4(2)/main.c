/*===================================
２００６年度プログラム研修
演習課題（３）問題４（２）
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
#include "random.h"

int main(void){
	
	LIST hash_table[HASH_SIZE];
	
	/*ハッシュテーブルを初期化*/
	init_hashtable(hash_table);
	
	/*ランダムな整数列を生成する*/
	create_random_num(LIST_MAX,random_num);
	
	/*ハッシュ表に登録する*/
	for(i=0;i<LIST_MAX;i++){
		insert_hashtable(hash_table,random_num[i]);
	}
	
	while(1){
		/*現在のハッシュ表を表示*/
		view_hashtable(hash_table);

		/*登録処理*/
		printf("\n検索する数値を入力して下さい。(q でプログラム終了します。)\n-->");
		gets(char_temp);/*文字入力受付*/
		if(strcmp("q",char_temp) == 0){
			printf("終了します。\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*文字列→数値変換*/
		
		/*ハッシュ表から数値を検索*/
		if(search_hashtable(hash_table,num_temp) == TRUE){
			printf("○ %dは存在します。\n",num_temp);
		}else{
			printf("× %dは存在しません。\n",num_temp);
		}
		
	}
	return(0);
}

