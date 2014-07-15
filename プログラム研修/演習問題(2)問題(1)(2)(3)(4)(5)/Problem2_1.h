/*===================================
２００６年度プログラム研修
演習課題（２）問題３（１）（２）（３）（４）（５）
作成日　４月２５日
作成者　池田　健太
------------------------------------*/
#define LIST_MAX 30
#define RANDOM_MAX 35

/* 関数のプロトタイプ宣言 */
void create_random_num(int size,int *random_num);

char char_temp[32];		/*文字列入力として受け取るため*/
int num_temp=0;			/*数値一時保管*/
int random_num[LIST_MAX];
int i=0,no=0;
