#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* �\���̂̒�` */
struct cell {
  double num;
  struct cell *next;
};

/* ���X�g�̐擪���w���|�C���^�� Global �Œ�` */
struct cell *listhead = NULL;

/* �֐��̃v���g�^�C�v�錾 */
void inserthead(double);

int main(void)
{
  double data;
  char ans[10];
  struct cell *q;

  /* �f�[�^�}���m�F */
  printf("\n\n�}������f�[�^���L��܂���? (yes/no)--->" );
  scanf("%s", ans);

  /* �}���f�[�^������ꍇ�Ƀ��[�v���� */
  while (strcmp(ans,"yes")==0){

    /* �}���f�[�^�l���� */
    printf("�f�[�^����͂��ĉ�����.--->");
    scanf("%lf", &data);

    /* inserthead() ���ďo���A�f�[�^��擪�ɒǉ����� */
    inserthead(data);

    /* ���݂̃��X�g���e��\�� */
    q=listhead;
    while(q!=NULL) {
      printf(" ->%f",q->num);
      q=q->next;
    }

    /* �ǉ��f�[�^�m�F */
    printf("\n\n�}������f�[�^���L��܂���? (yes/no)--->" );
    scanf("%s", ans);
  }

  /* �����I�� */
  printf("�}��������I�����܂�.\n\n");
  return(0);
}

/* inserthead(): �f�[�^�����X�g�̐擪�ɒǉ�����֐� */
void inserthead(double val)
{  
  struct cell *q;

  /* �f�[�^�̈�̊m�� */
  q=(struct cell *)malloc(sizeof(struct cell));

  /* �l�̑�� */
  q-> num=val;

  /* ���̃f�[�^�ւ̃|�C���^����� */
  q-> next=listhead;

  /* �擪�|�C���^��ύX */
  listhead=q;

  /* �I�� */
  return;
 }
