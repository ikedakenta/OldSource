/*===================================
２００６年度プログラム研修
演習課題（２）問題３（１）（２）（３）（４）（５）
作成日　４月２５日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "Problem2_1.h"
#include "tree.h"

int main(void)
{
	TREE *root = NULL;
	/*ランダムな整数列を生成する*/
	create_random_num(LIST_MAX,random_num);
	
	for(i=0;i<LIST_MAX;i++){
		insert(&root,random_num[i]);/*ノードに追加する*/
		//print_tree(root);
		//getch();
	}

	/*ツリー表示*/
	printf("\n=========== 昇順表示 =============\n");
	print_tree(root);
	
	printf("\n=========== 階層表示 =============\n");
	view_tree(root);
	
	while(1){
		/*検索処理*/
		printf("\nツリーから検索する数値を入力して下さい。(q でプログラム終了します。)\n-->");
		gets(char_temp);/*文字入力受付*/
		if(strcmp("q",char_temp) == 0){
			printf("終了します。\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*文字列→数値変換*/
		
		/*目的の数値をツリーから探索*/
		if(search(root,num_temp) != NULL){
			printf("○ %dはツリーに存在します。",num_temp);/*結果表示*/
		}else{
			printf("× %dはツリーに存在しません。",num_temp);
		};
	}
	return (0);
}

/*=======================================
ランダムな整数を生成する
但し重複した数値は生成しない
---------------------------------------*/
void create_random_num(int size,int *random_num){
	int i=0,j=0;
	int temp_num=0;
	
	srand( (unsigned)time( NULL ) );/*現在時刻を使い乱数ジェネレータを初期化*/
	printf("\nランダム整数：");
	
	
	random_num[0] = (rand() % RANDOM_MAX) + 1;
	   for(i=1;i<size;i++){/*ランダムなリストを生成する*/
		   temp_num = (rand() % RANDOM_MAX) + 1;/*1～RANDOM_MAXのランダムな数値を生成*/
		   for(j=0;j<i;j++){
			   if(random_num[j] == temp_num){/*重複する数値が既に配列内に存在していたらやり直し*/
				   i--;
				   break;
			   }
		   }
		   if(i == j){/* 最後まで重複しなかったら */
				random_num[i] = temp_num;
				printf("%d, ",random_num[i]);
		   }
	   }
}
