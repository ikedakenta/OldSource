/*
bitフィールドの速度計測プログラム
開発環境　Windows XP   Microsoft VisualC++6.0
GNU C++
P00011	池田　健太
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/
#include <ctype.h>/*文字処理*/
#include <time.h>/*時間処理*/

/*シミュレーションする回数*/
#define LOOP 10000
/*シミュレーションする舞台の大きさLOOPとSIZE_STARATの値によって決まる*/
#define SIZE 2000
#define jikan //デバッグ用時間計測
struct bitset{
	unsigned int test0 : 1;
	unsigned int test1 : 1;
	unsigned int test2 : 1;
	unsigned int test3 : 1;
	unsigned int test4 : 1;
	unsigned int test5 : 1;
	unsigned int test6 : 1;
	unsigned int test7 : 1;
};

int main(void){
	int i,j,l;
	char test[8][SIZE];
	struct bitset data[SIZE];
	
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	clock_t time1,time2,time3;
	double keika;
	char gomi[10];
#endif ///////////////////////////////////////////////////////////////////////
	
	/*初期化*///////////////////////////////////////////////////////////
	for (i=0;i<8;i++){
		for(j=0;j<SIZE;j++){
			test[i][j]=0;
		}
	}
	for(i=0;i<SIZE;i++){
		data[i].test0=0;
		data[i].test1=0;
		data[i].test2=0;
		data[i].test3=0;
		data[i].test4=0;
		data[i].test5=0;
		data[i].test6=0;
		data[i].test7=0;
	}
#ifdef jikan
	time1=clock();/*時間測定*/
#endif
	/*代入操作ループ*////////////////////////////////////////////////
	for(l=0;l<LOOP;l++){
		for(i=0;i<8;i++){
			for(j=0;j<SIZE;j++){
				test[i][j]=1;
			}
		}
	}
#ifdef jikan
	time2=clock();
#endif
	/*代入操作ループ*////////////////////////////////////////////////
	for(l=0;l<LOOP;l++){
		for(i=0;i<SIZE;i++){
			data[i].test0=1;
			data[i].test1=1;
			data[i].test2=1;
			data[i].test3=1;
			data[i].test4=1;
			data[i].test5=1;
			data[i].test6=1;
			data[i].test7=1;
		}
	}
#ifdef jikan
	time3=clock();
#endif
	
	
#ifdef jikan /*デバッグ用時間測定*/////////////////////////////////////////////
	keika=time2-time1;
	printf("通常配列コピー処理 　　　所要時間：%f\n",keika/1000.0);
	keika=time3-time2;
	printf("bitフィールドコピー処理　所要時間：%f\n",keika/1000.0);
	gets(gomi);
#endif ///////////////////////////////////////////////////////////////////////
	
	return(0);
}
