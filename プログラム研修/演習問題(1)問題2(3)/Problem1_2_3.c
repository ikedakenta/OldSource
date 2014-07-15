/*===================================
２００６年度プログラム研修
演習課題（１）問題２（３）
作成日　４月２０日
作成者　池田　健太
------------------------------------*/

#include "Problem1_2_3.h"
void insert_position(LIST *start,int val,int position);
void insert_tail(LIST *start,int val);
void view_list(LIST *start);
void create_random_list(LIST *start,int list_size);

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*最初の構造体の場所を記憶する*/
	
	start = &dmy;
	start->next = NULL;/*最初はデータがないのでＮＵＬＬを設定しておく*/
	
	/*ランダムなリストを生成する*/
	create_random_list(start,RANDOM_LIST_SIZE);
	   
	   while(1){
		   /*リストを表示*/
		   view_list(start);
		   
		   printf("\n数値を入力して下さい。(q でプログラム終了します。)\n-->");
		   gets(char_temp);/*文字入力受付*/
		   if(strcmp("q",char_temp) == 0){
			   printf("終了します。\n");
			   return 0;
		   }
		   num_temp	=	atoi(char_temp);/*文字列→数値変換*/
		   printf("\n入力する要素の位置を指定して下さい。(1～)-->");
		   gets(char_temp);/*文字入力受付*/
		   position	=	atoi(char_temp);/*文字列→数値変換*/
		   
		   /*リストの指定位置へ要素を挿入*/
		   insert_position(start,num_temp,position);
		   
	   }
	   
	   return 0;
}

/*=======================================
ランダムなリストを生成する
---------------------------------------*/
void create_random_list(LIST *start,int list_size){
	int i=0;
	   srand( (unsigned)time( NULL ) );/*現在時刻を使い乱数ジェネレータを初期化*/
	   for(i=0;i<list_size;i++){/*最初にランダムなリストを生成する*/
		   
		   insert_tail(start,(rand() % 10));/*0～9のランダムな数値を生成*/
	   }
}

/*=======================================
リストの指定位置へ追加する
---------------------------------------*/
void insert_position(LIST *start,int val,int position){
	LIST *list_temp;
	LIST *wp;
	LIST *wkdata;
	
	wp = start;
	for(i=0;i<position-1;i++){/*指定位置までリストを進む*/
		if(wp->next == NULL)continue;/*指定位置がリスト全長より大きかった場合最後へ追加*/
		wp = wp->next;
	}
	list_temp = wp->next;/*リストの位置保管*/
	
	/*リストを割り込ませる*/
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	wkdata->next = list_temp;/*保管しておいた次リストへ接続*/
	wp->next = wkdata;
}
/*=======================================
リストに追加する
---------------------------------------*/
void insert_tail(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;

	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	
	for(wp = start;wp->next != NULL;wp = wp->next){
		
		if(val < wp->next->num){//大小関係を比較して
			wkdata->next = wp->next;//チェインをつなぎかえる
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
void view_list(LIST *start){
	LIST *wp;
	
	/*リストを表示*/
	printf("現在のリストの中身\n");
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
