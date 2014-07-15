#include <stdio.h>

/* 関数のプロトタイプ宣言 */
int power_recursive( int, int );

int main( void )
{
  int n, m;

  /* 値の入力 */
  printf( "二つの自然数を入力してください ==> " );
  scanf( "%d %d", &n, &m );

  /* 計算と同時に結果表示 */
  printf( "%d の %d 乗は %d です．\n", n, m, power_recursive( n, m ) );

  /* 終了 */
  return( 0 );
}


/* 再帰呼出しを用いた累乗演算関数 */
int power_recursive( int n, int m )
{
  /* m = 0 ならば 1 を返す(終了条件) */
  if ( m == 0 )
    return( 1 );

  /* それ以外なら再帰的呼出しを行う */
  else
    return( n * power_recursive( n, m-1 ) );
}
