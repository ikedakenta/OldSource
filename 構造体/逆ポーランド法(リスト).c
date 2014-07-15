#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* 関数のプロトタイプ宣言 */
void   push( double );
double pop( void );

/* 構造体定義 */
typedef struct cell {
  double element;
  struct cell *next;
} CELL, *LIST;

/* スタックの先頭を指すポインタ // 初期値に NULL を入れておく */
LIST stack = NULL;

/* ここから main 関数 */
int main( void )
{
  int c;
  double x, op1, op2;

  /* とりあえず標準入力から1文字読み出す */
  while ( ( c=getchar() ) != EOF ) {

    /* もしそれが数字だったら ungetc＋scanf で読み直して push する */
    if ( isdigit( c ) ) {
      ungetc( c, stdin );
      scanf( "%lf", &x );
      push( x );
    }

    /* 数字以外の場合には演算子によって分岐させる */
    else{
      switch( c ) {

      /* 足し算の場合 */
      case '+':
	op2=pop();
	op1=pop();
	push( op1+op2 );
	break;

       /* 引き算の場合 */
       case '-':
	 op2=pop();
	 op1=pop();
	 push( op1-op2 );  
	 break;

       /* 掛け算の場合 */
       case '*':
	 op2=pop();
	 op1=pop();
	 push( op1*op2 );
	 break;

       /* 割り算の場合 */
       case '/':
	 op2=pop();
	 op1=pop();
	 if ( op2 != 0.0 )
	   push( op1/op2 );
	 else {
	   printf( "零での割算エラーです．\n" );
	   exit( 1 );
	 }
	 break;

       /* 改行記号の場合 */
       case '\n':
	 /* スタックにデータが一つしか残っていなければ正常 */
	 if( stack->next == NULL ) {
	   printf( "答えは %f です．\n\n", pop() );
	   return( 0 );
	 }
	 else {
	   printf( "入力エラーです．\n" );
	   exit( 1 );
	 }
	 break;
      }
    }
  }
  return( 0 );
}

/* push を実行する関数 */
void push( double val )
{
  /* 新しいセルを生成するためのポインタ */
  LIST p;

  /* セル生成 */
  p = ( LIST )malloc( sizeof( CELL ) );

  /* データを入力 */
  p->element = val;

  /* 既にあるリストの先頭へ接続 */
  p->next = stack;
  stack = p;
}

/* pop を実行する関数 */
double pop()
{  
  /* セルを削除するための一時ポインタ */
  LIST p;

  /* 値を一時的に保存するための変数 */
  double val;

  /* スタックのチェック */
  if ( stack == NULL) {
    printf( "エラー:スタックが空です．\n" );
    exit( 1 );
  }

  /* 先頭セルの値を保存 */
  val = stack->element;

  /* リストの先頭アドレスを取得 */
  p = stack;

  /* リストから先頭セルを排除（2番目のセルをスタックポインタに接続） */
  stack = stack->next;

  /* リストの先頭セルを実際にメモリから削除 */
  free ( ( void * )p );

  /* 先頭セルに入っていた値を返す */
  return( val );
}
