/*
ライフゲーム
開発環境　Windows XP   Microsoft VisualC++6.0
VineLinux    GNU C++
両環境で動作確認済み
　　　　　　　　　　　　　　　　P00011	池田　健太
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/
#include <ctype.h>
#include <time.h>

/*シミュレーションする期間、何世代目までシミュレートするか指定*/
#define LOOP 100
/*初期化する形の大きさ*/
#define SIZE_START 5
/*シミュレーションする舞台の大きさLOOPとSIZE_STARATの値によって決まる*/
#define SIZE_MATRIX (2*LOOP+2*SIZE_START)
#define jikan        /*デバッグ用に時間測定する場合*/

/*プロトタイプ宣言*/
char **malloc_2d();
void ini(char **,char **);
void next(char **,char **);
void write(char **);
void free_2d(char **);
char main(void){
		
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	clock_t time1,time2;
	double keika=0;
	char gomi[10];
	time1=clock();
#endif ///////////////////////////////////////////////////////////////////////
	char **pat,**prepat;
	/*メモリ確保*/
	prepat=malloc_2d();
	pat=malloc_2d();
	ini(prepat,pat);/*初期化*/
	printf("シミュレーションを開始します。\n........シミュレーション中\n");
	next(prepat,pat);/*シミュレーション関数*/
	write(prepat);/*結果をファイルへ出力*/
	/*メモリを解放*/
	free_2d(pat);
	free_2d(prepat);
	
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	time2=clock();
	keika=time2-time1;
	printf("所要時間：%f",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	return(0);
}


/*メモリ確保*/
char **malloc_2d(){
	int i;
	char **p1,*p2;
	
	if((p1=(char **)malloc(SIZE_MATRIX*sizeof(char *)))==NULL){
		printf("メモリ確保失敗\n");
		exit(-1);
	}
	if((p2=(char *)malloc(SIZE_MATRIX*SIZE_MATRIX*sizeof(char)))==NULL){
		printf("メモリ確保失敗\n");
		exit(-1);
	}
	for(i=0;i<SIZE_MATRIX;i++)
		p1[i]=p2+SIZE_MATRIX*i;
	return p1;
}

/*初期化関数*/
void ini(char **prepat,char **pat){
	int i,j,m;
	char *p1,*p2;
	i=j=SIZE_MATRIX/2;/*iを真ん中にする*/
	p1=&prepat[0][0];
	p2=&pat[0][0];
	for(m=0;m<SIZE_MATRIX*SIZE_MATRIX;m++){
			*(p1++)=*(p2++)=0;
	}
	/*ペントオミノとして初期化*/
	prepat[i][j]		=1;
	prepat[i-1][j]		=1;
	prepat[i][j-1]		=1;
	prepat[i+1][j]		=1;
	prepat[i-1][j+1]	=1;
}

void next(char **prepat,char **pat){
	
	int i,j,m,n,l,count;
	/*盤面の中心、生存が認められる可能性がある範囲を指定する*/
	m=SIZE_MATRIX/2-SIZE_START;
	n=SIZE_MATRIX/2+SIZE_START;
	
	for(l=0;l<LOOP;l++){/*#define LOOPで指定した回数だけ世代シミュレーション*/
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
				/*フラグを調べ自身の周りに何個生きている目があるか探索*/
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
		for(i=m;i<n;i++){
			for(j=m;j<n;j++){
			/*範囲を狭めて必要な部分だけコピーしているので
			アドレスが一意に並んでいない。
				そのためポインタが使えないので普通に配列の要素を順々にコピー*/
				prepat[i][j]=pat[i][j];
			}/*新しい世代へ更新する*/
		}
		m--;/*操作範囲を広げる*/
		n++;
	}
}

/*ファイル書き込み関数*/
void write(char **prepat){
	
	FILE *fp;
	int i,j,m,n;
	/*ファイル操作もシミュレーションの時と同じように
	シミュレーション結果が確認できるのに
	必要十分なだけの範囲を指定して処理する。*/
	m=SIZE_MATRIX/2-SIZE_START-LOOP;
	n=SIZE_MATRIX/2+SIZE_START+LOOP;
	
	printf("シミュレーションが終了しました。\n");
	fp=fopen("life.txt","w");
	for(i=m;i<n;i++){
		fprintf(fp,"\n");/*一行ごとに改行*/
#ifdef gamen
		printf("\n");
#endif
		for(j=m;j<n;j++){
			if(prepat[i][j]==1)fprintf(fp,"+");/*生きている目*/
			else fprintf(fp," ");/*死んでいる目は空白で何も表示しない*/
		}
	}
	fclose(fp);
	printf("\n結果を「life.txt」へ書き込みました。\n");
}

/*メモリ解放*/
void free_2d(char **point){
	free(point[0]);
	free(point);
}
