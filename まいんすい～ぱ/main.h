/*===================================
�܂��񂷂��`��
�쐬���@4��30��
�쐬�ҁ@�r�c�@����
------------------------------------*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int SetWinCenter(HWND hWnd);
void ShowMyBMP(HWND, HDC);


char szClassName[] = "�܂��񂷂��`��";
char char_temp[32];		/*��������͂Ƃ��Ď󂯎�邽��*/
int num_temp=0;			/*���l�ꎞ�ۊ�*/
int debug = 0;			/*�f�o�b�O�p*/
int i=0;
int x=0,y=0,no=0;		/*���W�ƍs���Ɏg������*/