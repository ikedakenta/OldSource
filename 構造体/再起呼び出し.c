#include <stdio.h>

/* �֐��̃v���g�^�C�v�錾 */
int power_recursive( int, int );

int main( void )
{
  int n, m;

  /* �l�̓��� */
  printf( "��̎��R������͂��Ă������� ==> " );
  scanf( "%d %d", &n, &m );

  /* �v�Z�Ɠ����Ɍ��ʕ\�� */
  printf( "%d �� %d ��� %d �ł��D\n", n, m, power_recursive( n, m ) );

  /* �I�� */
  return( 0 );
}


/* �ċA�ďo����p�����ݏ扉�Z�֐� */
int power_recursive( int n, int m )
{
  /* m = 0 �Ȃ�� 1 ��Ԃ�(�I������) */
  if ( m == 0 )
    return( 1 );

  /* ����ȊO�Ȃ�ċA�I�ďo�����s�� */
  else
    return( n * power_recursive( n, m-1 ) );
}
