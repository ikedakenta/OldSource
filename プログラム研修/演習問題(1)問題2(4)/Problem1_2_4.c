/*===================================
２００６年度プログラム研修
演習課題（１）問題２（４）
作成日　４月２０日
作成者　池田　健太
------------------------------------*/

#include "Problem1_2_4.h"

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*最初の構造体の場所を記憶する*/
	LIST *wkdata = NULL;/*データ設定用*/
	start = &dmy;
	start->next = NULL;/*最初はデータがないのでＮＵＬＬを設定しておく*/
	
	/*ランダムな整数を生成する*/
	create_random_num(LIST_MAX,random_num);
	
	for( no = 0 ; no < LIST_MAX ; no++ ){
		/*データを昇順でリストに追加する*/
		insert(start,random_num[no]);

		/*リストを表示*/
		view_list(start,no);	
		
	}
	
	gets(char_temp);/*文字入力受付*/
	printf("何かキー入力をすると終了します。\n");
	return(0);
}

/*=======================================
ランダムな整数を生成する
---------------------------------------*/
void create_random_num(int size,int *random_num){
	int i=0;
	
	srand( (unsigned)time( NULL ) );/*現在時刻を使い乱数ジェネレータを初期化*/
	printf("\nランダム整数：");
	   for(i=0;i<LIST_MAX;i++){/*ランダムなリストを生成する*/
		   random_num[i] = (rand() % 20) + 1  ;//(rand() % 10) + 1;/*1～20のランダムな数値を生成*/
		   printf("%d, ",random_num[i]);
	   }
	   
}

/*=======================================
データを昇順でリストに追加する
---------------------------------------*/
void insert(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;
	
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	
	for(wp = start;wp->next != NULL;wp = wp->next){
		if(val < wp->next->num){/*大小関係を比較して*/
			wkdata->next = wp->next;/*チェインをつなぎかえる*/
			wp->next = wkdata;
			break;
		}
	}
	/*チェインの最後につなぐ*/
	if(wp->next ==NULL){
		wkdata->next = NULL;
		wp->next = wkdata;
	}
}

/*========================================
リスト表示
----------------------------------------*/
void view_list(LIST *start,int no){
	LIST *wp;
	
	/*リストを表示*/
	printf("\n list[%d]:",no);
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
