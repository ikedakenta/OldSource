/*===================================
�}�C���X�C�[�p
�쐬�ҁ@�r�c�@����
------------------------------------*/

//#define MINE_TABLE_HIGHT 5 /*�e�[�u���̍���*/
//#define MINE_TABLE_WIDTH 5	/*�e�[�u���̕�*/
#define DIFFICULT 1			/*�f�t�H���g�ł̃Q�[���̓�Փx 1:EASY 2:NORMAL 3:HARD */
#define DIFFICULT_EASY 1		/*��ՓxEASY*/
#define DIFFICULT_NORMAL 2	/*��ՓxNORMAL*/
#define DIFFICULT_HARD 3	/*��ՓxHARD*/

#define EASY_TABLE_SIZE 10	/*��ՓxEASY�ł̃e�[�u���̑傫���@�c��*/
#define NORMAL_TABLE_SIZE 15/*��ՓxNORMAL�ł̃e�[�u���̑傫���c��*/
#define HARD_TABLE_SIZE 30	/*��ՓxHARD�ł̃e�[�u���̑傫���@�c��*/
#define BOM 1				/*���e�t���O*/
#define CLOSE 0				/*�J����Ă��Ȃ����*/
#define OPEN 1				/*�J����Ă�����*/
#define FLAG 2				/*������Ă�����*/

/*�}�C���X�C�[�p�̃}�X�ڂ̍\����*/
struct map{
	int table_statement;/*�e�[�u���̏�� 0:�J����Ă��Ȃ� 1:�J����Ă��� 2:������Ă���*/
	int table_bom;/*���e�����邩�ǂ��� 1:���� 0:�Ȃ�*/
	int table_val;/*�����̒l 0�` */
};
typedef struct map MINE_TABLE;

/*�v���g�^�C�v*/
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