/*
プログラミング演習課題11
開発環境　Windows XP   Microsoft VisualC++6.0
		  Cygwin GNU C++
							P00011	池田　健太
----------------------------------------------------
このプログラムでは発生させる乱数の範囲を指定でき
理想的な正規分布と比べて擬似乱数ではどの程度理論値とずれるかを測定するものである。

プログラムの使い方
コマンドラインで実行する際に次の引数を与えてやることですぐに実行できる。
*.exe 平均　標準偏差　発生させる擬似乱数の総数　乱数の種
例：ransuu.exe 0.0 1.0 100000 1

コマンドラインから引数を与えずに起動した場合は各設定項目値を後から入力する。
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/
#include <ctype.h>/*文字処理*/
#include <math.h>/*数学計算*/

/*実行時引数を取れるように*/
int main(int argc,char *argv[])
{
	double heikin;          /* 平均 */
	double hensa;           /* 標準偏差 */
	long num_ransuu;        /* 発生させる疑似乱数の総数 */
	unsigned int ranseed;   /* 乱数の種 */
	double riron1=0,riron2=0,riron3=0;/*理論値の計算に使う*/
	int j;
#ifdef METHOD_A
	double x1,x2,y1,y2;/*ボックス・マラー法にて使用*/
#endif
#ifdef METHOD_B
	double b_ransuu;/*一様乱数平均法にて使用*/
	int i;/*for文などで使用する*/
#endif
	/***** コマンドラインからのパラメータ代入 *****/
	if(argc >= 5)/*パラメータが5以上の場合*/
	{
		heikin=atof(argv[argc-4]);        /* 平均 */
		hensa=atof(argv[argc-3]);         /* 標準偏差 */
		num_ransuu=atoi(argv[argc-2]);    /* 発生させる疑似乱数の総数 */
		ranseed=atoi(argv[argc-1]);       /* 乱数の種 */
		if(num_ransuu <= 0)/*発生させる擬似乱数の総数の設定がおかしい場合*/
		{
			printf("発生させる擬似乱数の総数は1以上にしてください。\n");
			exit(1);/*異常終了*/
		}
		if(hensa <= 0.0)/*標準偏差の数がおかしい場合*/
		{
			printf("標準偏差0以上にしてください。\n");
			exit(1);/*異常終了*/
		}
	}
	else/*コマンドラインからの入力が不十分だった場合*/
	{
		printf("次の順番で各設定項目を決めてください\n平均　標準偏差　発生させる擬似乱数の総数　乱数の種類\n");
		scanf("%lf %lf %d %d",&heikin,&hensa,&num_ransuu,&ranseed);
	}
	
	printf("平均=%g 標準偏差=%g 乱数の総数=%d\n計算中............\n",heikin,hensa,num_ransuu);
	
	srand(ranseed);/* 乱数の種を設定(値が同じなら同じ乱数系列となる) */
	/* 乱数を生成させながらデータの割合を算出 */    
	for(j=0;j<num_ransuu;j++){

#ifdef METHOD_A  /* ボックス・マラー法 */
		x1=((double)rand()+1)/RAND_MAX;
		x2=((double)rand()+1)/RAND_MAX;
		y1=cos( (360*x2*3.14159265358979) /180.0)*sqrt((-2)*log(x1));

		/*ここではy1だけあれば測定はできるのでy2は計算から除外する*/
		/*y2=sin( (360*x2*3.14159265358979) /180.0)*sqrt((-2)*log(x1));*/
		if(y1<=hensa   && y1>=-hensa  )riron1+=1;
		if(y1<=hensa*2 && y1>=-hensa*2)riron2+=1;
		if(y1<=hensa*3 && y1>=-hensa*3)riron3+=1;
#endif
		
#ifdef METHOD_B  /* 一様乱数平均 */
		b_ransuu=0;
		for(i=0;i<12;i++){/*0以上1以下の一様乱数を12個加算*/
			b_ransuu+=((double)rand()/RAND_MAX);/*double型にキャストする必要あり*/
		}
		b_ransuu-=6;/*そこから6引く*/

		/*正規分布の割合を計算するための布石*/
		if(b_ransuu<=hensa&&b_ransuu>=-hensa)riron1+=1;
		if(b_ransuu<=hensa*2&&b_ransuu>=-hensa*2)riron2+=1;
		if(b_ransuu<=hensa*3&&b_ransuu>=-hensa*3)riron3+=1;
#endif

	}
	/*割合計算及び型のキャスト*/
	riron1/=num_ransuu;
	riron2/=num_ransuu;
	riron3/=num_ransuu;
    /* 算出した割合の表示 */
	printf("平均μから±1σ、±2σ、±3σ内のデータ数の割合\n"
		"---------------------------------------------------------------\n"
		"　　　　| ±１σ　　 ±２σ　　 ±３σ\n"
		"　　　　|% .7f % .7f % .7f\n"
	        "理論値差|% .7f % .7f % .7f\n",riron1,riron2,riron3,
	       (riron1-0.6827),(riron2-0.9545),(riron3-0.9973));
}
