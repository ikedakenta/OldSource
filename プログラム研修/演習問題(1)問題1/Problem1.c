/*===================================
２００６年度プログラム研修
演習課題（１）問題１
作成日　４月２０日
作成者　池田　健太
------------------------------------*/

#include "Problem1.h"
void calc_bin(int num);
void error(int no);

int main(void){
	char *p;/*文字列走査用*/
	p = char_temp;
	printf("数値を入力して下さい。\n-->");
	gets(char_temp);/*文字列として入力受付*/	
	
	/* 文字列ならエラー */
	while(*p != NULL){
		if(isalpha((*p)))
		{
			error(2);
		}
		p++;
	}
	
	/*文字列→数値変換*/
	num_temp	=	atoi(char_temp);
	
	/*数値でも異常値の入力はエラー*/
	if(num_temp > 65535 || num_temp < 0){
		error(1);
		return(0);
	}
	
	/*結果表示*/
	printf("入力された数値%dは２進数で次のようになります。\n",num_temp);
	calc_bin(num_temp);/*２進数計算*/
	
	printf("\n何かキーを押すとプログラムを終了します。\n");
	gets(char_temp);
	return(0);
}

/*====================================
２進数変換関数
------------------------------------*/
void calc_bin(int num){
	int i,count=0;
	int int_temp[16];
	
	for(i=0;i<16;i++){/*0で埋める*/
		int_temp[i]  =  0;
	}
	
	for(i=0;i<16;i++){/*２除算による変換作業*/
		int_temp[i]	=	(num % 2);
		num = num / 2;
		count++;
		if((num / 2) == 0){/*最後の桁まで計算が進みこれ以上割れなくなったら*/
			continue;/*continueする事で　計算が終わってからも0を入れていく*/
		}
	}
	
	for(i=count-1;i >= 0;i--){/*結果の表示*/
		printf("%d",int_temp[i]);
	}
}
/*====================================
エラー表示
------------------------------------*/
void error(int error_ID){
	switch (error_ID){
	case 1:
		printf("エラー：範囲外の数値が入力されました。\n入力は０～65535の数値にして下さい。");
		exit(1);
	case 2:
		printf("エラー：文字列が入力されました。");
		exit(1);
	default:
		exit(1);
	}
}