/*===================================
�Q�O�O�U�N�x�v���O�������C
���K�ۑ�i�P�j���Q�i�R�j
�쐬���@�S���Q�O��
�쐬�ҁ@�r�c�@����
------------------------------------*/

#include "Problem1_2_3.h"
void insert_position(LIST *start,int val,int position);
void insert_tail(LIST *start,int val);
void view_list(LIST *start);
void create_random_list(LIST *start,int list_size);

int main(void){
	LIST dmy;
	LIST *start = &dmy;/*�ŏ��̍\���̂̏ꏊ���L������*/
	
	start = &dmy;
	start->next = NULL;/*�ŏ��̓f�[�^���Ȃ��̂łm�t�k�k��ݒ肵�Ă���*/
	
	/*�����_���ȃ��X�g�𐶐�����*/
	create_random_list(start,RANDOM_LIST_SIZE);
	   
	   while(1){
		   /*���X�g��\��*/
		   view_list(start);
		   
		   printf("\n���l����͂��ĉ������B(q �Ńv���O�����I�����܂��B)\n-->");
		   gets(char_temp);/*�������͎�t*/
		   if(strcmp("q",char_temp) == 0){
			   printf("�I�����܂��B\n");
			   return 0;
		   }
		   num_temp	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/
		   printf("\n���͂���v�f�̈ʒu���w�肵�ĉ������B(1�`)-->");
		   gets(char_temp);/*�������͎�t*/
		   position	=	atoi(char_temp);/*�����񁨐��l�ϊ�*/
		   
		   /*���X�g�̎w��ʒu�֗v�f��}��*/
		   insert_position(start,num_temp,position);
		   
	   }
	   
	   return 0;
}

/*=======================================
�����_���ȃ��X�g�𐶐�����
---------------------------------------*/
void create_random_list(LIST *start,int list_size){
	int i=0;
	   srand( (unsigned)time( NULL ) );/*���ݎ������g�������W�F�l���[�^��������*/
	   for(i=0;i<list_size;i++){/*�ŏ��Ƀ����_���ȃ��X�g�𐶐�����*/
		   
		   insert_tail(start,(rand() % 10));/*0�`9�̃����_���Ȑ��l�𐶐�*/
	   }
}

/*=======================================
���X�g�̎w��ʒu�֒ǉ�����
---------------------------------------*/
void insert_position(LIST *start,int val,int position){
	LIST *list_temp;
	LIST *wp;
	LIST *wkdata;
	
	wp = start;
	for(i=0;i<position-1;i++){/*�w��ʒu�܂Ń��X�g��i��*/
		if(wp->next == NULL)continue;/*�w��ʒu�����X�g�S�����傫�������ꍇ�Ō�֒ǉ�*/
		wp = wp->next;
	}
	list_temp = wp->next;/*���X�g�̈ʒu�ۊ�*/
	
	/*���X�g�����荞�܂���*/
	wkdata = (LIST *)malloc(sizeof(LIST));
	wkdata->num = val;
	wkdata->next = list_temp;/*�ۊǂ��Ă����������X�g�֐ڑ�*/
	wp->next = wkdata;
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
	
	/*���X�g��\��*/
	printf("���݂̃��X�g�̒��g\n");
	for(wp = start->next;wp != NULL ; wp = wp->next){
		printf("%d, ",wp->num);
	}
}
