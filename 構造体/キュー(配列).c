#include <stdio.h>
#include <stdlib.h>

/* リングバッファサイズの宣言 */
#define MAX_RING_BUFFER 10

/* 関数のプロトタイプ宣言 */
void enq(void);
double deq(void);
void end(void);
void printq(void);

/* リングバッファの宣言 */
double ring_buff[MAX_RING_BUFFER];
int head;
int tail;

int main(void)
{
  int flag = 1;
  char ans[10];

  /* 始めはデータがないので head = tail = 0 を代入 */
  head = tail = 0;

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

  /* enq する値の入力 */
  printf("追加する値を入力して下さい--->");
  scanf("%lf", &val);

  /* 新しいデータを tail 位置に入力し，tail ポインタを1増加する */
  ring_buff[tail] = val;
  tail = (tail + 1) % MAX_RING_BUFFER;

  /* リングバッファをフルに使い切った場合には，head ポインタを1増加しておく */
  if (head == tail)
    head = (head + 1) % MAX_RING_BUFFER;
}

/**********************/
/* deq 操作を行う関数 */
/**********************/
double deq(void)
{
  double val;

  void end();

  /* 先頭と最後尾が一致していないならばデータが存在する */
  if (head != tail) {

    /* とりあえず val 変数にいれておく */
    val = ring_buff[head];

    /* リストの先頭を移動 */
    head = (head + 1) % MAX_RING_BUFFER;

    /* deq により出た値を返す */
    return(val);
  }

  /* head != tail ならデータなし -> メッセージを出して強制終了 */
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
  int i;

  printf("キュー内のデータ: ");

  /* head よりも後ろに tail がある場合 (通常モード) */
  if (head <= tail)
    for (i=head; i<tail; i++)
      printf(" ->%f", ring_buff[i]);

  /* head よりも前に tail がある場合 (リング循環モード) */
  else
    for (i=head; i<tail+MAX_RING_BUFFER; i++)
      printf(" ->%f", ring_buff[i%MAX_RING_BUFFER]);

  printf("\n");
}
