/*===================================
マインスイーパ
作成日　４月２７日
作成者　池田　健太
------------------------------------*/

#define MINE_TABLE_HIGHT 5 /*テーブルの高さ*/
#define MINE_TABLE_WIDTH 5	/*テーブルの幅*/
#define DIFFICULT 1			/*ゲームの難易度 1:EASY 2:NORMAL 3:HARD */
#define BOM 1
#define CLOSE 0
#define OPEN 1
#define FLAG 2

/*マインスイーパのマス目の構造体*/
struct map{
	int table_statement;/*テーブルの状態 0:開かれていない 1:開かれている 2:印をつけている*/
	int table_bom;/*爆弾があるかどうか 1:ある 0:ない*/
	int table_val;/*数字の値 0～ */
};
typedef struct map MINE_TABLE;

/*プロトタイプ*/
void init_mine_table(MINE_TABLE **table);
MINE_TABLE ** getMemory(int size_x,int size_y);
void first_open(MINE_TABLE **table);
void open_mine_table(MINE_TABLE **table,int x,int y);
void open_mine_table_execute(MINE_TABLE **table,int x,int y);
void check_flag_mine_table(MINE_TABLE **table,int x,int y);
int get_opend_count(MINE_TABLE **table);
int isOpend(MINE_TABLE **table,int x,int y);
int isBomd(MINE_TABLE **table,int x,int y);
int isClear(MINE_TABLE **table);
void view_mine_table(MINE_TABLE **table,int debug);
void gameover(void);
void gameclear(void);
