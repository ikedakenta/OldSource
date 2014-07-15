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

/* ファイルポインタの定義 */
FILE *fp;

/* 関数のプロトタイプ宣言 */
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

  strcpy( p[3]->sym, "15.5" );
  p[3]->left  = NULL;
  p[3]->right = NULL;

  strcpy( p[4]->sym, "5.2" );
  p[4]->left  = NULL;
  p[4]->right = NULL;

  strcpy( p[5]->sym, "7.1" );
  p[5]->left  = NULL;
  p[5]->right = NULL;

  strcpy( p[6]->sym, "/" );
  p[6]->left  = p[7];
  p[6]->right = p[8];

  strcpy( p[7]->sym, "8.2" );
  p[7]->left  = NULL;
  p[7]->right = NULL;

  strcpy( p[8]->sym, "2" );
  p[8]->left  = NULL;
  p[8]->right = NULL;

  /* ファイルオープン */
  if ( ( fp = fopen( "file_post", "w" ) ) == NULL ) {
    printf( "Cannot open file_post.\n" );
    exit( 1 );
  }

  /* 後置記法表示 ＝ 後順探索 */
  post_traversal( root );
  fprintf( fp, "\n" );

  /* ファイルクローズ */
  fclose( fp );

  return 0;
}

/* 後順探索によって値を表示する関数 */
void post_traversal( NODE *p )
{
  /* 後順では，左側の子，右側の子を探索した後で自分自身を探索する
     p = NULL の場合には何もしないで終了する */
  if ( p != NULL ) {
    post_traversal( p->left );
    post_traversal( p->right );
    fprintf( fp, "%s ", p->sym );
  }
}
