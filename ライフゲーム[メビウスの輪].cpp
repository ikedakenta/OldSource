/*
プログラミング演習課題10
ライフゲーム「メビウスの輪」仕様
開発環境　Windows XP   Microsoft VisualC++6.0
P00011	池田　健太
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/

/*シミュレーションする期間、何世代目までシミュレートするか指定*/
#define LOOP 115
#define SIZE 30/*盤面のサイズ*/
//#define gamen //デバッグ用画面出力

/*プロトタイプ宣言*/
void init(void);
void next(void);
void write(void);

/*グローバル変数宣言*/
char pat[SIZE+2][SIZE+2];/*多次元配列による盤面確保*/
char prepat[SIZE+2][SIZE+2];

int main(void){
	char gomi[10];
	init();/*配列初期化する*/
	printf("シミュレーションを開始します。\n........シミュレーション中\n");
	next();/*世代シミュレーション*/
	printf("シミュレーションが終了しました。\n");
	write();/*ファイルへの書き出し*/
	printf("\n結果を「life.txt」へ書きこみました\n");
	gets(gomi);
	return(0);
}


void init()/*初期化*/
{
	int i,j;
	i=5;/*一番右下の要素のy座標*/
	j=5;/*一番右下の要素のx座標*/
	
	prepat[i][j]		=1;
	prepat[i][j-1]		=1;
	prepat[i][j-2]		=1;
	prepat[i][j-3]		=1;
	prepat[i-1][j]		=1;
	prepat[i-2][j]		=1;
	prepat[i-3][j-1]	=1;
	prepat[i-1][j-4]	=1;
	
}

/*世代シミュレート*/
void next(){
	
	int i,j,l,count;
	
	for(l=0;l<LOOP;l++){/*#define LOOPで指定した回数だけ世代シミュレーション*/
		
		/*端っこ一列を余分に取っておいたのでここを利用してメビウスの輪を実現する*/
		for(i=1;i<SIZE;i++){/*上下ねじって接続*/
			prepat[i][SIZE+1]=prepat[SIZE+1-i][1];
			prepat[i][0]=prepat[SIZE+1-i][SIZE];
		}
		for(j=1;j<SIZE;j++){/*単純に上下をつなぐ*/
			prepat[SIZE+1][j]=prepat[1][j];
			prepat[0][j]=prepat[SIZE][j];
		}
		
		/*次世代判定部分*/
		for(i=1;i<SIZE+1;i++){
			for(j=1;j<SIZE+1;j++){
			/*フラグを調べ自身の周りに何個生きている目があるか探索
				現在の目が端っこの場合、メビウスの輪になるように判定する部分を上下ねじる*/
				count=0;/*毎回初期化*/
				count=prepat[i-1][j-1]+prepat[i][j-1]
					+prepat[i+1][j-1]+prepat[i-1][j]+prepat[i+1][j]
					+prepat[i-1][j+1]+prepat[i][j+1]+prepat[i+1][j+1];
				/* 注目点が0の場合、もし周囲の点が３点あれば注目点は１になる */
				/* そうではなくて注目点が1の場合、もし周囲の点が4点以上あるいは */
				/* 2点より少なければ、過密あるいは過疎により注目点は0になる */
				if(prepat[i][j]==0){/*自身が死んでいるとき*/
					if(count==3){
						pat[i][j]=1;/*周りに生きている目が3つあれば自身も生きる*/
					}
				}
				else if(prepat[i][j]==1){/*自身が生きているとき*/
					if(count!=2 && count!=3){
						pat[i][j]=0;/*周りに生きている目が4以上もしくは2未満の場合、自身は死ぬ*/
					}
					else{
						pat[i][j]=1;
					}
				}
			}
		}
		for(i=0;i<SIZE+2;i++){
			for(j=0;j<SIZE+2;j++){
				prepat[i][j]=pat[i][j];
			}/*新しい世代へ更新する*/
		}
	}
}

/*ファイルへの書き込み*/
void write(void){
	
	FILE *fp;
	int i,j;
	fp=fopen("life.txt","w");
	for(i=1;i<SIZE;i++){
		for(j=1;j<SIZE;j++){
			if(prepat[i][j]==1)fprintf(fp,"■");/*生きている目*/
			else fprintf(fp,"　");/*死んでいる目は空白で何も表示しない*/
		}
		fprintf(fp,"\n");/*一行ごとに改行*/
	}
	fclose(fp);
	
#ifdef gamen//デバッグ用画面出力////////////////////////////////////////////
	for(i=0;i<SIZE+1;i++){
		for(j=0;j<SIZE+1;j++){
			if(prepat[i][j]==1)printf("■");/*生きている目*/
			else printf("　");/*死んでいる目は空白で何も表示しない*/
		}
		printf("\n");/*一行ごとに改行*/
	}
#endif///////////////////////////////////////////////////////////////////////
	
}