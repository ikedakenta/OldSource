/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�T�j���V
�쐬���@�S���Q�V��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "main.h"
#include "mine_management.h"

int main(void){
/*�}�X�ڂ̊m��
	�[�̈��͋�̂܂܎g���̂ŗ]����2�񑽂����*/
	//MINE_TABLE table[MINE_TABLE_HIGHT + 2][MINE_TABLE_WIDTH + 2];
	MINE_TABLE **table;

	/*�}�X�ڃ������̈�m��*/
	table = getMemory(MINE_TABLE_WIDTH,MINE_TABLE_HIGHT);
	/*�}�X�ڏ�����*/
	init_mine_table(table);
	
	printf("\n���W����͂��A�s���𐔒l�œ��͂��ĉ������B\n"
			"(q �Ńv���O�����I�����܂��B)\n"
			"(r �ŃQ�[�������X�^�[�g���܂��B)\n");

	while(1){
		/*�}�X�ڕ\��*/
		view_mine_table(table,debug);
		
		/*�o�^����*/
		printf("\n(d �Ńf�o�b�O�\�����܂��B)"
			"��Fx y no\n"
			"x,y�F���W no�F1 �߂��� 2 �t���O����\n"
			"-->");
		gets(char_temp);/*�������͎�t*/
		if(strcmp("q",char_temp) == 0){
			printf("�I�����܂��B\n");
			return 0;
		}else if(strcmp("d",char_temp) == 0){
			if(debug == 0){
				debug = 1;/*�f�o�b�O�\��ON*/
			}else if(debug == 1){
				debug = 0;/*�f�o�b�O�\��OFF*/
			}
		}else if(strcmp("r",char_temp) == 0){
			/*�Q�[��������*/
			init_mine_table(table);
			continue;
		}
		/*���͎�t*/
		sscanf(char_temp,"%d %d %d",&y,&x,&no);
		
		/*�}�X�ڂ��J��*/
		if(no == 1){
			if(isBomd(table,x,y)){/*���e�Ȃ�*/
				if(isOpend(table,x,y)){
					printf("���̃}�X�͊��ɊJ���Ă��܂��B\n");
				}else{
					gameover();/*�Q�[���I�[�o�[*/
				}
			}else{
				if(isOpend(table,x,y)){
					/*���ɊJ����Ă��鐔���̎���������ŊJ��*/
					open_mine_table_execute(table,x,y);
				}else{
					/*���J��̈���J��*/
					open_mine_table(table,x,y);
				}
			}
		}else if(no == 2){
			if(isOpend(table,x,y)){
				printf("���̃}�X�͊��ɊJ���Ă��܂��B\n");
			}else{
				/*�������*/
				check_flag_mine_table(table,x,y);
			}
		}

		if(isClear(table)){/*�N���A�[�Ȃ�*/
			gameclear();
		}
	}
	return(0);
}