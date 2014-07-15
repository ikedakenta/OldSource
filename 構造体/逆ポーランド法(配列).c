#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define	   STACK_SIZE  100	   /* �X�^�b�N�̑傫�� */

long double stack[STACK_SIZE];	   /* �X�^�b�N�̒�` */
int n=0;			   /* �|�C���^ */


void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void   push(long x)
{
  if (n >= STACK_SIZE)
    error("�X�^�b�N�I�[�o�[�t���[\n");
  stack[n++] = x;
}

long double pop()
{
  if (n <= 0)
    error("�X�^�b�N�A���_�[�t���[\n");
  return  stack[--n];
}

int empty()
{
  return  n == 0;
}

main()
{
  double c;
  long double    x, a, b;
printf("�t�|�[�����h�@�ɂ��v�Z���s���܂��B\n�������X�y�[�X�ŋ�؂艉�Z�q�������ăX�y�[�X�ŋ�؂���͂��Ă��������B\n"
	  "�Ȃ��v���O�������I������ɂ�e����͂��Ă��������B\n");
  while (  (c = getchar() ) != EOF) {
    if (isdigit(c)) {
      //ungetc(c, stdin);
		if(isalnum(c)){
        scanf("%lf", &x);
		push(x);}
	} else {
          switch (c) {
            case '+':
	        b = pop(); a = pop();
       	        push(a + b);
	        break;
	    case '-':
		b = pop(); a = pop();
		push(a - b);
		break;
	    case '*':
		b = pop(); a = pop();
		push(a * b);
		break;
	    case '/':
		b = pop(); a = pop();
		push(a / b);
		break;
	    case '\n':
		if (! empty())
		    printf("������%ld�ł�\n", pop());
		printf("�t�|�[�����h�@�ɂ��v�Z���s���܂��B\n�������X�y�[�X�ŋ�؂艉�Z�q�������ăX�y�[�X�ŋ�؂���͂��Ă��������B\n"
		  "�Ȃ��v���O�������I������ɂ�e����͂��Ă��������B\n");
		n=0;
		break;
	    case ' ':
	    case '\t':
			exit(1);
		break;
		case 'e':
			printf("�v���O�����I��\n");
			exit(1);
	    default:
		printf("�s���ȕ���������܂����B\n");
		printf("���͂��Ȃ����ĉ������B\n");
		while ((c = getchar()) != EOF && c != '\n');
		break;
	  }
	}
  }
  exit(1);
}
