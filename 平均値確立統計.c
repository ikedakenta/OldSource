/*    プログラミング演習　第12回
[データの平均値の信頼性]
使用例:a.out 平均 標準偏差 乱数の総数 乱数の種 
開発環境　Windows XP   Microsoft VisualC++6.0
Cygwin GNU C++
P00011	池田　健太
----------------------------------------------------
*/
#include <stdio.h>/*標準*/
#include <stdlib.h>/*標準*/
#include <string.h>/*文字列処理*/
#include <math.h>/*数学計算処理*/

int main(int argc,char *argv[])
{
	FILE *fp;
	double heikin,heikin_sum=0,sample_heikin=0,heikin_temp=0,sample_heikin_heikin;          /* 平均 */
	double hensa,sample_hensa=0;           /* 標準偏差 */
	long num_ransuu;        /* 発生させる疑似乱数の総数 */
	unsigned int ranseed;   /* 乱数の種 */
	char gomi[10];//デバッグ用変数
	
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
	{
		int hist[3]={0,0,0};  /* 割合を算出するためのカウンタ */
		double ran1,ran2;     /* 乱数 */
		int i,m;
		double pai2=8.0*atan(1.0);  /* 2π */
		double x1,x2,a,b,c=0;
		
		
		fp=fopen("data.txt","w");/*ファイル書き込み*/
		heikin_sum=0;/*サンプル平均を０に初期化*/
		for(m=1;m<10000;m++){
			a=0,b=0,c=0,ran1=0,heikin_sum=0,sample_heikin=0,heikin_temp=0;
			num_ransuu=(m/2)*2; /* METHOD_Aの場合は乱数総数を偶数に変更 */
			for(i=1;i<=num_ransuu;i++)
			{
				x1=((double)rand()+1.0)/((double)(RAND_MAX)+1.0);
				x2=((double)rand()+1.0)/((double)(RAND_MAX)+1.0);
				a=pai2*x2;
				b=sqrt(-2.0*log(x1));
				ran1=sin(a)*b*hensa+heikin;    /* 乱数1 */
				/*平均の計算*******************************************************/
				heikin_sum=heikin_sum+ran1;
				sample_heikin=heikin_sum/i;
				heikin_temp+=sample_heikin;
				/*サンプル平均の平均と標準偏差の計算*****************************************/
				c+=((ran1-sample_heikin)*(ran1-sample_heikin));
			}
			
			if(c<0){
				c=-c;
			}
			c/=i;
			sample_heikin_heikin=heikin_temp/num_ransuu;
			sample_hensa=sqrt(c);
			
			/* 算出した割合の表示 */
				fprintf(fp,"%d % 7.5f %7.5f %7.5f\n",m,sample_heikin_heikin,sample_hensa,(sample_hensa-((double)(5/(sqrt(m))))));
	if((m%1000)==0){
		printf("%d % 7.5f %7.5f %7.5f\n",m,sample_heikin_heikin,sample_hensa,(sample_hensa-((double)(5/(sqrt(m))))));
	}
		}
	}
	printf("サンプル平均の平均:%7.5f\nサンプル平均の標準偏差:%7.5f\n→Please Enter anykey",sample_heikin,sample_hensa);
	gets(gomi);
	gets(gomi);//入力待ちにする。
	fclose(fp);
}