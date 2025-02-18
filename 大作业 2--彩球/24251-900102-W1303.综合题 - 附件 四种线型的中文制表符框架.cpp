#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void cct_showstr(const int X, const int Y, const char* str, const int bg_color, const int fg_color, int rpt, int maxlen);
void cct_getxy(int& x, int& y);
void cct_setfontsize(const char* fontname, const int high, const int width);
int main()
{
	/* 四种线型的框架，每种11个元素，每个元素均为一个中文字符（2字节） 
		双线框架："╔", "╚", "╗", "╝", "═", "║", "╦", "╩", "╠", "╣", "╬"
	 	单线框架："┏", "┗", "┓", "┛", "━", "┃", "┳", "┻", "┣", "┫", "╋"
		横双竖单: "╒", "╘", "╕", "╛", "═", "│", "╤", "╧", "╞", "╡", "╪"
		横单竖双："╓", "╙", "╖", "╜", "─", "║", "╥", "╨", "╟", "╢", "╫"
    */

	/* 双线框架使用样例（可自行替换为其它线型） 
	   ╔═╦═╗
	   ║  ║  ║
	   ╠═╬═╣
	   ║  ║  ║
	   ╚═╩═╝      */
	cct_setfontsize("新宋体",24,0);
	cout << "╔═╦═╗" << endl;
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔═╦═╗", 1, 4, 1, -1);
	cout << "║  ● ║ ○ ║" << endl;
	cout << "╠═╬═╣" << endl;
	cout << "║  ║  ║" << endl;
	cout << "╚═╩═╝" << endl;

	return 0;
}
/*
void draw_border_pro(int array[][9], int hang, int lie)
{
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie - 1; ++i) {                                  //1
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);                                                 
		cct_showstr(x, y, "╦", COLOR_HWHITE, COLOR_BLACK, 1, -1);       
	}
	cct_getxy(x, y);                                                     
	cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);           
	cct_getxy(x, y);
	cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < hang-1; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "╠", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie - 1; ++i) {
			cct_getxy(x, y);
			cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			cct_getxy(x, y);
			cct_showstr(x, y, "╬", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "╣", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_gotoxy(0, y + 1);
	cct_getxy(x, y);
	cct_showstr(0, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
		cout << "  ";
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(0, y + 1, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie-1; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "╩", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	//画球
	cct_gotoxy(2, 1);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			cct_getxy(x, y);
			if (array[(y - 1)/2][(x-2)/4] != 0) {
				cct_showstr(x, y, "○", array[(y - 1) / 2][(x - 2) / 4], COLOR_HWHITE, 1, -1);
				cct_getxy(x, y);
				cct_gotoxy(x + 2, y);
			}
			else {
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "  ";
				cct_getxy(x, y);
				cct_gotoxy(x + 2, y);
			}
		}
		cct_gotoxy(2, y + 2);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}*/