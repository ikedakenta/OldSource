/*===================================
マインスイーパ
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include "mine_management.h"


/*=======================================
マス目のメモリ領域確保
---------------------------------------*/
MINE_TABLE ** getMemory(int size_x,int size_y){
	MINE_TABLE ** table;
	int i;
	
	/*テーブルサイズを保管*/
	MINE_TABLE_WIDTH = size_x;
	MINE_TABLE_HIGHT = size_y;

	/*2次元配列のまずは先頭列をポインタ型で確保*/
	table = (MINE_TABLE **)malloc(sizeof(MINE_TABLE *) * (size_y + 2));
	/*確保したポインタ列にそれぞれ配列を確保してつなぐ*/
	for(i = 0;i < size_x + 2;i++){
		*(table + i) = (MINE_TABLE *)malloc(sizeof(MINE_TABLE) * (size_x + 2));
	}
	return table;/*確保した領域を返す*/
}

/*=======================================
マス目の初期化
---------------------------------------*/
void init_mine_table(MINE_TABLE **table){
	int i,j;
	int temp_num = 0;
	
	srand( (unsigned)time( NULL ) );/*現在時刻を使い乱数ジェネレータを初期化*/
	
	/*マス目の状態を初期化*/
	for(i = 0;i < MINE_TABLE_HIGHT + 2;i++){
		for(j = 0;j < MINE_TABLE_WIDTH + 2;j++){
			table[i][j].table_statement = CLOSE;/*開かれていない状態をセット*/
			table[i][j].table_val = 0;/*数字に０をセット*/
			table[i][j].table_bom = 0;/*爆弾なしをセット*/
		}
	}
	/*マス目に爆弾を配置する*/
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
		/*1～　難易度数値を生成 
		DIFFICULT 1:EASY 2:NORMAL 3:HARD
		DIFFICULTが1のときは１～６の乱数を生成する
		DIFFICULTが2のときは１～７の、HARDのときは１～８の乱数を生成する。
			*/
			temp_num = ((rand() * RAND_MAX) % (DIFFICULT + 5)) + 1;
			if(temp_num > 5){/*６以上なら*/
				table[i][j].table_bom = BOM;/* 爆弾を配置 */ 
			}
		}
	}
	
	/*マス目に数字をセットする*/
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
			if(table[i][j].table_bom == BOM){/*爆弾なら*/
				continue;
			}
			/*周囲の爆弾の数を自身の数字情報に足してセット*/
			table[i][j].table_val += 
				table[i-1][j-1].table_bom + table[i][j-1].table_bom + table[i+1][j-1].table_bom +
				table[i-1][j].table_bom +							table[i+1][j].table_bom +
				table[i-1][j+1].table_bom + table[i][j+1].table_bom + table[i+1][j+1].table_bom;
		}
	}
	/*ゲーム開始時に最初に一回だけどこか開いておく*/
	first_open(table);
}

/*=======================================
ゲーム開始時最初に一回開く処理
---------------------------------------*/
void first_open(MINE_TABLE **table){
	int x,y;
	
	while(1){
		x = ((rand() * RAND_MAX) % MINE_TABLE_WIDTH) + 1;/*1～MINE_TABLE_WIDTHまでの乱数を得る*/
		y = ((rand() * RAND_MAX) % MINE_TABLE_HIGHT) + 1;/*1～MINE_TABLE_HIGHTまでの乱数を得る*/
		
		/*爆弾でない部分をオープンする*/
		if(table[x][y].table_bom != BOM){
			open_mine_table(table,x,y);
			return;
		}
	}
}

/*=======================================
マス目を開く
---------------------------------------*/
void open_mine_table(MINE_TABLE **table,int x,int y){
	int i,j;
	/*指定された座標が想定範囲をはみ出していたら処理しない*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}
	
	table[x][y].table_statement = OPEN;/* OPEN 状態にする */
	if( table[x][y].table_val == 0 && table[x][y].table_bom != BOM){
		for( i=-1; i<=1; i++ ){
			for( j=-1; j<=1; j++ ){
				if(table[x + i][y + j].table_statement == CLOSE){
					open_mine_table(table,x+i,y+j);
				}
			}
		}
	}
}

/*=======================================
既に開かれたマス目周辺を開く
機能：
数字の入ったマス目が開いていて、
それに隣接する地雷に既に印をつけているときに
マス目周辺を一度に開けられる
---------------------------------------*/
void open_mine_table_execute(MINE_TABLE **table,int x,int y){
	int i,j;
	int bomz;
	/*指定された座標が想定範囲をはみ出していたら処理しない*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}
	if(isBomd(table,x,y) == 0){
		bomz = 0;
		for( i=-1; i<=1; i++ ){
			for( j=-1; j<=1; j++ ){
				if(table[x + i][y + j].table_bom == BOM){
					bomz += 1;
				}
			}
		}
		/*自分の数字と周辺の爆弾の数が一致していれば*/
		if(bomz == table[x][y].table_val){
			for( i=-1; i<=1; i++ ){
				for( j=-1; j<=1; j++ ){
					if(table[x + i][y + j].table_bom != BOM){
						table[x][y].table_statement = OPEN;/* OPEN 状態にする */
					}
				}
			}
		}
	}
}

/*=======================================
何マス開かれたか調べる
返り値：現在の開かれたマス目の数
---------------------------------------*/
int get_opend_count(MINE_TABLE **table){
	int i,j,count = 0;
	
	/*マス目を調べOPENだったらカウントを１増やす*/
	for(i = 1;i<MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j<MINE_TABLE_WIDTH + 1;j++){
			if(table[i][j].table_statement == OPEN ){
				count += 1;
			}else if(table[i][j].table_statement == FLAG && table[i][j].table_bom == BOM){
				count += 1;
			}
		}
	}
	//printf("クリアーまで後 %d マス\n",(MINE_TABLE_WIDTH * MINE_TABLE_HIGHT) - count);
	return count;
}


/*=======================================
マス目に印をつける
---------------------------------------*/
void check_flag_mine_table(MINE_TABLE **table,int x,int y){
	/*指定された座標が想定範囲をはみ出していたら処理しない*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}

	if(table[x][y].table_statement ==CLOSE){/*閉じていたら*/
		table[x][y].table_statement = FLAG;/*印をつける*/
	}else if(table[x][y].table_statement == FLAG){/*印がついていたら*/
		table[x][y].table_statement = CLOSE;/*印の解除*/
	}
}

/*=======================================
指定したマス目が開かれているかどうか調べる
返り値：真偽
---------------------------------------*/
int isOpend(MINE_TABLE **table,int x,int y){
	
	/*OPENかどうか調べる*/
	if(table[x][y].table_statement == OPEN){
		return 1;
	}
	return 0;
}

/*=======================================
指定したマス目に爆弾があるかどうか調べる
返り値：真偽
---------------------------------------*/
int isBomd(MINE_TABLE **table,int x,int y){
	
	/*爆弾があるかどうか調べる*/
	if(table[x][y].table_bom == BOM){
		return 1;
	}
	return 0;
}

/*=======================================
クリアー条件を満たしたかどうか調べる
---------------------------------------*/
int isClear(MINE_TABLE **table){
	int val = 0;
	
	val = get_opend_count(table);
	if(val == ((MINE_TABLE_WIDTH) * (MINE_TABLE_HIGHT))){
		return 1;
	}
	return 0;
}

/*=======================================
マス目表示
---------------------------------------*/
void view_mine_table(MINE_TABLE **table,int debug){
	int i,j;
	/*マス目を表示する*/
	printf("   ");
	for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
		printf("%2d",j);
	}
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		printf("\n%2d:",i);
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
			if(debug == 1){
				/* マス目が爆弾の時 */
				if(table[i][j].table_bom == BOM){
					printf(" *");
					/* マス目が空のとき */
				}else if(table[i][j].table_val == 0){
					printf("□");
					/*数字が入っているとき*/
				}else if(table[i][j].table_val > 0){
					printf("%2d",table[i][j].table_val);
					/*印がつけてあるとき*/
				}else if(table[i][j].table_statement == FLAG){
					printf("■");
				}
			}else{
				/* マス目が爆弾の時 */
				if(table[i][j].table_statement == OPEN && table[i][j].table_bom == BOM){
					printf(" *");
					/* マス目が空のとき */
				}else if(table[i][j].table_statement == OPEN && table[i][j].table_val == 0){
					printf("□");
					/*数字が入っているとき*/
				}else if(table[i][j].table_statement == OPEN && table[i][j].table_val > 0){
					printf("%2d",table[i][j].table_val);
					/*印がつけてあるとき*/
				}else if(table[i][j].table_statement == FLAG){
					printf("■");
				}else{
					printf("  ");
				}
			}
		}
	}
}

/*=======================================
ゲームオーバー
---------------------------------------*/
void gameover(void){
	char gomi[16];
	printf("ゲームオーバーです！！\n");
	printf("何かキーを押してください。終了します。\n");
	gets(gomi);/*文字入力受付*/
	exit(0);
}


/*=======================================
ゲームクリア
---------------------------------------*/
void gameclear(void){
	char gomi[16];
	printf("クリアー！！おめでとう！\n");
	printf("何かキーを押してください。終了します。\n");
	gets(gomi);/*文字入力受付*/
	exit(0);
}