#include <stdio.h>
#include <stdlib.h>

/* 関数のプロトタイプ宣言 */
void push(void);
int pop(void);
void end(void);

/* 構造体 cell の宣言 */
struct cell {
  int num;
  struct cell *next;
};

/* スタック(リスト）の先頭を指すポインタ
   始めは空なので NULL をいれておく */
struct cell *stack = NULL;


int main(void)
{
  int flag = 1;
  char ans[10];

  /* end が実行されるまで継続 */
  while(flag) {

    /* 操作の入力 */
    printf("操作を選択して下さい (push/pop/end)--->");
    scanf("%s", ans);

    /* 操作ごとの関数を呼出 */
    if (strcmp(ans, "push") == 0)
      push();

    else if (strcmp(ans, "pop") == 0)
      printf("popされた値は%dです．\n", pop());

    else if (strcmp(ans, "end") == 0) {
      end();
      flag = 0;
    }
    else
      printf("操作が分かりません\n");
  }
  return(0);
}


/***********************/
/* push 操作を行う関数 */
/***********************/
void push(void)
{
  int val;
  struct cell *q;

  /* push する値の入力 */
  printf("pushする値を入力して下さい--->");
  scanf("%d", &val);

  /* 新規データなので，構造体領域を動的確保 */
  q = (struct cell *)malloc(sizeof(struct cell));

  /* 構造体に新しいデータを入力し，リストの先頭にもってくる */
  q->num = val;
  q->next = stack;
  stack = q;
}


/**********************/
/* pop 操作を行う関数 */
/**********************/
int pop(void)
{
  int val;
  struct cell *q;

  /* 一度先頭ポインタを q に代入 */
  q = stack;

  /* q が NULL でなければデータが存在する */
  if (q!=NULL) {

    /* とりあえず val 変数にいれておく */
    val = q->num;

    /* リストの先頭を変更 */
    stack = q->next;

    /* 不要になった構造体を破棄 */
    free(q);

    /* pop により出た値を返す */
    return(val);
  }

  /* q が NULL ならばデータなし -> メッセージを出して強制終了 */
  else {
    printf("スタックにデータがありません．\n");
    end();
    exit(1);
  }
}

/**********************/
/* end 操作を行う関数 */
/**********************/
void end(void)
{
  printf("プログラムを終了します．\n");
}
