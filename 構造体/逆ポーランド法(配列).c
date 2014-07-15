#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define	   STACK_SIZE  100	   /* スタックの大きさ */

long double stack[STACK_SIZE];	   /* スタックの定義 */
int n=0;			   /* ポインタ */


void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void   push(long x)
{
  if (n >= STACK_SIZE)
    error("スタックオーバーフロー\n");
  stack[n++] = x;
}

long double pop()
{
  if (n <= 0)
    error("スタックアンダーフロー\n");
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
printf("逆ポーランド法による計算を行います。\n数字をスペースで区切り演算子も続けてスペースで区切り入力してください。\n"
	  "なおプログラムを終了するにはeを入力してください。\n");
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
		    printf("答えは%ldです\n", pop());
		printf("逆ポーランド法による計算を行います。\n数字をスペースで区切り演算子も続けてスペースで区切り入力してください。\n"
		  "なおプログラムを終了するにはeを入力してください。\n");
		n=0;
		break;
	    case ' ':
	    case '\t':
			exit(1);
		break;
		case 'e':
			printf("プログラム終了\n");
			exit(1);
	    default:
		printf("不正な文字がありました。\n");
		printf("入力しなおして下さい。\n");
		while ((c = getchar()) != EOF && c != '\n');
		break;
	  }
	}
  }
  exit(1);
}
