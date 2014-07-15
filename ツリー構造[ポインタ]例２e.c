#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOJI "a b + c d e / - *"
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

typedef struct  node  *tree;

char  BUFFER[BUFSIZE];

tree  stack[MAX_NEST];
int   sp;

char  debug=0;

/*  スタックを初期化  */
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

/*  文字列を後置記法で解釈して、構造をツリーにして返す  */
tree  post2tree(char  *p)
{
  tree  t;

  for (;*p;p++) {

    if  (debug) printf("*p=%c\n",*p);

    if  (*p==' ') continue;//空白を飛ばす

    t=new(*p);
    if  (t==NULL) {
      /*  新しいノードを作るのが失敗した  */
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
          /*  有るべき左右の要素が無い  */
          dispError(ER_SYNTAX);
          return  NULL;
        }
      default   :
		  ;
    }
    if  (!push(t))  {
      /*  スタックオーバーフロー  */
      dispError(ER_STACK);
      return  NULL;
    }
  }

  t=pop();

  if  (pop()) {
    /*  スタックにまだ要素が残っている  */
    dispError(ER_SYNTAX);
    return  NULL;
  }
  return  t;
}

/*  ツリーのノードを訪れる処理(単に表示のみ)  */
void  visit(tree  t)
{
  printf("%c",t->record);
}

/*  ツリーを中間記法で走査  */
void  trav_infix(tree t)
{

	if (t){
		trav_infix(t->left);
		visit(t);
		trav_infix(t->right);
	}
}

/*  ツリーを前置記法で走査  */
void  trav_prefix(tree  t)
{
  if  (t) {
    visit(t);
    trav_prefix(t->left);
    trav_prefix(t->right);
  }
}

/*ツリーを後置記法で走査*/
void  trav_post(tree  t)
{
  if  (t) {
	  	trav_post(t->left);
    trav_post(t->right);
		    visit(t);
  }
}

/*  ツリーをfree()  */
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

   init_stack();
	p=MOJI;
	{
      t=post2tree(p);
      if  (t) {
        printf("prefix notation ===>");
        trav_prefix(t);
        printf("\n");

        printf("infix notation ====>");
        trav_infix(t);
        printf("\n");

		printf("postfix notation ==>");
		trav_post(t);
		printf("\n");

        killtree(t);
		printf("***** END OF TRAVERSAL *****");
      }
    }
}

