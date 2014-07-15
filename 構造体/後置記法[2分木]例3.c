#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* �\���̂̒�` */
struct node {
  char sym[10];               /* �ߓ_�̕������ۑ�����ϐ� */
  struct node *left, *right;  /* �u�q�v�ւ̃|�C���^: 2���؂Ȃ̂�2�K�v */
};
  
/* typedef �錾���Ċy���悤 */
typedef struct node NODE;

/* �t�@�C���|�C���^�̒�` */
FILE *fp;

/* �֐��̃v���g�^�C�v�錾 */
void post_traversal( NODE * );

int main(void)
{
  int i;

  /* typedef �錾�����̂ŁC�uNODE�v�ϐ� = �ustruct node�v�ϐ� �ƂȂ� */
  NODE *root, *p[9];

  /* �������̓��I�m�� */
  for ( i=0; i<9; i++ )
    p[i] = ( NODE * )malloc( sizeof( NODE ) );

  root = p[0];

  /* �f�[�^�\���̐ݒ� */
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

  /* �t�@�C���I�[�v�� */
  if ( ( fp = fopen( "file_post", "w" ) ) == NULL ) {
    printf( "Cannot open file_post.\n" );
    exit( 1 );
  }

  /* ��u�L�@�\�� �� �㏇�T�� */
  post_traversal( root );
  fprintf( fp, "\n" );

  /* �t�@�C���N���[�Y */
  fclose( fp );

  return 0;
}

/* �㏇�T���ɂ���Ēl��\������֐� */
void post_traversal( NODE *p )
{
  /* �㏇�ł́C�����̎q�C�E���̎q��T��������Ŏ������g��T������
     p = NULL �̏ꍇ�ɂ͉������Ȃ��ŏI������ */
  if ( p != NULL ) {
    post_traversal( p->left );
    post_traversal( p->right );
    fprintf( fp, "%s ", p->sym );
  }
}
