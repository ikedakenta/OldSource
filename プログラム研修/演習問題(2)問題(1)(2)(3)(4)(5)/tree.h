/*===================================
�c���[�\���w�b�_�t�@�C��
�쐬���@�S���Q�T��
�쐬�ҁ@�r�c�@����
------------------------------------*/

/* �؂̃f�[�^�\�� */
struct node {
	int key;
	struct node *left,*right;
	
};
typedef struct node TREE;

/*�v���g�^�C�v*/
TREE *make_leaf(int val);
TREE *insert(TREE **t, int val);
TREE *search(TREE *t, int val);
void print_tree(TREE *t);
void view_tree(TREE *t);

