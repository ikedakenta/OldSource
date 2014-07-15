/*===================================
�c���[�\��
�쐬���@�S���Q�T��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include "tree.h"


/*=======================================
�t�m�[�h�̐���
---------------------------------------*/
TREE *make_leaf(int val) {
	TREE *t = (TREE *)malloc(sizeof(TREE));
	t->left = NULL;
	t->right = NULL;
	t->key = val;
	return t;
}

/*=======================================
�f�[�^�̑}��
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
�c���[�T��
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
�c���[�\��(�����\��)
---------------------------------------*/
void print_tree(TREE *t){
	if(t != NULL){
		print_tree(t->left);
		printf("%d\n",t->key);
		print_tree(t->right);
	}
}


/*=======================================
�c���[�\��(�K�w�\���t)
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
