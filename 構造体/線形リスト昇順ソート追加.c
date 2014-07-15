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
void insert(double);

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

    /* inserthead() を呼出し、データを昇順に追加する */
    insert(data);

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

          
/* insert(): データを昇順でリストに追加する関数 */
void insert(double val)
{  
  struct cell *ptr, *p, *q;
  
  /**** 入力データを格納する新しいセルの生成 ****/
  /* データ領域の確保 */
  ptr=(struct cell *)malloc(sizeof(struct cell));

  /* 値の代入 */
  ptr->num=val;
  ptr->next=NULL;

  /* 一時ポインタ(データ監視用)を以下のように設定する

     +----------+     +--------+     +--------+
     | listhead | --> | DATA 1 | --> | DATA 2 | --> .....
     +----------+     +--------+     +--------+
                          ↑             ↑
                          p              q

     新規データ値と q の指すデータ値と大小比較する。
     ptr->num < q->num, または q = NULL ならば、
     新規データは p と q の間に挿入される。
     そうでないなら、p と q を一つずつ進める。


     ***** 特例1 ****
     listhead=NULL の場合がある。
     この場合には q の設定は不可能。

     +----------+
     | listhead | --> NULL
     +----------+      ↑
                       p

     ***** 処置 *****
     新規データをリストの先頭に追加して処理終了。

     +----------+     +----------+
     | listhead | --> | 新規DATA | --> NULL
     +----------+     +----------+      ↑
                                        p

     ***** 特例2 *****
     新規データ値が p のデータ値より小さい場合がある。

     ***** 処置 *****
     ptr->num < p->num ならば、新規データは先頭に挿入される。

     +----------+     +----------+     +--------+
     | listhead | --> | 新規DATA | --> | DATA 1 | --> .....
     +----------+     +----------+     +--------+
                                           ↑
                                           p
  */

  /* 特例1の処理 */
  if (listhead==NULL) {
    listhead=ptr;
    return;
  }

  /* p, q の設定 */
  p=listhead;
  q=listhead->next;

  /* 特例2の処理 */
  if (ptr->num < p->num) {
    listhead=ptr;
    ptr->next=p;
    return;
  }

  while(1) {

    /* 条件式 ( q==NULL || ptr->num < q->num ) について
       q = NULLなら、q->num が存在しないので、後半部の比較で
       セグメントエラーを起こしそうであるが、C言語の場合には
       q==NULL で条件を満たせば後半部の比較を行わないので、
       これで問題ない。

       気持悪い人は、下記のように2段階にわけて書いてもよい。

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
