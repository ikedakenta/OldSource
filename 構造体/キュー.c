#include <stdio.h>
#include <stdlib.h>

/* �֐��̃v���g�^�C�v�錾 */
void enq(void);
double deq(void);
void end(void);
void printq(void);

/* �\���� cell �̐錾 */
struct cell {
  double num;
  struct cell *next;
};

/* ���X�g�̐擪�Ɩ��[���w���|�C���^ */
struct cell *listhead, *listtail;


int main(void)
{
  int flag = 1;
  char ans[10];

  /* �n�߂̓f�[�^���Ȃ��̂� NULL ���� */
  listhead = NULL;

  /* end �����s�����܂Ōp�� */
  while(flag) {

    /* ����̓��� */
    printf("�����I�����ĉ����� (enq/deq/end)--->");
    scanf("%s", ans);

    /* ���삲�Ƃ̊֐����ďo */
    if (strcmp(ans, "enq") == 0) {
      enq();
      printq();
    }
    else if (strcmp(ans, "deq") == 0) {
      printf("%f�̓L���[����폜����܂����D\n", deq());
      printq();
    }
    else if (strcmp(ans, "end") == 0) {
      end();
      flag = 0;
    }
    else
      printf("���삪������܂���\n");
  }
  return(0);
}


/**********************/
/* enq ������s���֐� */
/**********************/
void enq(void)
{
  double val;
  struct cell *q;

  /* enq ����l�̓��� */
  printf("�ǉ�����l����͂��ĉ�����--->");
  scanf("%lf", &val);

  /* �V�K�f�[�^�Ȃ̂ŁC�\���̗̈�𓮓I�m�� */
  q = (struct cell *)malloc(sizeof(struct cell));

  /* �\���̂ɐV�����f�[�^����͂��C�Ō���֐ڑ����� */
  q->num = val;
  q->next = NULL;

  /* listhead == NULL �Ȃ�C�V�K�f�[�^ */
  if (listhead == NULL)
    listhead = listtail = q;

  /* ����ȊO�Ȃ�΁C�V�K�f�[�^���Ō���ɐڑ����Clisttail �����ֈړ����� */
  else {
    listtail->next = q;
    listtail = q;
  }
}


/**********************/
/* deq ������s���֐� */
/**********************/
double deq(void)
{
  double val;
  struct cell *q;

  /* ��x�擪�|�C���^�� q �ɑ�� */
  q = listhead;

  /* q �� NULL �łȂ���΃f�[�^�����݂��� */
  if (q != NULL) {

    /* �Ƃ肠���� val �ϐ��ɂ���Ă��� */
    val = q->num;

    /* ���X�g�̐擪��ύX */
    listhead = q->next;

    /* �s�v�ɂȂ����\���̂�j�� */
    free(q);

    /* deq �ɂ��o���l��Ԃ� */
    return(val);
  }

  /* q �� NULL �Ȃ�΃f�[�^�Ȃ� -> ���b�Z�[�W���o���ċ����I�� */
  else {
    printf("�L���[�Ƀf�[�^������܂���D\n");
    end();
    exit(1);
  }
}


/**********************/
/* end ������s���֐� */
/**********************/
void end(void)
{
  printf("�v���O�������I�����܂��D\n");
}


/**************************************/
/* printq: �L���[�̒��g��\������֐� */
/**************************************/
void printq(void)
{
  struct cell *q;

  q = listhead;
  printf("�L���[���̃f�[�^: ");
  while (q != NULL) {
    printf(" ->%f", q->num);
    q = q->next;
  }
  printf("\n");
}
