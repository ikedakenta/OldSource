#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 構造体の定義 */
struct node {
  char sym[10];               /* 節点の文字列を保存する変数 */
  struct node *left, *right;  /* 「子」へのポインタ: 2分木なので2つ必要 */
};
  
/* typedef 宣言して楽しよう */
typedef struct node NODE;

/* 関数のプロトタイプ宣言 */
void pre_traversal( NODE * );
void in_traversal( NODE * );
void post_traversal( NODE * );

int main(void)
{
  int i;

  /* typedef 宣言したので，「NODE」変数 = 「struct node」変数 となる */
  NODE *root, *p[9];

  /* メモリの動的確保 */
  for ( i=0; i<9; i++ )
    p[i] = ( NODE * )malloc( sizeof( NODE ) );

  root = p[0];

  /* データ構造の設定 */
  strcpy( p[0]->sym, "*" );
  p[0]->left  = p[1];
  p[0]->right = p[2];

  strcpy( p[1]->sym, "+" );
  p[1]->left  = p[3];
  p[1]->right = p[4];

  strcpy( p[2]->sym, "-" );
  p[2]->left  = p[5];
  p[2]->right = p[6];

  strcpy( p[3]->sym, "a" );
  p[3]->left  = NULL;
  p[3]->right = NULL;

  strcpy( p[4]->sym, "b" );
  p[4]->left  = NULL;
  p[4]->right = NULL;

  strcpy( p[5]->sym, "c" );
  p[5]->left  = NULL;
  p[5]->right = NULL;

  strcpy( p[6]->sym, "/" );
  p[6]->left  = p[7];
  p[6]->right = p[8];

  strcpy( p[7]->sym, "d" );
  p[7]->left  = NULL;
  p[7]->right = NULL;

  strcpy( p[8]->sym, "e" );
  p[8]->left  = NULL;
  p[8]->right = NULL;

  /* 前置記法表示 ＝ 前順探索 */
  printf( "prefix notation ===> " );
  pre_traversal( root );
  printf( "\n" );

  /* 中置記法表示 ＝ 間順探索 */
  printf( "infix notation ====> " );
  in_traversal( root );
  printf( "\n" );

  /* 後置記法表示 ＝ 後順探索 */
  printf( "postfix notation ==> " );
  post_traversal( root );
  printf( "\n" );

  printf( "***** END OF TRAVERSAL *****\n" );

  return 0;
}

/* 前順探索によって値を表示する関数 */
void pre_traversal( NODE *p )
{
  /* 前順では，自分自身を探索した後で左側の子，右側の子を探索する
     p = NULL の場合には何もしないで終了する */
  if ( p != NULL ) {
    printf( "%s ", p->sym );
    pre_traversal( p->left );
    pre_traversal( p->right );
  }
}

/* 間順探索によって値を表示する関数 */
void in_traversal( NODE *p )
{
  /* 間順では，左側の子を探索後自分自身を探索し，最後に右側の子を探索する
     p = NULL の場合には何もしないで終了する */
  if ( p != NULL ) {
    in_traversal( p->left );
    printf( "%s ", p->sym );
    in_traversal( p->right );
  }
}

/* 後順探索によって値を表示する関数 */
void post_traversal( NODE *p )
{
  /* 後順では，左側の子，右側の子を探索した後で自分自身を探索する
     p = NULL の場合には何もしないで終了する */
  if ( p != NULL ) {
    post_traversal( p->left );
    post_traversal( p->right );
    printf( "%s ", p->sym );
  }
}
