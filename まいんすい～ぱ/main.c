/*===================================
まいんすい～ぱ
作成日　2006年4月30日
作成者　池田　健太
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
ウィンドウズメインプログラム
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
	hWnd	=	CreateWindow(szClassName,"まいんすい～ぱ",
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
ウィンドウプロシージャ処理
コールバック関数
メッセージを受け取りそれぞれ処理する
---------------------------------------*/
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
	/*マス目配列アドレス情報*/
	MINE_TABLE **table;
	HDC hdc;
	PAINTSTRUCT ps;
	int id = 0;
	int difficulty = DIFFICULT;/*初期難易度*/
	int size_x,size_y;
	
	switch(msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		id = MessageBox(hWnd,
			(LPCSTR)"終了しますか",
			(LPCSTR)"終了確認",
			MB_OKCANCEL | MB_ICONQUESTION);
		if(id == IDOK)
			DestroyWindow(hWnd);
		return (0L);
	case WM_PAINT:
		hdc	=	BeginPaint(hWnd,&ps);
		ShowMyBMP(hWnd,hdc);
		TextOut(hdc,50,50,"まいんすい～ぱ",14);
		SetBkMode(hdc,TRANSPARENT);
		SetTextColor(hdc,RGB(255,0,0));
		TextOut(hdc,50,100,"池田健太　試作",14);
		EndPaint(hWnd,&ps);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)){
		case EXIT_GAME:
			SendMessage(hWnd,WM_CLOSE,wParam,lParam);
		case HELP:
			MessageBox(hWnd, 
				(LPCSTR)"ヘルプが押されました", 
				(LPCSTR)"test", 
				MB_OK);
			break;
		case VERSION_INFO:
			MessageBox(hWnd, 
				(LPCSTR)"バージョン情報が押されました", 
				(LPCSTR)"About",
				MB_OK);
			break;
		case NEW_GAME:
			/*難易度ごとにテーブルサイズを指定*/
			if(difficulty == DIFFICULT_EASY){
				size_x = size_y = EASY_TABLE_SIZE;
			}else if(difficulty == DIFFICULT_NORMAL){
				size_x = size_y = NORMAL_TABLE_SIZE;
			}else if(difficulty == DIFFICULT_HARD){
				size_x = size_y = HARD_TABLE_SIZE;
			}
			/*マス目メモリ領域確保*/
			table = getMemory(size_x,size_y);
			/*マス目初期化*/
			init_mine_table(table);
			
			/*
			printf("\n座標を入力し、行動を数値で入力して下さい。\n"
				"(q でプログラム終了します。)\n"
				"(r でゲームをリスタートします。)\n");
			*/

			while(1){
				break;/*デバッグ用*/

				/*マス目表示*/
				//view_mine_table(table,debug);
				
				/*登録処理*/
				/*printf("\n(d でデバッグ表示します。)"
					"例：x y no\n"
					"x,y：座標 no：1 めくる 2 フラグ立て\n"
					"-->");
					*/
				//gets(char_temp);/*文字入力受付*/
				if(strcmp("q",char_temp) == 0){
					printf("終了します。\n");
					return 0;
				}else if(strcmp("d",char_temp) == 0){
					if(debug == 0){
						debug = 1;/*デバッグ表示ON*/
					}else if(debug == 1){
						debug = 0;/*デバッグ表示OFF*/
					}
				}else if(strcmp("r",char_temp) == 0){
					/*ゲーム初期化*/
					init_mine_table(table);
					continue;
				}
				/*入力受付*/
				//sscanf(char_temp,"%d %d %d",&y,&x,&no);
				
				/*マス目を開く*/
				if(no == 1){
					if(isBomd(table,x,y)){/*爆弾なら*/
						if(isOpend(table,x,y)){
							printf("そのマスは既に開いています。\n");
						}else{
							gameover();/*ゲームオーバー*/
						}
					}else{
						if(isOpend(table,x,y)){
							/*既に開かれている数字の周りを自動で開く*/
							open_mine_table_execute(table,x,y);
						}else{
							/*未開拓領域を開く*/
							open_mine_table(table,x,y);
						}
					}
				}else if(no == 2){
					if(isOpend(table,x,y)){
						printf("そのマスは既に開いています。\n");
					}else{
						/*印をつける*/
						check_flag_mine_table(table,x,y);
					}
				}
				
				if(isClear(table)){/*クリアーなら*/
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
ウィンドウを中央にセットする
---------------------------------------*/
int SetWinCenter(HWND hWnd)
{
    HWND hDeskWnd;
    RECT deskrc, rc;
    int x, y;
    
    hDeskWnd = GetDesktopWindow();/*デスクトップウィンドウのハンドルを取得する*/
	/*ウィンドウ範囲を取得して真ん中座標を計算*/
    GetWindowRect(hDeskWnd, (LPRECT)&deskrc);
    GetWindowRect(hWnd, (LPRECT)&rc);
    x = (deskrc.right - (rc.right-rc.left)) / 2;
    y = (deskrc.bottom - (rc.bottom-rc.top)) / 2;
	/*ウィンドウを指定位置にセットする*/
    SetWindowPos(hWnd, HWND_TOP, x, y, (rc.right-rc.left), (rc.bottom-rc.top),SWP_SHOWWINDOW); 
    return 0;
}

/*=======================================
ビットマップ表示テスト
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
