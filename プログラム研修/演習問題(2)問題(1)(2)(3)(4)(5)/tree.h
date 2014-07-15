/*===================================
ツリー構造ヘッダファイル
作成日　４月２５日
作成者　池田　健太
------------------------------------*/

/* 木のデータ構造 */
struct node {
	int key;
	struct node *left,*right;
	
};
typedef struct node TREE;

/*プロトタイプ*/
TREE *make_leaf(int val);
TREE *insert(TREE **t, int val);
TREE *search(TREE *t, int val);
void print_tree(TREE *t);
void view_tree(TREE *t);

