/*===================================
２００６年度プログラム研修
演習課題（５）問題７
作成日　４月２７日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "main.h"
#include "mine_management.h"

int main(void){
/*マス目の確保
	端の一列は空のまま使うので余分に2列多く取る*/
	//MINE_TABLE table[MINE_TABLE_HIGHT + 2][MINE_TABLE_WIDTH + 2];
	MINE_TABLE **table;

	/*マス目メモリ領域確保*/
	table = getMemory(MINE_TABLE_WIDTH,MINE_TABLE_HIGHT);
	/*マス目初期化*/
	init_mine_table(table);
	
	printf("\n座標を入力し、行動を数値で入力して下さい。\n"
			"(q でプログラム終了します。)\n"
			"(r でゲームをリスタートします。)\n");

	while(1){
		/*マス目表示*/
		view_mine_table(table,debug);
		
		/*登録処理*/
		printf("\n(d でデバッグ表示します。)"
			"例：x y no\n"
			"x,y：座標 no：1 めくる 2 フラグ立て\n"
			"-->");
		gets(char_temp);/*文字入力受付*/
		if(strcmp("q",char_temp) == 0){
			printf("終了します。\n");
			return 0;
		}else if(strcmp("d",char_temp) == 0){
			if(debug == 0){
				debug = 1;/*デバッグ表示ON*/
			}else if(debug == 1){
				debug = 0;/*デバッグ表示OFF*/
			}
		}else if(strcmp("r",char_temp) == 0){
			/*ゲーム初期化*/
			init_mine_table(table);
			continue;
		}
		/*入力受付*/
		sscanf(char_temp,"%d %d %d",&y,&x,&no);
		
		/*マス目を開く*/
		if(no == 1){
			if(isBomd(table,x,y)){/*爆弾なら*/
				if(isOpend(table,x,y)){
					printf("そのマスは既に開いています。\n");
				}else{
					gameover();/*ゲームオーバー*/
				}
			}else{
				if(isOpend(table,x,y)){
					/*既に開かれている数字の周りを自動で開く*/
					open_mine_table_execute(table,x,y);
				}else{
					/*未開拓領域を開く*/
					open_mine_table(table,x,y);
				}
			}
		}else if(no == 2){
			if(isOpend(table,x,y)){
				printf("そのマスは既に開いています。\n");
			}else{
				/*印をつける*/
				check_flag_mine_table(table,x,y);
			}
		}

		if(isClear(table)){/*クリアーなら*/
			gameclear();
		}
	}
	return(0);
}