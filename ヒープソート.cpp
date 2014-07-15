#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	void hsort_d(double a[], int n);
	double x[20];
	char gomi[20];
	printf("ランダムに２０の数字を発生させます。\n→Enter Key");
	gets(gomi);
	for(int i=0;i<20;i++){
		x[i]=rand()*20;
		printf("x[%d]=%.0f\n",i,x[i]);
	}
	printf("ソートテスト開始します。\n→Enter Key");
	gets(gomi);
	hsort_d(x,20);
	for(i=0;i<20;i++){
		printf("x[%d]=%.0f\n",i,x[i]);
	}
	printf("ソートしました。");
	gets(gomi);//処理中断
}

void hsort_d(double a[], int n)
{
	int j, k;
	double *alast, *pi, *pj, x;
	
	if(n <= 1)
	{
		fprintf(stderr, "Error : n <= 1  in hsort_d()\n");
		return;
	}
	
	alast = a + n - 1;
	for(k = n / 2; k >= 1; k--)
	{
		x = *(pi = a + (j = k) - 1);
		while((j *= 2) < n)
		{
			pj = a + j - 1;
			if(pj < alast && *pj < *(pj + 1))	pj++;
			j = pj - a + 1;
			if(x >= *pj)	break;
			*pi = *pj;
			pi = pj;
		}
		*pi = x;
	}
	while(n > 0)
	{
		x = *alast;
		*alast = *a;
		alast = (pi = a) + (--n) - (j = 1);
		while((j *= 2) <= n)
		{
			pj = a + j - 1;
			if(pj < alast && *pj < *(pj + 1))	pj++;
			j = pj - a + 1;
			if(x >= *pj)	break;
			*pi = *pj;
			pi = pj;
		}
		*pi = x;
	}
}