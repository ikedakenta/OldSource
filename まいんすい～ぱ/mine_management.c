/*===================================
�}�C���X�C�[�p
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include "mine_management.h"


/*=======================================
�}�X�ڂ̃������̈�m��
---------------------------------------*/
MINE_TABLE ** getMemory(int size_x,int size_y){
	MINE_TABLE ** table;
	int i;
	
	/*�e�[�u���T�C�Y��ۊ�*/
	MINE_TABLE_WIDTH = size_x;
	MINE_TABLE_HIGHT = size_y;

	/*2�����z��̂܂��͐擪����|�C���^�^�Ŋm��*/
	table = (MINE_TABLE **)malloc(sizeof(MINE_TABLE *) * (size_y + 2));
	/*�m�ۂ����|�C���^��ɂ��ꂼ��z����m�ۂ��ĂȂ�*/
	for(i = 0;i < size_x + 2;i++){
		*(table + i) = (MINE_TABLE *)malloc(sizeof(MINE_TABLE) * (size_x + 2));
	}
	return table;/*�m�ۂ����̈��Ԃ�*/
}

/*=======================================
�}�X�ڂ̏�����
---------------------------------------*/
void init_mine_table(MINE_TABLE **table){
	int i,j;
	int temp_num = 0;
	
	srand( (unsigned)time( NULL ) );/*���ݎ������g�������W�F�l���[�^��������*/
	
	/*�}�X�ڂ̏�Ԃ�������*/
	for(i = 0;i < MINE_TABLE_HIGHT + 2;i++){
		for(j = 0;j < MINE_TABLE_WIDTH + 2;j++){
			table[i][j].table_statement = CLOSE;/*�J����Ă��Ȃ���Ԃ��Z�b�g*/
			table[i][j].table_val = 0;/*�����ɂO���Z�b�g*/
			table[i][j].table_bom = 0;/*���e�Ȃ����Z�b�g*/
		}
	}
	/*�}�X�ڂɔ��e��z�u����*/
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
		/*1�`�@��Փx���l�𐶐� 
		DIFFICULT 1:EASY 2:NORMAL 3:HARD
		DIFFICULT��1�̂Ƃ��͂P�`�U�̗����𐶐�����
		DIFFICULT��2�̂Ƃ��͂P�`�V�́AHARD�̂Ƃ��͂P�`�W�̗����𐶐�����B
			*/
			temp_num = ((rand() * RAND_MAX) % (DIFFICULT + 5)) + 1;
			if(temp_num > 5){/*�U�ȏ�Ȃ�*/
				table[i][j].table_bom = BOM;/* ���e��z�u */ 
			}
		}
	}
	
	/*�}�X�ڂɐ������Z�b�g����*/
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
			if(table[i][j].table_bom == BOM){/*���e�Ȃ�*/
				continue;
			}
			/*���͂̔��e�̐������g�̐������ɑ����ăZ�b�g*/
			table[i][j].table_val += 
				table[i-1][j-1].table_bom + table[i][j-1].table_bom + table[i+1][j-1].table_bom +
				table[i-1][j].table_bom +							table[i+1][j].table_bom +
				table[i-1][j+1].table_bom + table[i][j+1].table_bom + table[i+1][j+1].table_bom;
		}
	}
	/*�Q�[���J�n���ɍŏ��Ɉ�񂾂��ǂ����J���Ă���*/
	first_open(table);
}

/*=======================================
�Q�[���J�n���ŏ��Ɉ��J������
---------------------------------------*/
void first_open(MINE_TABLE **table){
	int x,y;
	
	while(1){
		x = ((rand() * RAND_MAX) % MINE_TABLE_WIDTH) + 1;/*1�`MINE_TABLE_WIDTH�܂ł̗����𓾂�*/
		y = ((rand() * RAND_MAX) % MINE_TABLE_HIGHT) + 1;/*1�`MINE_TABLE_HIGHT�܂ł̗����𓾂�*/
		
		/*���e�łȂ��������I�[�v������*/
		if(table[x][y].table_bom != BOM){
			open_mine_table(table,x,y);
			return;
		}
	}
}

/*=======================================
�}�X�ڂ��J��
---------------------------------------*/
void open_mine_table(MINE_TABLE **table,int x,int y){
	int i,j;
	/*�w�肳�ꂽ���W���z��͈͂��͂ݏo���Ă����珈�����Ȃ�*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}
	
	table[x][y].table_statement = OPEN;/* OPEN ��Ԃɂ��� */
	if( table[x][y].table_val == 0 && table[x][y].table_bom != BOM){
		for( i=-1; i<=1; i++ ){
			for( j=-1; j<=1; j++ ){
				if(table[x + i][y + j].table_statement == CLOSE){
					open_mine_table(table,x+i,y+j);
				}
			}
		}
	}
}

/*=======================================
���ɊJ���ꂽ�}�X�ڎ��ӂ��J��
�@�\�F
�����̓������}�X�ڂ��J���Ă��āA
����ɗאڂ���n���Ɋ��Ɉ�����Ă���Ƃ���
�}�X�ڎ��ӂ���x�ɊJ������
---------------------------------------*/
void open_mine_table_execute(MINE_TABLE **table,int x,int y){
	int i,j;
	int bomz;
	/*�w�肳�ꂽ���W���z��͈͂��͂ݏo���Ă����珈�����Ȃ�*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}
	if(isBomd(table,x,y) == 0){
		bomz = 0;
		for( i=-1; i<=1; i++ ){
			for( j=-1; j<=1; j++ ){
				if(table[x + i][y + j].table_bom == BOM){
					bomz += 1;
				}
			}
		}
		/*�����̐����Ǝ��ӂ̔��e�̐�����v���Ă����*/
		if(bomz == table[x][y].table_val){
			for( i=-1; i<=1; i++ ){
				for( j=-1; j<=1; j++ ){
					if(table[x + i][y + j].table_bom != BOM){
						table[x][y].table_statement = OPEN;/* OPEN ��Ԃɂ��� */
					}
				}
			}
		}
	}
}

/*=======================================
���}�X�J���ꂽ�����ׂ�
�Ԃ�l�F���݂̊J���ꂽ�}�X�ڂ̐�
---------------------------------------*/
int get_opend_count(MINE_TABLE **table){
	int i,j,count = 0;
	
	/*�}�X�ڂ𒲂�OPEN��������J�E���g���P���₷*/
	for(i = 1;i<MINE_TABLE_HIGHT + 1;i++){
		for(j = 1;j<MINE_TABLE_WIDTH + 1;j++){
			if(table[i][j].table_statement == OPEN ){
				count += 1;
			}else if(table[i][j].table_statement == FLAG && table[i][j].table_bom == BOM){
				count += 1;
			}
		}
	}
	//printf("�N���A�[�܂Ō� %d �}�X\n",(MINE_TABLE_WIDTH * MINE_TABLE_HIGHT) - count);
	return count;
}


/*=======================================
�}�X�ڂɈ������
---------------------------------------*/
void check_flag_mine_table(MINE_TABLE **table,int x,int y){
	/*�w�肳�ꂽ���W���z��͈͂��͂ݏo���Ă����珈�����Ȃ�*/
	if( x < 1 || x > MINE_TABLE_WIDTH || y < 1 || y > MINE_TABLE_HIGHT ){
		return;
	}

	if(table[x][y].table_statement ==CLOSE){/*���Ă�����*/
		table[x][y].table_statement = FLAG;/*�������*/
	}else if(table[x][y].table_statement == FLAG){/*�󂪂��Ă�����*/
		table[x][y].table_statement = CLOSE;/*��̉���*/
	}
}

/*=======================================
�w�肵���}�X�ڂ��J����Ă��邩�ǂ������ׂ�
�Ԃ�l�F�^�U
---------------------------------------*/
int isOpend(MINE_TABLE **table,int x,int y){
	
	/*OPEN���ǂ������ׂ�*/
	if(table[x][y].table_statement == OPEN){
		return 1;
	}
	return 0;
}

/*=======================================
�w�肵���}�X�ڂɔ��e�����邩�ǂ������ׂ�
�Ԃ�l�F�^�U
---------------------------------------*/
int isBomd(MINE_TABLE **table,int x,int y){
	
	/*���e�����邩�ǂ������ׂ�*/
	if(table[x][y].table_bom == BOM){
		return 1;
	}
	return 0;
}

/*=======================================
�N���A�[�����𖞂��������ǂ������ׂ�
---------------------------------------*/
int isClear(MINE_TABLE **table){
	int val = 0;
	
	val = get_opend_count(table);
	if(val == ((MINE_TABLE_WIDTH) * (MINE_TABLE_HIGHT))){
		return 1;
	}
	return 0;
}

/*=======================================
�}�X�ڕ\��
---------------------------------------*/
void view_mine_table(MINE_TABLE **table,int debug){
	int i,j;
	/*�}�X�ڂ�\������*/
	printf("   ");
	for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
		printf("%2d",j);
	}
	for(i = 1;i < MINE_TABLE_HIGHT + 1;i++){
		printf("\n%2d:",i);
		for(j = 1;j < MINE_TABLE_WIDTH + 1;j++){
			if(debug == 1){
				/* �}�X�ڂ����e�̎� */
				if(table[i][j].table_bom == BOM){
					printf(" *");
					/* �}�X�ڂ���̂Ƃ� */
				}else if(table[i][j].table_val == 0){
					printf("��");
					/*�����������Ă���Ƃ�*/
				}else if(table[i][j].table_val > 0){
					printf("%2d",table[i][j].table_val);
					/*�󂪂��Ă���Ƃ�*/
				}else if(table[i][j].table_statement == FLAG){
					printf("��");
				}
			}else{
				/* �}�X�ڂ����e�̎� */
				if(table[i][j].table_statement == OPEN && table[i][j].table_bom == BOM){
					printf(" *");
					/* �}�X�ڂ���̂Ƃ� */
				}else if(table[i][j].table_statement == OPEN && table[i][j].table_val == 0){
					printf("��");
					/*�����������Ă���Ƃ�*/
				}else if(table[i][j].table_statement == OPEN && table[i][j].table_val > 0){
					printf("%2d",table[i][j].table_val);
					/*�󂪂��Ă���Ƃ�*/
				}else if(table[i][j].table_statement == FLAG){
					printf("��");
				}else{
					printf("  ");
				}
			}
		}
	}
}

/*=======================================
�Q�[���I�[�o�[
---------------------------------------*/
void gameover(void){
	char gomi[16];
	printf("�Q�[���I�[�o�[�ł��I�I\n");
	printf("�����L�[�������Ă��������B�I�����܂��B\n");
	gets(gomi);/*�������͎�t*/
	exit(0);
}


/*=======================================
�Q�[���N���A
---------------------------------------*/
void gameclear(void){
	char gomi[16];
	printf("�N���A�[�I�I���߂łƂ��I\n");
	printf("�����L�[�������Ă��������B�I�����܂��B\n");
	gets(gomi);/*�������͎�t*/
	exit(0);
}