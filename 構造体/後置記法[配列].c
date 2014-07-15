#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define	   STACK_SIZE  100	   /* �X�^�b�N�̑傫�� */

double stack[STACK_SIZE];	   /* �X�^�b�N�̒�` */
int n=0;			   /* �|�C���^ */


void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void push(double x)
{
  if (n >= STACK_SIZE)
    error("�X�^�b�N�I�[�o�[�t���[\n");
  stack[n++] = x;}

double pop()
{
  if (n <= 0)
    error("�X�^�b�N�A���_�[�t���[\n");
  return  stack[--n];
}

double empty()
{
  return  n == 0;
}

main()
{
  int c;
  double    x, a, b;
	    while((c=getchar()) !=EOF)
    {
      if(isdigit(c))
	{
	  ungetc(c,stdin);
	  if(scanf("%lf",&x) !=1)
	    {
	      printf("ERROR\n");
	      exit(-1);
	    }
	  push(x);
	}
      else {
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
	    printf("������%f�ł��B\n", pop());
		exit(1);
		break;
	    case ' ':
			break;
		case '\t':
			printf("�v���O�����I��\n");
			exit(1);
	    default:
			printf("�s������\n�v���O�������I�����܂�\n");
			exit(1);
			break;
}}}}
