/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�S�j
�쐬���@�S���Q�O��
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include "Problem1_2_4.h"

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*�ŏ��̍\���̂̏ꏊ���L������*/
	LIST *wkdata = NULL;/*�f�[�^�ݒ�p*/
	start = &dmy;
	start->next = NULL;/*�ŏ��̓f�[�^���Ȃ��̂łm�t�k�k��ݒ肵�Ă���*/
	
	/*�����_���Ȑ����𐶐�����*/
	create_random_num(LIST_MAX,random_num);
	
	for( no = 0 ; no < LIST_MAX ; no++ ){
		/*�f�[�^�������Ń��X�g�ɒǉ�����*/
		insert(start,random_num[no]);

		/*���X�g��\��*/
		view_list(start,no);	
		
	}
	
	gets(char_temp);/*�������͎�t*/
	printf("�����L�[���͂�����ƏI�����܂��B\n");
	return(0);
}

/*=======================================
�����_���Ȑ����𐶐�����
---------------------------------------*/
void create_random_num(int size,int *random_num){
	int i=0;
	
	srand( (unsigned)time( NULL ) );/*���ݎ������g�������W�F�l���[�^��������*/
	printf("\n�����_�������F");
	   for(i=0;i<LIST_MAX;i++){/*�����_���ȃ��X�g�𐶐�����*/
		   random_num[i] = (rand() % 20) + 1  ;//(rand() % 10) + 1;/*1�`20�̃����_���Ȑ��l�𐶐�*/
		   printf("%d, ",random_num[i]);
	   }
	   
}

/*=======================================
�f�[�^�������Ń��X�g�ɒǉ�����
---------------------------------------*/
void insert(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;
	
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	
	for(wp = start;wp->next != NULL;wp = wp->next){
		if(val < wp->next->num){/*�召�֌W���r����*/
			wkdata->next = wp->next;/*�`�F�C�����Ȃ�������*/
			wp->next = wkdata;
			break;
		}
	}
	/*�`�F�C���̍Ō�ɂȂ�*/
	if(wp->next ==NULL){
		wkdata->next = NULL;
		wp->next = wkdata;
	}
}

/*========================================
���X�g�\��
----------------------------------------*/
void view_list(LIST *start,int no){
	LIST *wp;
	
	/*���X�g��\��*/
	printf("\n list[%d]:",no);
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
