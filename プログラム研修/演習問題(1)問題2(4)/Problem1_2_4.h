/*===================================
２００６年度プログラム研修
演習課題（１）問題２（４）
作成者　池田　健太
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define LIST_MAX 20

struct cell{
	int num;		/*要素*/
	struct cell* next;	/*次の要素へのポインタ*/
};
typedef struct cell LIST;

void insert(LIST *start,int val);
void view_list(LIST *start,int no);
void create_random_num(int size,int *random_num);

char char_temp[32];		/*文字列入力として受け取るため*/
int num_temp=0;			/*数値一時保管*/
int random_num[LIST_MAX];
int i=0,no=0;

