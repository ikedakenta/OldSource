/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�P�j�i�Q�j
�쐬���@�S���Q�O��
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include "Problem1_2.h"
void insert_tail(LIST *start,int val);
void view_list(LIST *start);

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*�ŏ��̍\���̂̏ꏊ���L������*/
	LIST *wkdata;/*�f�[�^�ݒ�p*/
	
	start = &dmy;
	start->next = NULL;/*�ŏ��̓f�[�^���Ȃ��̂łm�t�k�k��ݒ肵�Ă���*/
	
	while(1){
		printf("\n���l����͂��ĉ������B(q �Ńv���O�����I�����܂��B)\n-->");
		gets(char_temp);/*�������͎�t*/
		
		if(strcmp("q",char_temp) == 0){
			printf("�I�����܂��B\n");
			return 0;
		}
		num_temp	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/
		
		/*���X�g�֗v�f��ǉ�*/
		insert_tail(start,num_temp);
		
		/*���X�g��\��*/
		view_list(start);
	}
	
	return(0);
}

/*=======================================
���X�g�ɒǉ�����
---------------------------------------*/
void insert_tail(LIST *start,int val){
	LIST *wp;
	LIST *wkdata;

	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	
	for(wp = start;wp->next != NULL;wp = wp->next){
		
		if(val < wp->next->num){//�召�֌W���r����
			wkdata->next = wp->next;//�`�F�C�����Ȃ�������
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
void view_list(LIST *start){
	LIST *wp;
	LIST *wkdata;
	
	/*���X�g��\��*/
	printf("���݂̃��X�g�̒��g\n");
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
