/*===================================
�w�b�_���
���X�g�Ǘ�
�쐬���@�S���Q�U��
�쐬�ҁ@�r�c�@����
------------------------------------*/

#ifndef cell_list
#define cell_list 
/* ���X�g�̒�` */
struct cell{
	int num;		/*�v�f*/
	struct cell *next;	/*���̗v�f�ւ̃|�C���^*/
};
typedef struct cell LIST;
#endif

/*�v���g�^�C�v*/
void insert_list(LIST *start,int val);
void view_list(LIST *start);
