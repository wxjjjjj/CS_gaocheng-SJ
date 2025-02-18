/* 计科 2353761 王皙晶*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;


/*本文件：
放 cmd 图形界面方式实现的各函数  功能DEFG*/

//衔接--按回车键图形显示
void draw_border_pause()
{
	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(x, y + 1);
	cout << "按回车键显示图形...";

	while (_getch() != '\r')
		;
	cct_cls();
}
//画边框（无分割线）
void draw_border(int array[][9], int hang, int lie)
{//因为清屏了，所以画框的相对参考起点就是（0，0）
	cct_cls();
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < hang; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(0, y+1, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	//画球
	cct_gotoxy(2, 1);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			cct_getxy(x, y);
			if (array[y - 1][x/2 - 1] != 0) {
				cct_showstr(x, y, "○", array[y - 1][x/2 - 1], COLOR_HWHITE, 1, -1);
			}
			else {
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "  ";
			}
		}
		cct_gotoxy(2, y+1);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}
//画边框（有分割线）
void draw_border_pro(int array[][9], int hang, int lie)
{
	cct_cls();
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie - 1; ++i) {
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
}
//得分框
void draw_score()
{
	int x, y, X, Y, x1, y1;
	cct_gotoxy(45, 0);
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 5; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_getxy(X, Y);
	cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "得分：", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x1, y1);
	cct_showstr(x1, y1, "0", COLOR_HWHITE, COLOR_BLACK, 1, -1);             //更新得分的坐标(53,1)
	cct_getxy(x, y);
	while (x < X) {
		cct_showstr(x, y, " ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
	}
	cct_showstr(X, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 5; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}
//计算数组中各个颜色球的数量
int cal_number(int array[][9], int hang,int lie,int color)
{
	int count = 0;
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] == color) {
				count++;
			}
		}
	}
	return count;
}
//统计框
void draw_sort(int array[][9],int hang,int lie)
{
	int x, y;
	cct_showstr(45, 8, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 12; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < 8; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(45, y + 1);
		cct_getxy(x, y);
		cct_showstr(45, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < 12; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 12; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "╝", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_showstr(47, 9, "○", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << ':' << setw(2) << hang * lie-5<<"/("<< fixed << setprecision(2) << double(hang*lie-5)/hang/lie*100<<"%)" << "  消除-0";
	for (int i = 1; i < 8; ++i) {
		cct_showstr(47, 9+i, "○", i, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cct_getxy(x, y);
		cct_gotoxy(x, y);
		cout << ':' << setw(2) << cal_number(array,hang,lie,i) << "/(" << fixed << setprecision(2)<< double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)" << "  消除-0";
	}
	return;
}
//各框架初始
void draw_real_time(int ball[],int array[][9],int hang,int lie) //实时绘制
{
	draw_score();//得分框
	int x, y;
	cct_showstr(45, 4, "╔", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 2; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "╦", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j <1; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(45, y + 1);
		cct_getxy(x, y);
		cct_showstr(45, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < 3; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
	}
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "╚", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 2; ++i) {
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
	for (int i = 0; i < 3; ++i) {
		cct_showstr(47 + 4 * i,5 , "○", ball[i], COLOR_HWHITE, 1, -1);
	}
	draw_sort(array,hang,lie);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	
	return;
}
//鼠标控制
void move_by_mouse(int hang,int lie,int array[][9],int gongnenghao)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int x, y, flag_y = 0, flag_x = 0, flag_first = 0, flag_second = 0, array_src_x = 0, array_src_y = 0, array_dst_x = 0, array_dst_y = 0,sum_score=0;
	cct_getxy(x, y);
	cct_gotoxy(0, y);
	cout << "鼠标移动，左键单击选择，右键单击退出" << endl;
	cct_enable_mouse();
	cout << "[当前光标] ";
	cct_getxy(x, y);
	int MX, MY, MAction, keycode1, keycode2,state_= CCT_MOUSE_EVENT,ball[3] = { 0 };
	if (gongnenghao == 2) {//画得分框、统计框、和预告彩球 //cct_gotoxy(45, 0);//cct_gotoxy(0, 22);
		for (int i = 0; i < 3; ++i) {
			ball[i] = rand() % 7 + 1;
		}
		draw_real_time(ball, array, hang, lie);
	}
	while (1) {
		cct_gotoxy(x, y);
		state_ = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		for (int i = 1; i <= hang; ++i) {
			if (MY == 2 * i - 1) {
				flag_y = i;
			}
		}
		for (int i = 1; i <= lie; ++i) {
			if (MX == 4 * i - 2|| MX == 4 * i - 1) {
				flag_x = i;
			}
		}
		if (flag_y == 0 || flag_x == 0) {
			cout << "位置非法";
		}
		else {
			cout << char('A' + flag_y-1) << " 行"<< flag_x << " 列";
			if (MAction == MOUSE_LEFT_BUTTON_CLICK&& array[flag_y - 1][flag_x - 1]!=0&&flag_first==0) {
				cct_showstr(4 * flag_x-2, 2*flag_y-1, "★", array[flag_y - 1][flag_x - 1], COLOR_HWHITE, 1, -1);    //选中了就不能再选其他的！！！
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				flag_first = 1;
				array_src_x = flag_y - 1;
				array_src_y = flag_x - 1;
			}
			else if (MAction == MOUSE_LEFT_BUTTON_CLICK && array[flag_y - 1][flag_x - 1] == 0 && flag_second == 0) {
				flag_second = 1;
				array_dst_x = flag_y - 1;
				array_dst_y = flag_x - 1;
			}
		}
		if (MAction == MOUSE_RIGHT_BUTTON_CLICK) {
			break;
		}
		flag_x = 0;
		flag_y = 0;
		if (flag_first == 1 && flag_second == 1) {
			int visited[9][9] = { 0 },result = 0;
			search_for_path(array, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie, visited, &result, 4, array_src_x, array_src_y);
			if (result == 1) {
				int visited_1[9][9] = { 0 }, result_1 = 0;
				search_for_path(array, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie, visited_1, &result_1, 9, array_src_x, array_src_y);//起始array[str[0] - 'A'][str[1] - '0' - 1]
				if (gongnenghao == 2) {
					update_array(array, flag_y, flag_x, flag_first, flag_second, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie,ball,&sum_score);
					if (judge_full(array, hang, lie)) {
						cct_gotoxy(0, 21);
						break;
					}
				}
			}
			else {
				if (gongnenghao == 2) {
					break;
				}
			}
			if (gongnenghao == 1) {
				break;
			}
		}
	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_disable_mouse();
}
//更新变量的值，更新得分、各色球消除总数统计
void update_array(int array[][9], int& flag_y, int& flag_x, int& flag_first, int& flag_second, int& array_src_x, int& array_src_y, int& array_dst_x, int& array_dst_y,int hang,int lie,int ball[],int *sum_score)
{
	int tmp, count = 0;
	tmp = array[array_src_x][array_src_y];
	array[array_src_x][array_src_y] = 0;
	array[array_dst_x][array_dst_y] = tmp;
	get_score(array, sum_score, hang, lie, ball,8);//再写一个累计得分的函数
	for (int i = 0; i < 3; ++i) {
		ball[i] = rand() % 7 + 1;
	}
	for (int i = 0; i < 3; ++i) {
		cct_showstr(47 + 4 * i, 5, "○", ball[i], COLOR_HWHITE, 1, -1);
	}
	flag_y = 0;
	flag_x = 0;
	flag_first = 0;
	flag_second = 0;
	array_src_x = 0;
	array_src_y = 0;
	array_dst_x = 0;
	array_dst_y = 0;
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cct_gotoxy(53, 1);
	cout << *sum_score;
	cct_showstr(47, 9, "○", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << ':' << setw(2) << cal_number(array, hang, lie, 0) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, 0)) / hang / lie * 100 << "%)";
	for (int i = 1; i < 8; ++i) {
		cct_showstr(47, 9 + i, "○", i, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		int x, y;
		cct_getxy(x, y);
		cct_gotoxy(x, y);
		cout << ':' << setw(2) << cal_number(array, hang, lie, i) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)";
	}
	cct_setcolor(COLOR_BLACK,COLOR_WHITE);
	return;
}
//动画移动
void movement_ball(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int result, int gongnenghao,int _x,int _y)
{
	if (result==0&&(gongnenghao==9|| gongnenghao == 10|| gongnenghao == 11|| gongnenghao == 12)) {//移动
		//上移
		if (gongnenghao == 10) {
			for (int y = 2 * src_x + 1; y >= 2 * dst_x + 1; y--) {
				int x = 4 * src_y + 2;
				if (y % 2 == 1) {
					cct_showstr(x, y + 1, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				}
				else {
					cct_showstr(x, y + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "○", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 11) {
			for (int x = 4 * src_y + 2; x <= 4 * dst_y + 2; x++) {//右移
				int y = 2 * src_x + 1;
				if (x % 2 == 0) {
					if (x % 4 == 0) {
						cct_showstr(x - 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
					}
					else {
						cct_showstr(x - 2, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
				}
				else {
					cct_showstr(x - 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "○", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 12) {
			for (int x = 4 * src_y + 2; x >= 4 * dst_y + 2; x--) {//左移
				int y = 2 * src_x + 1;
				if (x % 2 == 0) {
					if (x % 4 == 0) {
						cct_showstr(x + 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
					}
					else {
						cct_showstr(x + 2, y, "║", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
				}
				else {
					cct_showstr(x + 2, y, " ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "○", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 9) {
			//下移 
			for (int y = 2 * src_x + 1; y <= 2 * dst_x + 1; y++) {
				int x = 4 * src_y + 2;
				if (y % 2 == 1) {
					cct_showstr(x, y - 1, "═", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				}
				else {
					cct_showstr(x, y - 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "○", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_gotoxy(0, 20);
	}
	return;
}
