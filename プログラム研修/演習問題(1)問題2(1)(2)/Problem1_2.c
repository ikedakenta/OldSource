/*===================================
２００６年度プログラム研修
演習課題（１）問題２（１）（２）
作成日　４月２０日
作成者　池田　健太
------------------------------------*/

#include "Problem1_2.h"
void insert_tail(LIST *start,int val);
void view_list(LIST *start);

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*最初の構造体の場所を記憶する*/
	LIST *wkdata;/*データ設定用*/
	
	start = &dmy;
	start->next = NULL;/*最初はデータがないのでＮＵＬＬを設定しておく*/
	
	while(1){
		printf("\n数値を入力して下さい。(q でプログラム終了します。)\n-->");
		gets(char_temp);/*文字入力受付*/
		
		if(strcmp("q",char_temp) == 0){
			printf("終了します。\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*文字列→数値変換*/
		
		/*リストへ要素を追加*/
		insert_tail(start,num_temp);
		
		/*リストを表示*/
		view_list(start);
	}
	
	return(0);
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
	LIST *wkdata;
	
	/*リストを表示*/
	printf("現在のリストの中身\n");
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
