#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256
#define MAX_NEST 15

#define TRUE  1
#define FALSE 0

#define ER_SYNTAX 1
#define ER_STACK  2
#define ER_MEMORY 3

struct  node  {
	char  record;
	struct  node  *left,*right;
};

FILE *fp;
typedef struct  node  *tree;

char  BUFFER[BUFSIZE];

tree  stack[MAX_NEST];
int   sp;

char  debug=0;

/*  �X�^�b�N��������  */
void  init_stack()
{
	sp=0;
}

int push(tree t)
{
	if  (debug) printf("push!\n");

	if (sp>MAX_NEST) return FALSE;

	stack[sp++]=t;
	return  TRUE;
}

tree  pop()
{
	if  (debug) printf("pop!\n");

	if  (sp==0) return  NULL;
	return  stack[--sp];
}

/*  x��v�f�Ƃ���t(���E�̎}��NULL���w���Ă���m�[�h)����� */
tree  new(char  x)
{
	tree  t=(tree)malloc(sizeof(struct  node));
	if  (t) {
		t->record=x;
		t->right=t->left=NULL;
	}
	return  t;
}

void  dispError(int error)
{
	switch  (error) {
case  ER_SYNTAX :
	printf("  Syntax error!\n");
	break;
case  ER_STACK  :
	printf("  Stack overflow!\n");
	break;
case  ER_MEMORY :
	printf("  Memory not enough!\n");
	break;
default         :
	printf("  Error! Code: %d\n",error);
	}
}

/*  ���������u�L�@�ŉ��߂��āA�\�����c���[�ɂ��ĕԂ�  */
tree  post2tree(char  *p)
{
	tree  t;

	for (;*p;p++) {

		if  (debug) printf("*p=%c\n",*p);

		if  (*p==' ') continue;

		t=new(*p);
		if  (t==NULL) {
			/*  �V�����m�[�h�����̂����s����  */
			dispError(ER_MEMORY);
			return  NULL;
		}

		switch(*p)  {
case  '+' :
case  '-' :
case  '*' :
case  '/' :
	t->right=pop();
	t->left =pop();
	if  (t->right==NULL||t->left==NULL) {
		/*  �L��ׂ����E�̗v�f������  */
		dispError(ER_SYNTAX);
		return  NULL;
	}
default   :
	;
		}
		if  (!push(t))  {
			/*  �X�^�b�N�I�[�o�[�t���[  */
			dispError(ER_STACK);
			return  NULL;
		}
	}

	t=pop();

	if  (pop()) {
		/*  �X�^�b�N�ɂ܂��v�f���c���Ă���  */
		dispError(ER_SYNTAX);
		return  NULL;
	}
	return  t;
}

/*  �c���[�̃m�[�h��K��鏈��(�P�ɕ\���̂�)  */
void  visit(tree  t)
{

	if(t->record=='a'){
		fprintf(fp,"15.5");
	}
	else if(t->record=='b'){
		fprintf(fp,"5.2");
	}
	else if(t->record=='c'){
		fprintf(fp,"7.1");
	}
	else if(t->record=='d'){
		fprintf(fp,"8.2");
	}
	else if(t->record=='e'){
		fprintf(fp,"2");
	}
	else{
		fprintf(fp,"%c",t->record);
	}
}
/*�c���[����u�L�@�ő���*/
void  trav_post(tree  t)
{
	if  (t) {
		trav_post(t->left);
		trav_post(t->right);
		visit(t);
		fprintf(fp," ");
	}
}

/*  �c���[����u�L�@�ő�������free()  */
void  killtree(tree t)
{
	if  (t) {
		killtree(t->left);
		killtree(t->right);
		free(t);
	}
}

int main()
{
	char  *p;
	tree  t;
	fp=fopen("file_post","a");
	init_stack();
	p="a b + c d e / - *";
	t=post2tree(p);
	if  (t) {
		trav_post(t);
		killtree(t);
		fprintf(fp,"\n");
		fclose(fp);
	}
}

