/*===================================
�܂��񂷂��`��
�쐬���@2006�N4��30��
�쐬�ҁ@�r�c�@����
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "main.h"
#include "mine_management.h"
#include "resource.h"


/*=======================================
�E�B���h�E�Y���C���v���O����
---------------------------------------*/
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInst,LPSTR lpszCmdLine,int nCmdShow){
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS myProg;
	
	if(!hPreInst){
		myProg.style				=	CS_HREDRAW | CS_VREDRAW;
		myProg.lpfnWndProc		=	WndProc;
		myProg.cbClsExtra		=	0;
		myProg.cbWndExtra		=	0;
		myProg.hInstance		=	hInstance;
		myProg.hIcon			=	NULL;
		myProg.hCursor			=	LoadCursor(NULL, IDC_ARROW);
		myProg.hbrBackground	=	GetStockObject(WHITE_BRUSH);
		myProg.lpszMenuName		=	(LPCTSTR)MINE_MENU;//MAKEINTRESOURCE(MINE_MENU);
		myProg.lpszClassName	=	szClassName;
		if(!RegisterClass(&myProg)){
			return FALSE;
		}
	}
	hWnd	=	CreateWindow(szClassName,"�܂��񂷂��`��",
		WS_CAPTION | WS_SYSMENU | WS_DLGFRAME | WS_MINIMIZEBOX,
		CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);
	SetWinCenter(hWnd);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	while(GetMessage(&lpMsg,NULL,0,0)){
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return(lpMsg.wParam);
}

/*=======================================
�E�B���h�E�v���V�[�W������
�R�[���o�b�N�֐�
���b�Z�[�W���󂯎�肻�ꂼ�ꏈ������
---------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
	/*�}�X�ڔz��A�h���X���*/
	MINE_TABLE **table;
	HDC hdc;
	PAINTSTRUCT ps;
	int id = 0;
	int difficulty = DIFFICULT;/*������Փx*/
	int size_x,size_y;
	
	switch(msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		id = MessageBox(hWnd,
			(LPCSTR)"�I�����܂���",
			(LPCSTR)"�I���m�F",
			MB_OKCANCEL | MB_ICONQUESTION);
		if(id == IDOK)
			DestroyWindow(hWnd);
		return (0L);
	case WM_PAINT:
		hdc	=	BeginPaint(hWnd,&ps);
		ShowMyBMP(hWnd,hdc);
		TextOut(hdc,50,50,"�܂��񂷂��`��",14);
		SetBkMode(hdc,TRANSPARENT);
		SetTextColor(hdc,RGB(255,0,0));
		TextOut(hdc,50,100,"�r�c�����@����",14);
		EndPaint(hWnd,&ps);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)){
		case EXIT_GAME:
			SendMessage(hWnd,WM_CLOSE,wParam,lParam);
		case HELP:
			MessageBox(hWnd, 
				(LPCSTR)"�w���v��������܂���", 
				(LPCSTR)"test", 
				MB_OK);
			break;
		case VERSION_INFO:
			MessageBox(hWnd, 
				(LPCSTR)"�o�[�W������񂪉�����܂���", 
				(LPCSTR)"About",
				MB_OK);
			break;
		case NEW_GAME:
			/*��Փx���ƂɃe�[�u���T�C�Y���w��*/
			if(difficulty == DIFFICULT_EASY){
				size_x = size_y = EASY_TABLE_SIZE;
			}else if(difficulty == DIFFICULT_NORMAL){
				size_x = size_y = NORMAL_TABLE_SIZE;
			}else if(difficulty == DIFFICULT_HARD){
				size_x = size_y = HARD_TABLE_SIZE;
			}
			/*�}�X�ڃ������̈�m��*/
			table = getMemory(size_x,size_y);
			/*�}�X�ڏ�����*/
			init_mine_table(table);
			
			/*
			printf("\n���W����͂��A�s���𐔒l�œ��͂��ĉ������B\n"
				"(q �Ńv���O�����I�����܂��B)\n"
				"(r �ŃQ�[�������X�^�[�g���܂��B)\n");
			*/

			while(1){
				break;/*�f�o�b�O�p*/

				/*�}�X�ڕ\��*/
				//view_mine_table(table,debug);
				
				/*�o�^����*/
				/*printf("\n(d �Ńf�o�b�O�\�����܂��B)"
					"��Fx y no\n"
					"x,y�F���W no�F1 �߂��� 2 �t���O����\n"
					"-->");
					*/
				//gets(char_temp);/*�������͎�t*/
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
				//sscanf(char_temp,"%d %d %d",&y,&x,&no);
				
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
		break;
		default:
			return(DefWindowProc(hWnd,msg,wParam,lParam));
	}
	return (0L);
}

/*=======================================
�E�B���h�E�𒆉��ɃZ�b�g����
---------------------------------------*/
int SetWinCenter(HWND hWnd)
{
    HWND hDeskWnd;
    RECT deskrc, rc;
    int x, y;
    
    hDeskWnd = GetDesktopWindow();/*�f�X�N�g�b�v�E�B���h�E�̃n���h�����擾����*/
	/*�E�B���h�E�͈͂��擾���Đ^�񒆍��W���v�Z*/
    GetWindowRect(hDeskWnd, (LPRECT)&deskrc);
    GetWindowRect(hWnd, (LPRECT)&rc);
    x = (deskrc.right - (rc.right-rc.left)) / 2;
    y = (deskrc.bottom - (rc.bottom-rc.top)) / 2;
	/*�E�B���h�E���w��ʒu�ɃZ�b�g����*/
    SetWindowPos(hWnd, HWND_TOP, x, y, (rc.right-rc.left), (rc.bottom-rc.top),SWP_SHOWWINDOW); 
    return 0;
}

/*=======================================
�r�b�g�}�b�v�\���e�X�g
---------------------------------------*/
void ShowMyBMP(HWND hWnd, HDC hdc)
{
    HDC hmdc;
    HBITMAP hBitmap;
    BITMAP bmp;
    HINSTANCE hInst;
    int BMP_W, BMP_H;

    hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
    hBitmap = LoadBitmap(hInst,(LPCTSTR)MYBMP);
    GetObject(hBitmap, sizeof(BITMAP), &bmp);
    BMP_W = (int)bmp.bmWidth;
    BMP_H = (int)bmp.bmHeight;
    hmdc = CreateCompatibleDC(hdc);
    SelectObject(hmdc, hBitmap);
    BitBlt(hdc, 0, 0, BMP_W, BMP_H, hmdc, 0, 0, SRCCOPY);
    StretchBlt(hdc, 0, BMP_H, BMP_W / 2, BMP_H / 2, hmdc, 0, 0, BMP_W, BMP_H, SRCCOPY);
    DeleteDC(hmdc);
    DeleteObject(hBitmap);
    return;
}
