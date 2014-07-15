/*===================================
ランダム整数生成
作成日　４月２６日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "random.h"

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
