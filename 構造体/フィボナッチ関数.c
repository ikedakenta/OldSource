#include <stdio.h>

/* �֐��̃v���g�^�C�v�錾 */
int fibonacci_recursive( int );

int main( void )
{
  int n;

  /* �l�̓��� */
  printf( "���R������͂��Ă������� ==> " );
  scanf( "%d", &n );

  /* �v�Z�Ɠ����Ɍ��ʕ\�� */
  printf( "%d ��fibonacci���� %d �ł��D\n", n, fibonacci_recursive( n ) );

  /* �I�� */
  return( 0 );
}

/* �ċA�ďo����p����fibonacci�����Z�֐� */
int fibonacci_recursive( int n )
{
  /* n=0, n=1 �Ȃ�� 1 ��Ԃ�(�I������) */
  if ( n < 2 )
    return( 1 );

  /* ����ȊO�Ȃ�ċA�I�ďo�����s�� */
  else
    return( fibonacci_recursive( n-1 ) + fibonacci_recursive( n-2 ) );
}
