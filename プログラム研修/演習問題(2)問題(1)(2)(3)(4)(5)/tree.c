/*===================================
ツリー構造
作成日　４月２５日
作成者　池田　健太
------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include "tree.h"


/*=======================================
葉ノードの生成
---------------------------------------*/
TREE *make_leaf(int val) {
	TREE *t = (TREE *)malloc(sizeof(TREE));
	t->left = NULL;
	t->right = NULL;
	t->key = val;
	return t;
}

/*=======================================
データの挿入
---------------------------------------*/
TREE *insert(TREE **t,int val){
	if(*t == NULL){
		*t = make_leaf(val);
		return *t;
	}else if(val > (*t)->key){
		insert(&((*t)->right),val);
	}else{
		insert(&((*t)->left),val);
	}
}

/*=======================================
ツリー探索
---------------------------------------*/
TREE *search(TREE *t,int val){
	TREE *p;
	if(t == NULL){
		return t;
	}
	if(val == t->key){
		p = t;
	}else if(val > t->key){
		p = search(t->right,val);
	}else{
		p = search(t->left,val);
	}
	return p;
}

/*=======================================
ツリー表示(昇順表示)
---------------------------------------*/
void print_tree(TREE *t){
	if(t != NULL){
		print_tree(t->left);
		printf("%d\n",t->key);
		print_tree(t->right);
	}
}


/*=======================================
ツリー表示(階層構造付)
---------------------------------------*/
void view_tree(TREE *t){
	static int depth = 0;
	if(t != NULL){
		if(t->left != NULL){
			depth++;
			view_tree(t->left);
			depth--;
		}
		printf("%*c%d\n",10 * depth,' ',t->key);
		if(t->right != NULL){
			depth++;
			view_tree(t->right);
			depth--;
		}
	}
}
