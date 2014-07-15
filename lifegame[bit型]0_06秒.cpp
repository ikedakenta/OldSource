/*
ライフゲーム
開発環境　Windows XP   Microsoft VisualC++6.0
GNU C++
P00011	池田　健太
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/
#include <ctype.h>/*文字処理*/
#include <time.h>/*時間処理*/

/*シミュレーションする期間、何世代目までシミュレートするか指定*/
#define LOOP 100
/*初期化する形の大きさ*/
#define SIZE_START 5
/*シミュレーションする舞台の大きさLOOPとSIZE_STARATの値によって決まる*/
#define SIZE (2*LOOP+2*SIZE_START)
#define jikan //デバッグ用時間計測
struct bitset{
	unsigned int pat : 1;
	unsigned int prepat: 1;
};
/*プロトタイプ宣言*/
void init(void);
void next(void);
void write(void);

/*グローバル変数宣言*/
struct bitset data[SIZE][SIZE];
int main(void){
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	clock_t time1,time2;
	double keika;
	char gomi[10];
	time1=clock();
#endif ///////////////////////////////////////////////////////////////////////
	init();/*配列初期化する*/
	
	printf("シミュレーションを開始します。\n........シミュレーション中\nしばらくお待ちください。\n");
	next();
	printf("シミュレーションが終了しました。\n結果をファイルに書き込んでいます。\n");
	write();/*ファイルへの書き出し*/
	printf("\n書き込みを終了しました。\n");
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	time2=clock();
	keika=time2-time1;
	printf("所要時間：%f",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	return(0);
}

void init()/*初期化*/
{
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			
			data[i][j].prepat		=0;
			data[i][j].pat	=0;
		}
	}
	i=j=SIZE/2;/*iを真ん中にする*/
	/*ペントオミノとして初期化*/
	data[i][j].prepat		=1;
	data[i-1][j].prepat		=1;
	data[i][j-1].prepat		=1;
	data[i+1][j].prepat		=1;
	data[i-1][j+1].prepat	=1;
}

/*世代シミュレート*/
void next(){
	
	int i,j,count,m,n,l;
	m=SIZE/2-SIZE_START;
	n=SIZE/2+SIZE_START;
	
	for(l=0;l<LOOP;l++){/*#define LOOPで指定した回数だけ世代シミュレーション*/
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
				/*フラグを調べ自身の周りに何個生きている目があるか探索*/
				count=0;/*毎回初期化*/
				count=data[i-1][j-1].prepat+data[i][j-1].prepat
					+data[i+1][j-1].prepat+data[i-1][j].prepat+data[i+1][j].prepat
					+data[i-1][j+1].prepat+data[i][j+1].prepat+data[i+1][j+1].prepat;
				/* 注目点が0の場合、もし周囲の点が３点あれば注目点は１になる */
				/* そうではなくて注目点が1の場合、もし周囲の点が4点以上あるいは */
				/* 2点より少なければ、過密あるいは過疎により注目点は０になる */
				if(data[i][j].prepat==0){/*自身が死んでいるとき*/
					if(count==3){
						data[i][j].pat=1;/*周りに生きている目が3つあれば自身も生きる*/
					}
				}
				else if(data[i][j].prepat==1){/*自身が生きているとき*/
					if(count!=2 && count!=3){
						data[i][j].pat=0;/*周りに生きている目が4以上もしくは2未満の場合、自身は死ぬ*/
					}
					else{
						data[i][j].pat=1;
					}
				}
			}
		}
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
				data[i][j].prepat=data[i][j].pat;
			}
		}/*新しい世代へ更新する*/
		m--;
		n++;
	}
}

/*ファイルへの書き込み*/
void write(void){
	
	FILE *fp;
	int i,j,m,n;
	/*ファイル操作もシミュレーションの時と同じように
	シミュレーション結果が確認できるのに
	必要十分なだけの範囲を指定して処理する。*/
	m=SIZE/2-SIZE_START-LOOP;
	n=SIZE/2+SIZE_START+LOOP;
	
	fp=fopen("life.txt","w");
	for(i=m;i<n;i++){
		fprintf(fp,"\n");/*一行ごとに改行*/
		for(j=m;j<n;j++){
			if(data[i][j].prepat==1)fprintf(fp,"+");/*生きている目*/
			else fprintf(fp," ");/*死んでいる目は空白で何も表示しない*/
		}
	}
	fclose(fp);
}