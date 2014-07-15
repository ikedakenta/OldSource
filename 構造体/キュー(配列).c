#include <stdio.h>
#include <stdlib.h>

/* �����O�o�b�t�@�T�C�Y�̐錾 */
#define MAX_RING_BUFFER 10

/* �֐��̃v���g�^�C�v�錾 */
void enq(void);
double deq(void);
void end(void);
void printq(void);

/* �����O�o�b�t�@�̐錾 */
double ring_buff[MAX_RING_BUFFER];
int head;
int tail;

int main(void)
{
  int flag = 1;
  char ans[10];

  /* �n�߂̓f�[�^���Ȃ��̂� head = tail = 0 ���� */
  head = tail = 0;

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

  /* enq ����l�̓��� */
  printf("�ǉ�����l����͂��ĉ�����--->");
  scanf("%lf", &val);

  /* �V�����f�[�^�� tail �ʒu�ɓ��͂��Ctail �|�C���^��1�������� */
  ring_buff[tail] = val;
  tail = (tail + 1) % MAX_RING_BUFFER;

  /* �����O�o�b�t�@���t���Ɏg���؂����ꍇ�ɂ́Chead �|�C���^��1�������Ă��� */
  if (head == tail)
    head = (head + 1) % MAX_RING_BUFFER;
}

/**********************/
/* deq ������s���֐� */
/**********************/
double deq(void)
{
  double val;

  void end();

  /* �擪�ƍŌ������v���Ă��Ȃ��Ȃ�΃f�[�^�����݂��� */
  if (head != tail) {

    /* �Ƃ肠���� val �ϐ��ɂ���Ă��� */
    val = ring_buff[head];

    /* ���X�g�̐擪���ړ� */
    head = (head + 1) % MAX_RING_BUFFER;

    /* deq �ɂ��o���l��Ԃ� */
    return(val);
  }

  /* head != tail �Ȃ�f�[�^�Ȃ� -> ���b�Z�[�W���o���ċ����I�� */
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
  int i;

  printf("�L���[���̃f�[�^: ");

  /* head �������� tail ������ꍇ (�ʏ탂�[�h) */
  if (head <= tail)
    for (i=head; i<tail; i++)
      printf(" ->%f", ring_buff[i]);

  /* head �����O�� tail ������ꍇ (�����O�z���[�h) */
  else
    for (i=head; i<tail+MAX_RING_BUFFER; i++)
      printf(" ->%f", ring_buff[i%MAX_RING_BUFFER]);

  printf("\n");
}
