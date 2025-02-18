/* 计科 2353761 王皙晶 */
#include"cmd_console_tools.h"
#include"hanoi.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

int bushu = 1;
int a[10], b[10], c[10];  //存储盘号
int d, e, f;            //存储a，b，c柱的盘数
static int sudushijian;//移动延时的时间

void chushihua(char src, int n) 
{
	bushu = 1;
	d = 0;
	e = 0;
	f = 0;
	sudushijian = 0;
	for (int g = 0; g < 10; ++g) {
		a[g] = 0;
		b[g] = 0;
		c[g] = 0;
	}
	if (src == 'A') {
		d = n;
		for (int i = 0; i < n; ++i) {
			a[i] = n - i;
		}
	}
	else if (src == 'B') {
		e = n;
		for (int i = 0; i < n; ++i) {
			b[i] = n - i;
		}
	}
	else {
		f = n;
		for (int i = 0; i < n; ++i) {
			c[i] = n - i;
		}
	}
	return;
}
void chushihua2(int gongnenghao)
{
	if (gongnenghao == 4 ||gongnenghao==9||gongnenghao==8) {
		cct_gotoxy(11, 36);
		cout << "初始： ";
		cout << "A:";
		for (int m = 0; m < 10; ++m) {
			if (a[m] > 0) {
				cout << setw(2) << a[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "B:";
		for (int m = 0; m < 10; ++m) {
			if (b[m] > 0) {
				cout << setw(2) << b[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "C:";
		for (int m = 0; m < 10; ++m) {
			if (c[m] > 0) {
				cout << setw(2) << c[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";
		cout << endl;
		print_shu();
		if (gongnenghao != 9) {
			if (sudushijian) {
				Sleep(sudushijian);
			}
			else {
				int huiche;
				while (1) {
					huiche = _getch();
					if (huiche == 13) {
						break;
					}
				}
			}
		}
		else {
			cct_gotoxy(9, 33);
			cout << "=========================" << endl;
			cct_gotoxy(9, 34);
			cout << "  A         B         C" << endl;
		}
	}
	return;
}
void mark_number(int n,char src, char dst)
{
	int i, j;
	if (src == 'A') {
		i = d;
		a[i - 1] = 0;
		--d;
	}
	else if (src == 'B') {
		i = e;
		b[i - 1] = 0;
		--e;
	}
	else {
		i = f;
		c[i - 1] = 0;
		--f;
	}

	if (dst == 'A') {
		j = d;
		a[j] = n;
		++d;
	}
	else if (dst == 'B') {
		j = e;
		b[j] = n;
		++e;
	}
	else {
		j = f;
		c[j] = n;
		++f;
	}
	return;
}

void print_column(int n, char src, char dst,int gongnenghao)
{
	mark_number(n, src, dst);
	if (gongnenghao == 2) {
		cout << endl;
	}
	else {
		cout << "A:";
		for (int m = 0; m < 10; ++m) {
			if (a[m] > 0) {
				cout << setw(2) << a[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "B:";
		for (int m = 0; m < 10; ++m) {
			if (b[m] > 0) {
				cout << setw(2) << b[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "C:";
		for (int m = 0; m < 10; ++m) {
			if (c[m] > 0) {
				cout << setw(2) << c[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";
		cout << endl;
		if (gongnenghao != 3) {
			print_shu();
		}
	}
	return;
}

void print_shu()//纵向输出函数
{
	int x = 11, y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (a[m] > 0) {
			cout << a[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (b[m] > 0) {
			cout << b[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (c[m] > 0) {
			cout << c[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	return;
}

void print(int x, int y)
{
	cct_gotoxy(x, y);
	cout << "按回车键继续";

	while (_getch() != '\r')
		;
	cct_cls();

	return;
}

void print_title(int gongnenghao,char src,char dst,int n)
{
	cct_cls();
	switch (gongnenghao) {
		case 6:
		case 7:
		case 9:
			cct_gotoxy(0, 0);
			cout << "从 " << src << " 移动到 " << dst << " ,共 " << n << " 层";
			break;
		case 8:
		case 4:
			cout << "从 " << src << " 移动到 " << dst << " ,共 " << n << " 层，延时设置为 ";
			break;
		default:
			break;
	}
	return;
}
void draw_column(char src,char dst,int gongnenghao,int n)
{
	if (gongnenghao == 5 || gongnenghao == 6 || gongnenghao == 7 || gongnenghao == 8 || gongnenghao == 9) {
		if (gongnenghao != 8) {
			print_title(gongnenghao, src, dst, n);
		}
		int x;
		int y;
		cct_setcursor(CURSOR_INVISIBLE);
		/*先画三个底柱*/
		x = 1;
		y = 20;
		/* 在坐标(1,20)位置处打印第一个底柱 */
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
		x = 1 + LENGTH + SPACE;                                                 //A柱子起始x：1-24 
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
		x = 1 + (LENGTH + SPACE) * 2;                                            //B柱起始 x：33-56 
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);                 //C柱起始 x: 65-88  
		/*开始打印条柱*/
		for (y = 19; y >= 5; --y) {
			x = 1 + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
			x = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
			x = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
		}
		//增设常量A柱中间值x1=1+(LENGTH-1)/2；B柱中间值x2=1+LENGTH+SPACE+(LENGTH-1)/2;C柱中间值x3=1+(LENGTH+SPACE)*2+(LENGTH-1)/2
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
	return;
}

void draw_original(char src,int n,int gongnenghao) 
{
	if (gongnenghao == 6 || gongnenghao == 7 || gongnenghao == 8 || gongnenghao == 9) {
		cct_setcursor(CURSOR_INVISIBLE);

		int x, y = 19;
		if (src == 'A') {
			x = 1 + (LENGTH - 1) / 2;
		}
		else if (src == 'B') {
			x = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
		}
		else {
			x = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
		}
		for (int h = n; h >= 1; --h) {
			cct_showch(x - h, y, ' ', h, fg_color, 2 * h + 1);
			--y;
			Sleep(30);
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
	return;
}

void yanshipanduan(int gongnenghao, char src, char dst, int n)
{
	if (gongnenghao == 4 || gongnenghao == 8) {
		if (gongnenghao == 8) {
			movement(src, dst, n);
		}
		if (sudushijian) {
			Sleep(sudushijian);
		}
		else {
			int huiche;
			while (1) {
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
	}
	return;
}

void panduan_function(int gongnenghao, int n, char src, char dst)
{
	if (gongnenghao == 1) {
		cout << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
	}
	else {
		if (gongnenghao != 2&&gongnenghao!=3) {
			cct_gotoxy(11, 36);
		}
		cout << "第" << setw(4) << bushu << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
		print_column(n, src, dst, gongnenghao);
		yanshipanduan(gongnenghao, src, dst, n);
	}
	return;
}

void hanoi(int n, char src, char tmp, char dst, int gongnenghao)  //n是盘号 从上到下为1，2，3...传入功能号
{
	if (gongnenghao != 5 && gongnenghao != 6 && gongnenghao != 7 && gongnenghao != 9) {
		if (n == 1) {
			panduan_function(gongnenghao, n, src, dst);
			++bushu;
			return;
		}
		hanoi(n - 1, src, dst, tmp, gongnenghao);
		panduan_function(gongnenghao, n, src, dst);
		++bushu;
		hanoi(n - 1, tmp, src, dst, gongnenghao);
	}
	return;
}


void shuru(char *src1,char *tmp1,char *dst1,int*n,int gongnenghao)//处理输入的函数                                                       
{
	int layers;
	char src, dst;//layers是层，src是起始柱,dst是目标柱
	if (gongnenghao != 5) {
		while (1) {
			cout << "请输入汉诺塔的层数(1-10)" << endl;
			cin >> layers;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
			}
			else {
				cin.ignore(65536, '\n');//输入正确也要忽略后面的字符
				if (layers >= 1 && layers <= 16) {
					*n = layers;
					while (1) {
						cout << "请输入起始柱(A-C)" << endl;
						cin >> src;
						if (cin.good() == 0) {
							cin.clear();
							cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符//加个continue！！！会大大减少程序量 并且65536定义成宏更好 
						}
						else {
							cin.ignore(65536, '\n');//输入正确也要忽略后面的字符
							if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
								if (src >= 'a' && src <= 'c') {
									src = src - 32;
								}
								*src1 = src;
								while (1) {
									cout << "请输入目标柱(A-C)" << endl;
									cin >> dst;
									if (cin.good() == 0) {
										cin.clear();
										cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
									}
									else {
										cin.ignore(65536, '\n');
										if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
											if (dst >= 'a' && dst <= 'c') {
												dst = dst - 32;
											}
											*dst1 = dst;
											if (src == dst) {
												cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
											}
											else {
												break;
											}
										}
									}
								}
								break;
							}
						}
					}
					break;
				}
			}
		}                //输入部分处理完毕;已经转了大小写
		*tmp1 = 'A' + 'B' + 'C' - src - dst;
	}
	return;
}

void set_sudu(char src,char dst,int layers,int gongnenghao)
{
	int sudu;
	if (gongnenghao == 4 || gongnenghao == 8) {
		while (1) {
			cout << "请输入移动速度(0-5: 0-按回车单步演示 1-5延时对应为100ms/80ms/50ms/20ms/10ms)" << endl;
			cin >> sudu;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
			}
			else {
				if (sudu >= 0 && sudu <= 5)
					break;
			}
		}
		//延时设置sudu）
		if (sudu == 1) {
			sudushijian = 100;
		}
		else if (sudu == 2) {
			sudushijian = 80;
		}
		else if (sudu == 3) {
			sudushijian = 50;
		}
		else if (sudu == 4) {
			sudushijian = 20;
		}
		else if (sudu == 5) {
			sudushijian = 10;
		}
		else {//0-单步运行
			sudushijian = 0;
		}
		print_title(4, src, dst, layers);
		cout << sudu;
		cct_gotoxy(9, 33);
		cout << "=========================" << endl;
		cct_gotoxy(9, 34);
		cout << "  A         B         C" << endl;
		cct_gotoxy(20, 36);
	}
	return;
}

void movement(char src, char dst, int n)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int srcc, dstt, x1, x2;
	if (src == 'A') {
		srcc = d;
		x1 = 1 + (LENGTH - 1) / 2;
	}
	else if (src == 'B') {
		srcc = e;
		x1 = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
	}
	else {
		srcc = f;
		x1 = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
	}

	if (dst == 'A') {
		dstt = d;
		x2 = 1 + (LENGTH - 1) / 2;
	}
	else if (dst == 'B') {
		dstt = e;
		x2 = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
	}
	else {
		dstt = f;
		x2 = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
	}
    //上移
	for (int y = 19 - srcc; y >= Y; y--) {
		cct_showstr(x1-n, y, " ", n, fg_color, 2 * n+1 );          
		Sleep(sudushijian+20);
		if (y >= Y+1) {
			cct_showch(x1-n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n+1);
		}
		if (y >= 5) {
			cct_showch(x1, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
	}
	if (x1 < x2) {  //右移(x1<x2)
		for (int x = x1; x <= x2; x++) {
			cct_showch(x-n, Y, ' ', n, fg_color, 2 * n+1);
			Sleep(sudushijian+20);
			if (x <= x2 - 1) {
				cct_showch(x-n, Y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
			}
		}
	}
	else {     //左移 x1>x2
		for (int x = x1; x >= x2; x--) {
			cct_showch(x-n, Y, ' ', n, fg_color, 2 * n + 1);
			Sleep(sudushijian+20);
			if (x >= x2 - 1) {
				cct_showch(x-n, Y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
			}
		}
	}
	//下移 
	for (int y = Y; y <= 19-dstt+1; y++) {
		cct_showstr(x2-n, y, " ", n, fg_color, 2*n + 1);
		Sleep(sudushijian+20);
		if (y <= 19-dstt) {
			cct_showch(x2-n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}
		if (y >= 5&&y<=19-dstt) {
			cct_showch(x2, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
	}
	cct_setcolor(COLOR_BLACK,COLOR_WHITE); //恢复缺省颜色--黑底白字
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return;
}

int game_9_shuru()
{
	char srcc1, dstt1;
	while (1) {
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		int x1, y1;
		cct_getxy(x1, y1);
		cct_showch(x1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 2);//擦除
		cct_gotoxy(x1, y1);
		while (1) {
			srcc1 = _getche();
			if ((srcc1 >= 'a' && srcc1 <= 'c') || (srcc1 >= 'A' && srcc1 <= 'C')||srcc1=='Q'||srcc1=='q') {
				if (srcc1 == 'q' || srcc1 == 'Q') {
					return 0;
				}
				if (srcc1 >= 'a' && srcc1 <= 'c') {
					srcc1 = srcc1 - 32;
				}
				while (1) {
					dstt1 = _getche();
					if ((dstt1 >= 'a' && dstt1 <= 'c') || (dstt1 >= 'A' && dstt1 <= 'C')) {
						if (dstt1 >= 'a' && dstt1 <= 'c') {
							dstt1 = dstt1 - 32;
						}
						if (dstt1 != srcc1) {
							while (_getch() != '\r')
								;
							break;
						}

					}
					cct_showch(x1+1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 1);//擦除
					cct_gotoxy(x1+1, y1);
				}
			}
			else {
				cct_showch(x1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 1);//擦除
				cct_gotoxy(x1, y1);
				continue;
			}
			break;
		}//输入完成
		int m, n;
		if (srcc1 == 'A') {
			m =d==0?0: a[d - 1];
		}
		else if (srcc1 == 'B') {
			m =e==0?0: b[e - 1];
		}
		else {
			m = f==0?0:c[f - 1];
		}
		if (dstt1 == 'A') {
			n = d == 0 ? 0 : a[d - 1];
		}
		else if (dstt1 == 'B') {
			n = e == 0 ? 0 : b[e - 1];
		}
		else {
			n = f == 0 ? 0 : c[f - 1];;
		}
		if (m == 0) {
			cout << endl;
			cout << "不要移动空的柱子";
			Sleep(1000);
			cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 40);//擦除
			cct_showch(0, 39, ' ', COLOR_BLACK, COLOR_WHITE, 40);//擦除
			cct_gotoxy(0, 38);
		}
		else if (m >= n && n != 0) {
			cout << endl;
			cout << "NoNo,不要大盘压小盘哦";
			Sleep(1000);
			cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 40);//擦除
			cct_showch(0, 39, ' ', COLOR_BLACK, COLOR_WHITE, 40);//擦除
			cct_gotoxy(0, 38);
		}
		else {
			game_9_yidong(srcc1,dstt1,m);
			break;
		}
	}
	return 1;
}

void game_9_yidong(char srcc1, char dstt1,int m)
{
	cct_gotoxy(9, 33);
	cout << "=========================" << endl;
	cct_gotoxy(9, 34);
	cout << "  A         B         C" << endl;
	cct_gotoxy(11, 36);
	cout << "第" << setw(4) << bushu << " 步(" << setw(2) << m << "#: " << srcc1 << "-->" << dstt1 << ")  ";
	++bushu;
	print_column(m, srcc1, dstt1, 9);
	movement(srcc1, dstt1, m);
}

void game_9_control(char dst,int layers)
{
	int i=1;
	if (dst == 'A') {
		while (d != layers&&i==1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	else if (dst == 'B') {
		while (e!= layers && i == 1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	else {
		while (f != layers && i == 1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	if (i == 0) {
		cct_gotoxy(0, 39);
		cout << "再来一局！";
		return;
	}
	cct_gotoxy(0, 39);
	cout << "游戏结束，太棒啦！！";
	return;
	
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
