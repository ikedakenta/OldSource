/*===================================
まいんすい～ぱ
作成日　4月30日
作成者　池田　健太
------------------------------------*/
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int SetWinCenter(HWND hWnd);
void ShowMyBMP(HWND, HDC);


char szClassName[] = "まいんすい～ぱ";
char char_temp[32];		/*文字列入力として受け取るため*/
int num_temp=0;			/*数値一時保管*/
int debug = 0;			/*デバッグ用*/
int i=0;
int x=0,y=0,no=0;		/*座標と行動に使う入力*/