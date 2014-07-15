#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define	   STACK_SIZE  100	   /* スタックの大きさ */

double stack[STACK_SIZE];	   /* スタックの定義 */
int n=0;			   /* ポインタ */


void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void push(double x)
{
  if (n >= STACK_SIZE)
    error("スタックオーバーフロー\n");
  stack[n++] = x;}

double pop()
{
  if (n <= 0)
    error("スタックアンダーフロー\n");
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
	    printf("答えは%fです。\n", pop());
		exit(1);
		break;
	    case ' ':
			break;
		case '\t':
			printf("プログラム終了\n");
			exit(1);
	    default:
			printf("不正入力\nプログラムを終了します\n");
			exit(1);
			break;
}}}}
