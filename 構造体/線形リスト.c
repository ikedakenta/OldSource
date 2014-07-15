#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 構造体の定義 */
struct cell {
  double num;
  struct cell *next;
};

/* リストの先頭を指すポインタを Global で定義 */
struct cell *listhead = NULL;

/* 関数のプロトタイプ宣言 */
void inserthead(double);

int main(void)
{
  double data;
  char ans[10];
  struct cell *q;

  /* データ挿入確認 */
  printf("\n\n挿入するデータが有りますか? (yes/no)--->" );
  scanf("%s", ans);

  /* 挿入データがある場合にループする */
  while (strcmp(ans,"yes")==0){

    /* 挿入データ値入力 */
    printf("データを入力して下さい.--->");
    scanf("%lf", &data);

    /* inserthead() を呼出し、データを先頭に追加する */
    inserthead(data);

    /* 現在のリスト内容を表示 */
    q=listhead;
    while(q!=NULL) {
      printf(" ->%f",q->num);
      q=q->next;
    }

    /* 追加データ確認 */
    printf("\n\n挿入するデータが有りますか? (yes/no)--->" );
    scanf("%s", ans);
  }

  /* 処理終了 */
  printf("挿入操作を終了します.\n\n");
  return(0);
}

/* inserthead(): データをリストの先頭に追加する関数 */
void inserthead(double val)
{  
  struct cell *q;

  /* データ領域の確保 */
  q=(struct cell *)malloc(sizeof(struct cell));

  /* 値の代入 */
  q-> num=val;

  /* 次のデータへのポインタを入力 */
  q-> next=listhead;

  /* 先頭ポインタを変更 */
  listhead=q;

  /* 終了 */
  return;
 }
