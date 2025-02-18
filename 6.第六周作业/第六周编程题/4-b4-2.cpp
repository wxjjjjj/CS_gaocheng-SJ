/* 2353761 王皙晶 计科 */
#include <iostream>
#include <cstdio>
#include <conio.h>   //_getch()和_kbhit()的头文件 _kbhit() 函数用于检查当前是否有键盘输入。如果有按键被按下，它会返回一个非零值（通常是1），否则返回0。
#include <time.h>
#include <windows.h>  //不能和num什么玩意的清空输入错误的程序一起用
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
            int X       ：指定位置的x坐标
            int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
            int X       ：指定位置的x坐标
            int Y       ：指定位置的y坐标
            char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu() 
{
	cout << "1.用I、J、K、L键控制上下左右（大小写均可，按左箭头光标不允许下移，边界停止）" << endl;
	cout << "2.用I、J、K、L键控制上下左右（大小写均可，按左箭头光标不允许下移，边界回绕）" << endl;
	cout << "3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）" << endl;
	cout << "4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）" << endl;
	cout << "0.退出" << endl;
	cout << "请选择[0-4] ";
	char shuru;
	shuru = _getch();
	if (shuru== '0') {
		return 0;
	}
	else if (shuru == '1' ) {
		return 1;
	}
	else if (shuru == '2') {
		return 2;
	}
	else if (shuru == '3' ) {
		return 3;
	}
	else if (shuru == '4') {
		return 4;
	}
	else {       //本程序下的错误输入，处理方法应该是继续跳到这个菜单页面
		return 5;
	}
}

int move_by_ijkl(const HANDLE hout,int huirao) { //a是用来决定是否回绕的

	init_border(hout);
	gotoxy(hout, 35, 9);	//光标移回正中间
	int x = 35, y = 9;
	int diuqijiantou;
	char ch;
	if (huirao == 1) {//边界停止
		while (1) {
			if (_kbhit()) {//键盘有按键按下 则_kbhit返回值为1

				ch = _getch();
				if (int(ch) <0) { //在该程序中左箭头的返回值是负数-32？为什么？
					diuqijiantou = _getch();
				}
				switch (ch) {
					case 'i':
					case'I':
						if (y == 1) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							y--;
							gotoxy(hout, x, y);
							break; // 上
						}
					case'K':
					case 'k':
						if (y == 17) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							y++;
							gotoxy(hout, x, y);
							break; // 下
						}

					case'J':
					case 'j':
						if (x == 1) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							x--;
							gotoxy(hout, x, y);
							break; // 左  
						}

					case 'l':
					case'L':
						if (x == 69) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							x++;
							gotoxy(hout, x, y);
							break; // 右 
						}

					case'Q':
					case'q':
						gotoxy(hout, 0, 24);
						return 0;
					default:
						break;
				}  //光标移动部分

				
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}	
	}

	else {//边界回绕
		while (1) {
			if (_kbhit()) {//键盘有按键按下 则_kbhit返回值为1

				ch = _getch();
				if (int(ch) < 0) { //在该程序中左箭头的返回值是负数-32？为什么？
					diuqijiantou = _getch();//读取掉第二个等待读取的键值
				}
				switch (ch) {
					case 'i':
					case'I':
						if (y == 1) {
							y = 17;
							gotoxy(hout, x, y);
							break;
						}
						else {
							y--;
							gotoxy(hout, x, y);
							break; // 上
						}
					case'K':
					case 'k':
						if (y == 17) {
							y = 1;
							gotoxy(hout, x, y);
							break;
						}
						else {
							y++;
							gotoxy(hout, x, y);
							break; // 下
						}

					case'J':
					case 'j':
						if (x == 1) {
							x = 69;
							gotoxy(hout, x, y);
							break;
						}
						else {
							x--;
							gotoxy(hout, x, y);
							break; // 左  
						}

					case 'l':
					case'L':
						if (x == 69) {
							x = 1;
							gotoxy(hout, x, y);
							break;
						}
						else {
							x++;
							gotoxy(hout, x, y);
							break; // 右 
						}

					case'Q':
					case'q':
						gotoxy(hout, 0, 24);
						return 0;
					default:
						break;
				}  //光标移动部分
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}

	}
	return 1;
}

int move_by_arrow(const HANDLE hout, int huirao2) { //a是用来决定是否回绕的
	init_border(hout);
	gotoxy(hout, 35, 9);	//光标移回正中间
	int x = 35, y = 9;
	char ch;
	if (huirao2 == 3) {//边界停止
		while (1) {
			if (_kbhit()) {//键盘有按键按下 则_kbhit返回值为1

				ch = _getch();
				if (int(ch) < 0) { //在该程序中左箭头的返回值是负数-32？为什么？
					ch = _getch();
					switch (int(ch)) {
						case 72:
							if (y == 1) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								y--;
								gotoxy(hout, x, y);
								break; // 上
							}
						case 80:
							if (y == 17) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								y++;
								gotoxy(hout, x, y);
								break; // 下
							}

						case 75:
							if (x == 1) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								x--;
								gotoxy(hout, x, y);
								break; // 左  
							}

						case 77:
							if (x == 69) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								x++;
								gotoxy(hout, x, y);
								break; // 右 
							}
						default:
							break;
					}  //光标移动部分
				}
				if (ch == 'q' || ch == 'Q') {

						gotoxy(hout, 0, 24);
						return 0;
				}
				
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}
	}

	else {//边界回绕
		while (1) {
			if (_kbhit()) {//键盘有按键按下 则_kbhit返回值为1

				ch = _getch();
				if (int(ch) < 0) { //在该程序中左箭头的返回值是负数-32？为什么？
					ch = _getch();
					switch (int(ch)) {
						case 72:
							if (y == 1) {
								y = 17;
								gotoxy(hout, x, y);
								break;
							}
							else {
								y--;
								gotoxy(hout, x, y);
								break; // 上
							}
						case 80:
							if (y == 17) {
								y = 1;
								gotoxy(hout, x, y);
								break;
							}
							else {
								y++;
								gotoxy(hout, x, y);
								break; // 下
							}

						case 75:
							if (x == 1) {
								x = 69;
								gotoxy(hout, x, y);
								break;
							}
							else {
								x--;
								gotoxy(hout, x, y);
								break; // 左  
							}

						case 77:
							if (x == 69) {
								x = 1;
								gotoxy(hout, x, y);
								break;
							}
							else {
								x++;
								gotoxy(hout, x, y);
								break; // 右 
							}
						default:
							break;
					}  //光标移动部分
				}
				if (ch == 'q' || ch == 'Q') {

					gotoxy(hout, 0, 24);
					return 0;
				}

				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}
	}
	return 1;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄 HANDLE是一种类似int的数据类型定义，变量名是hout

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));


	while (1) {
		int a,b=1;
		a = menu();
		if (a == 0) {
			cout << 0;
			return 0;
		}
		else if (a == 1) {//功能1
			cls(hout);
			b=move_by_ijkl(hout,a);
		}
		else if (a == 2) {//功能2
			cls(hout);
			b=move_by_ijkl(hout,a);
		}
		else if (a == 3) {//功能3
			cls(hout);
			b = move_by_arrow(hout, a);
		
		}
		else if (a == 4) {//功能4
			cls(hout);
			b = move_by_arrow(hout, a);
		}

		if (b==0) {
			cout << "游戏结束，按回车键返回菜单.";
			int huiche;
			
			while (1) {
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
		/* 此句的作用是调用系统的cls命令清屏 */
		cls(hout);
			
	}

	return 0;
}
