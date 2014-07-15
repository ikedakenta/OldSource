/**************************************************/
/*                    normal1_ans.c               */
/* Usage: a.out 平均 標準偏差 乱数の総数 乱数の種 */
/**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void error1(char *);

int main(int argc,char *argv[])
{
  double heikin;          /* 平均 */
  double hensa;           /* 標準偏差 */
  long num_ransuu;        /* 発生させる疑似乱数の総数 */
  unsigned int ranseed;   /* 乱数の種 */

  /***** パラメータ代入 *****/
  if(argc >= 5)
  {
    heikin=atof(argv[argc-4]);        /* 平均 */
    hensa=atof(argv[argc-3]);         /* 標準偏差 */
    num_ransuu=atoi(argv[argc-2]);    /* 発生させる疑似乱数の総数 */
    ranseed=atoi(argv[argc-1]);       /* 乱数の種 */
    if(num_ransuu <= 0)
    {
      printf("1 <= num_ransuu\n");
      exit(1);
    }
    if(hensa <= 0.0)
    {
      printf("hensa > 0.0\n");
      exit(1);
    }
  }
  else
  {
    printf("usage: %s heikin hensa num_ransuu seed\n",argv[0]);
    exit(1);
  }

  printf("heikin=%g hensa=%g num_ransuu=%d\n",heikin,hensa,num_ransuu);

  srandom(ranseed);/* 乱数の種を設定(値が同じなら同じ乱数系列となる) */

  /* 乱数を生成させながらデータの割合を算出 */    
  {
    double dist;          /* σで規格化した平均からの距離 */
    int hist[3]={0,0,0};  /* 割合を算出するためのカウンタ */
    double ran1,ran2;     /* 乱数 */


#ifdef METHOD_A  /* ボックス・マラー法 */    
    {
      int i;
      double pai2=8.0*atan(1.0);  /* 2π */
      double x1,x2,a,b;

      num_ransuu=(num_ransuu/2)*2; /* METHOD_Aの場合は乱数総数を偶数に変更 */
      for(i=0;i<num_ransuu/2;i++)
      {
	x1=((double)random()+1.0)/((double)(RAND_MAX)+1.0);
	x2=((double)random()+1.0)/((double)(RAND_MAX)+1.0);
	a=pai2*x2;
	b=sqrt(-2.0*log(x1));
	ran1=sin(a)*b*hensa+heikin;    /* 乱数1 */
	ran2=cos(a)*b*hensa+heikin;    /* 乱数2 */

	dist=fabs(ran1-heikin)/hensa;  /* σで規格化した平均からの距離 */
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;

	dist=fabs(ran2-heikin)/hensa;
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;
      }
    }
#endif
#ifdef METHOD_B  /* 一様乱数平均 */
    {
      int i,j;
      double sum;
      for(i=0;i<num_ransuu;i++)
      {
	sum=0.0;
	for(j=0;j<12;j++)
	  sum += (double)random()/(double)RAND_MAX;
	ran1=(sum-6.0)*hensa+heikin;    /* 乱数 */

	dist=fabs(ran1-heikin)/hensa;  /* σで規格化した平均からの距離 */
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;
      }
    }
#endif

    /* 算出した割合の表示 */    
    printf("±1σ:%7.5f ±2σ:%7.5f ±3σ:%7.5f\n",(double)hist[0]/(double)num_ransuu,(double)hist[1]/(double)num_ransuu,(double)hist[2]/(double)num_ransuu);
  }
}

/* エラー時の処理 */
void error1(char *message)
{
  printf("%s\n",message);
  exit(1);
}
