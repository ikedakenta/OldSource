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
void insert(double);

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

    /* inserthead() ���ďo���A�f�[�^�������ɒǉ����� */
    insert(data);

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

          
/* insert(): �f�[�^�������Ń��X�g�ɒǉ�����֐� */
void insert(double val)
{  
  struct cell *ptr, *p, *q;
  
  /**** ���̓f�[�^���i�[����V�����Z���̐��� ****/
  /* �f�[�^�̈�̊m�� */
  ptr=(struct cell *)malloc(sizeof(struct cell));

  /* �l�̑�� */
  ptr->num=val;
  ptr->next=NULL;

  /* �ꎞ�|�C���^(�f�[�^�Ď��p)���ȉ��̂悤�ɐݒ肷��

     +----------+     +--------+     +--------+
     | listhead | --> | DATA 1 | --> | DATA 2 | --> .....
     +----------+     +--------+     +--------+
                          ��             ��
                          p              q

     �V�K�f�[�^�l�� q �̎w���f�[�^�l�Ƒ召��r����B
     ptr->num < q->num, �܂��� q = NULL �Ȃ�΁A
     �V�K�f�[�^�� p �� q �̊Ԃɑ}�������B
     �����łȂ��Ȃ�Ap �� q ������i�߂�B


     ***** ����1 ****
     listhead=NULL �̏ꍇ������B
     ���̏ꍇ�ɂ� q �̐ݒ�͕s�\�B

     +----------+
     | listhead | --> NULL
     +----------+      ��
                       p

     ***** ���u *****
     �V�K�f�[�^�����X�g�̐擪�ɒǉ����ď����I���B

     +----------+     +----------+
     | listhead | --> | �V�KDATA | --> NULL
     +----------+     +----------+      ��
                                        p

     ***** ����2 *****
     �V�K�f�[�^�l�� p �̃f�[�^�l��菬�����ꍇ������B

     ***** ���u *****
     ptr->num < p->num �Ȃ�΁A�V�K�f�[�^�͐擪�ɑ}�������B

     +----------+     +----------+     +--------+
     | listhead | --> | �V�KDATA | --> | DATA 1 | --> .....
     +----------+     +----------+     +--------+
                                           ��
                                           p
  */

  /* ����1�̏��� */
  if (listhead==NULL) {
    listhead=ptr;
    return;
  }

  /* p, q �̐ݒ� */
  p=listhead;
  q=listhead->next;

  /* ����2�̏��� */
  if (ptr->num < p->num) {
    listhead=ptr;
    ptr->next=p;
    return;
  }

  while(1) {

    /* ������ ( q==NULL || ptr->num < q->num ) �ɂ���
       q = NULL�Ȃ�Aq->num �����݂��Ȃ��̂ŁA�㔼���̔�r��
       �Z�O�����g�G���[���N���������ł��邪�AC����̏ꍇ�ɂ�
       q==NULL �ŏ����𖞂����Ό㔼���̔�r���s��Ȃ��̂ŁA
       ����Ŗ��Ȃ��B

       �C�������l�́A���L�̂悤��2�i�K�ɂ킯�ď����Ă��悢�B

       if (q==NULL) {
         p->next=ptr;
	 ptr->next=q;
         return;
       }
       if (ptr->num < q->num) {
         p->next=ptr;
	 ptr->next=q;
         return;
       }       
    */
    if (q==NULL || ptr->num < q->num) {
      p->next=ptr;
      ptr->next=q;
      return;
    }
    p=q;
    q=q->next;
  }
}
