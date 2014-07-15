/*	-------------プログラミング演習Ⅱ課題 4-----------
開発環境	Windows2000	MicrosoftVisualC++6.0	池田　健太	*/
#include <stdio.h>/*標準ヘッダ*/
#include <stdlib.h>/**/
#include <string.h>/**/
#define DATA 5000/*扱うデータの大きさ*/
#define TXT "data.txt" /*読み込む数列ファイルの場所*/

int *intsort(int a[],int n0,int nn);
void swap(int *pa,int*pb);

void main(void){
		  /*---------------------------------変数定義---------------------------------------------*/
				int i,j,data[DATA];
				char gomi[10];/*gets(f)のときに使うだけのゴミ変数*/
				FILE *fp;/*ファイル入出力操作用ポインタ*/
				/*---------------------------ファイル読み込み----------------------------------------*/
				printf("「TXT」から数列を読み込みます\n");
				fp=fopen(TXT,"r");
				i=0;
				for (;;){
					if(fscanf(fp,"%d",&data[i])==EOF)break;/*ファイルから一行読んでdata[]に入れる、ファイルの終了でbreak*/
					i++;
				}
				fclose(fp);
				/*[Quiksort]呼び出し*/
				intsort(data,0,DATA-1);
				/*-------------------------------------結果のディスプレイへの出力--------------------------------------*/
				for (i=0;i<=DATA-1;i++){
					printf("%d ",data[i]);
				}
				/*------------------------出力結果をファイルへエクスポート---------------------------*/
				fp=fopen("kekka.txt","w");
				for(i=0;i<=DATA-1;i++){
					fprintf(fp,"%d\n",data[i]);
				}
				fclose(fp);
				printf("[QuikSort] により数列を並び替えた結果を\n「kekka.txt」に出力しました。\n");
}
/*------------------------------------Quicksortプログラム-------------------------------------*/
int *intsort(int a[],int n0,int nn)
{
				int t;
				int i,j;
				if(nn-n0==1){/*比べる配列要素が隣のとき*/
					if(a[n0]<a[nn])swap(&a[n0],&a[nn]);
				}
				else if(nn-n0>1){/*比べる配列要素がまだ離れている時*/
					t=a[(n0+nn)/2];
					i=n0-1;
					j=nn+1;
					while(i<j){
						while(a[++i]>t);
						while(a[--j]<t);
						if(i<j)swap(&a[i],&a[j]);
						else if(i==j){
							intsort(a,n0,i-1);
							intsort(a,i+1,nn);
						}
						else{
							intsort(a,n0,j);
							intsort(a,i,nn);
						}
					}
				}
				return a;
}
/*-------------データの交換部分のプログラム---------------------------*/
void swap(int *pa,int *pb){
				int temp;
				temp=*pa;
				*pa=*pb;
				*pb=temp;
}
