#include <stdio.h>
#include <stdlib.h>

/* �֐��̃v���g�^�C�v�錾 */
void push(void);
int pop(void);
void end(void);

/* �\���� cell �̐錾 */
struct cell {
  int num;
  struct cell *next;
};

/* �X�^�b�N(���X�g�j�̐擪���w���|�C���^
   �n�߂͋�Ȃ̂� NULL ������Ă��� */
struct cell *stack = NULL;


int main(void)
{
  int flag = 1;
  char ans[10];

  /* end �����s�����܂Ōp�� */
  while(flag) {

    /* ����̓��� */
    printf("�����I�����ĉ����� (push/pop/end)--->");
    scanf("%s", ans);

    /* ���삲�Ƃ̊֐����ďo */
    if (strcmp(ans, "push") == 0)
      push();

    else if (strcmp(ans, "pop") == 0)
      printf("pop���ꂽ�l��%d�ł��D\n", pop());

    else if (strcmp(ans, "end") == 0) {
      end();
      flag = 0;
    }
    else
      printf("���삪������܂���\n");
  }
  return(0);
}


/***********************/
/* push ������s���֐� */
/***********************/
void push(void)
{
  int val;
  struct cell *q;

  /* push ����l�̓��� */
  printf("push����l����͂��ĉ�����--->");
  scanf("%d", &val);

  /* �V�K�f�[�^�Ȃ̂ŁC�\���̗̈�𓮓I�m�� */
  q = (struct cell *)malloc(sizeof(struct cell));

  /* �\���̂ɐV�����f�[�^����͂��C���X�g�̐擪�ɂ����Ă��� */
  q->num = val;
  q->next = stack;
  stack = q;
}


/**********************/
/* pop ������s���֐� */
/**********************/
int pop(void)
{
  int val;
  struct cell *q;

  /* ��x�擪�|�C���^�� q �ɑ�� */
  q = stack;

  /* q �� NULL �łȂ���΃f�[�^�����݂��� */
  if (q!=NULL) {

    /* �Ƃ肠���� val �ϐ��ɂ���Ă��� */
    val = q->num;

    /* ���X�g�̐擪��ύX */
    stack = q->next;

    /* �s�v�ɂȂ����\���̂�j�� */
    free(q);

    /* pop �ɂ��o���l��Ԃ� */
    return(val);
  }

  /* q �� NULL �Ȃ�΃f�[�^�Ȃ� -> ���b�Z�[�W���o���ċ����I�� */
  else {
    printf("�X�^�b�N�Ƀf�[�^������܂���D\n");
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
