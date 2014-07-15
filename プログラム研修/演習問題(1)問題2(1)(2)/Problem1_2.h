/*===================================
２００６年度プログラム研修
演習課題（１）問題２（１）（２）
作成者　池田　健太
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct cell{
	int num;		/*要素*/
	struct cell *next;	/*次の要素へのポインタ*/
};
typedef struct cell LIST;


char char_temp[32];		/*文字列入力として受け取るため*/
int num_temp;			/*数値一時保管*/