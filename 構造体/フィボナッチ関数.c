#include <stdio.h>

/* 関数のプロトタイプ宣言 */
int fibonacci_recursive( int );

int main( void )
{
  int n;

  /* 値の入力 */
  printf( "自然数を入力してください ==> " );
  scanf( "%d", &n );

  /* 計算と同時に結果表示 */
  printf( "%d のfibonacci数は %d です．\n", n, fibonacci_recursive( n ) );

  /* 終了 */
  return( 0 );
}

/* 再帰呼出しを用いたfibonacci数演算関数 */
int fibonacci_recursive( int n )
{
  /* n=0, n=1 ならば 1 を返す(終了条件) */
  if ( n < 2 )
    return( 1 );

  /* それ以外なら再帰的呼出しを行う */
  else
    return( fibonacci_recursive( n-1 ) + fibonacci_recursive( n-2 ) );
}
