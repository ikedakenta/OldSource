/*===================================
ヘッダ情報
リスト管理
作成日　４月２６日
作成者　池田　健太
------------------------------------*/

#ifndef cell_list
#define cell_list 
/* リストの定義 */
struct cell{
	int num;		/*要素*/
	struct cell *next;	/*次の要素へのポインタ*/
};
typedef struct cell LIST;
#endif

/*プロトタイプ*/
void insert_list(LIST *start,int val);
void view_list(LIST *start);
