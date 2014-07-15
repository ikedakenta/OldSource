/*===================================
マインスイーパ
作成者　池田　健太
------------------------------------*/

//#define MINE_TABLE_HIGHT 5 /*テーブルの高さ*/
//#define MINE_TABLE_WIDTH 5	/*テーブルの幅*/
#define DIFFICULT 1			/*デフォルトでのゲームの難易度 1:EASY 2:NORMAL 3:HARD */
#define DIFFICULT_EASY 1		/*難易度EASY*/
#define DIFFICULT_NORMAL 2	/*難易度NORMAL*/
#define DIFFICULT_HARD 3	/*難易度HARD*/

#define EASY_TABLE_SIZE 10	/*難易度EASYでのテーブルの大きさ　縦横*/
#define NORMAL_TABLE_SIZE 15/*難易度NORMALでのテーブルの大きさ縦横*/
#define HARD_TABLE_SIZE 30	/*難易度HARDでのテーブルの大きさ　縦横*/
#define BOM 1				/*爆弾フラグ*/
#define CLOSE 0				/*開かれていない状態*/
#define OPEN 1				/*開かれている状態*/
#define FLAG 2				/*印をつけている状態*/

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

int MINE_TABLE_WIDTH;
int MINE_TABLE_HIGHT;