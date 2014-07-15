#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* �֐��̃v���g�^�C�v�錾 */
void   push( double );
double pop( void );

/* �\���̒�` */
typedef struct cell {
  double element;
  struct cell *next;
} CELL, *LIST;

/* �X�^�b�N�̐擪���w���|�C���^ // �����l�� NULL �����Ă��� */
LIST stack = NULL;

/* �������� main �֐� */
int main( void )
{
  int c;
  double x, op1, op2;

  /* �Ƃ肠�����W�����͂���1�����ǂݏo�� */
  while ( ( c=getchar() ) != EOF ) {

    /* �������ꂪ������������ ungetc�{scanf �œǂݒ����� push ���� */
    if ( isdigit( c ) ) {
      ungetc( c, stdin );
      scanf( "%lf", &x );
      push( x );
    }

    /* �����ȊO�̏ꍇ�ɂ͉��Z�q�ɂ���ĕ��򂳂��� */
    else{
      switch( c ) {

      /* �����Z�̏ꍇ */
      case '+':
	op2=pop();
	op1=pop();
	push( op1+op2 );
	break;

       /* �����Z�̏ꍇ */
       case '-':
	 op2=pop();
	 op1=pop();
	 push( op1-op2 );  
	 break;

       /* �|���Z�̏ꍇ */
       case '*':
	 op2=pop();
	 op1=pop();
	 push( op1*op2 );
	 break;

       /* ����Z�̏ꍇ */
       case '/':
	 op2=pop();
	 op1=pop();
	 if ( op2 != 0.0 )
	   push( op1/op2 );
	 else {
	   printf( "��ł̊��Z�G���[�ł��D\n" );
	   exit( 1 );
	 }
	 break;

       /* ���s�L���̏ꍇ */
       case '\n':
	 /* �X�^�b�N�Ƀf�[�^��������c���Ă��Ȃ���ΐ��� */
	 if( stack->next == NULL ) {
	   printf( "������ %f �ł��D\n\n", pop() );
	   return( 0 );
	 }
	 else {
	   printf( "���̓G���[�ł��D\n" );
	   exit( 1 );
	 }
	 break;
      }
    }
  }
  return( 0 );
}

/* push �����s����֐� */
void push( double val )
{
  /* �V�����Z���𐶐����邽�߂̃|�C���^ */
  LIST p;

  /* �Z������ */
  p = ( LIST )malloc( sizeof( CELL ) );

  /* �f�[�^����� */
  p->element = val;

  /* ���ɂ��郊�X�g�̐擪�֐ڑ� */
  p->next = stack;
  stack = p;
}

/* pop �����s����֐� */
double pop()
{  
  /* �Z�����폜���邽�߂̈ꎞ�|�C���^ */
  LIST p;

  /* �l���ꎞ�I�ɕۑ����邽�߂̕ϐ� */
  double val;

  /* �X�^�b�N�̃`�F�b�N */
  if ( stack == NULL) {
    printf( "�G���[:�X�^�b�N����ł��D\n" );
    exit( 1 );
  }

  /* �擪�Z���̒l��ۑ� */
  val = stack->element;

  /* ���X�g�̐擪�A�h���X���擾 */
  p = stack;

  /* ���X�g����擪�Z����r���i2�Ԗڂ̃Z�����X�^�b�N�|�C���^�ɐڑ��j */
  stack = stack->next;

  /* ���X�g�̐擪�Z�������ۂɃ���������폜 */
  free ( ( void * )p );

  /* �擪�Z���ɓ����Ă����l��Ԃ� */
  return( val );
}
