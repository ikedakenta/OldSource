#include <stdio.h>
#include <stdlib.h>

/* 関数のプロトタイプ宣言 */
void enq(void);
double deq(void);
void end(void);
void printq(void);

/* 構造体 cell の宣言 */
struct cell {
  double num;
  struct cell *next;
};

/* リストの先頭と末端を指すポインタ */
struct cell *listhead, *listtail;


int main(void)
{
  int flag = 1;
  char ans[10];

  /* 始めはデータがないので NULL を代入 */
  listhead = NULL;

  /* end が実行されるまで継続 */
  while(flag) {

    /* 操作の入力 */
    printf("操作を選択して下さい (enq/deq/end)--->");
    scanf("%s", ans);

    /* 操作ごとの関数を呼出 */
    if (strcmp(ans, "enq") == 0) {
      enq();
      printq();
    }
    else if (strcmp(ans, "deq") == 0) {
      printf("%fはキューから削除されました．\n", deq());
      printq();
    }
    else if (strcmp(ans, "end") == 0) {
      end();
      flag = 0;
    }
    else
      printf("操作が分かりません\n");
  }
  return(0);
}


/**********************/
/* enq 操作を行う関数 */
/**********************/
void enq(void)
{
  double val;
  struct cell *q;

  /* enq する値の入力 */
  printf("追加する値を入力して下さい--->");
  scanf("%lf", &val);

  /* 新規データなので，構造体領域を動的確保 */
  q = (struct cell *)malloc(sizeof(struct cell));

  /* 構造体に新しいデータを入力し，最後尾へ接続する */
  q->num = val;
  q->next = NULL;

  /* listhead == NULL なら，新規データ */
  if (listhead == NULL)
    listhead = listtail = q;

  /* それ以外ならば，新規データを最後尾に接続し，listtail を次へ移動する */
  else {
    listtail->next = q;
    listtail = q;
  }
}


/**********************/
/* deq 操作を行う関数 */
/**********************/
double deq(void)
{
  double val;
  struct cell *q;

  /* 一度先頭ポインタを q に代入 */
  q = listhead;

  /* q が NULL でなければデータが存在する */
  if (q != NULL) {

    /* とりあえず val 変数にいれておく */
    val = q->num;

    /* リストの先頭を変更 */
    listhead = q->next;

    /* 不要になった構造体を破棄 */
    free(q);

    /* deq により出た値を返す */
    return(val);
  }

  /* q が NULL ならばデータなし -> メッセージを出して強制終了 */
  else {
    printf("キューにデータがありません．\n");
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


/**************************************/
/* printq: キューの中身を表示する関数 */
/**************************************/
void printq(void)
{
  struct cell *q;

  q = listhead;
  printf("キュー内のデータ: ");
  while (q != NULL) {
    printf(" ->%f", q->num);
    q = q->next;
  }
  printf("\n");
}
