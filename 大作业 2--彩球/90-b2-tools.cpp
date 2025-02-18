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

/*本文件功能：
放一些内部数组/图形方式公用的函数，如判断结束等
放置公用函数--
1.行列的输入
2.小题判断结束等待输入end
3.每个功能执行完一次后都需要的array恢复0
4.路径搜索函数
5.判断数组是否满
6.计算得分*/


//计算得分
int get_score(int array[][9], int* sum_score, int hang, int lie, int ball[], int gongnenghao)
{
	/*得分规则：只有横着，竖着超过五个才可消除得分,消除几个得几分哈*/
	int number1[8] = { 0 };
	for (int i = 0; i < 8; ++i) {
		number1[i] = cal_number(array, hang, lie, i);
	}
	int k = 0, m = 0, x = 0, y = 0, tmp = 0;;
	int tmp_score = 0, count = 0;
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] != 0) {
				//横着找可以消除的
				for (k = j; k >= 0; --k) {
					if (array[i][k] != array[i][j]) {
						k++;
						break;
					}
					++count;
				}
				for (m = j + 1; m < lie; ++m) {
					if (array[i][m] != array[i][j]) {
						m--;
						break;
					}
					++count;
				}
				if (count >= 5) {//得完分如何消除？k记录着左边界，m记录右边界
					tmp_score = tmp_score + count;
					for (int q = k; q <= m; ++q) {
						array[i][q] = 0;
						if (gongnenghao == 8) {
							cct_showstr(4 * q + 2, 2 * i + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
						}
					}
					count = 0;
				}
				else {
					count = 0;
					//竖着找可以消除的
					for (k = i; k >= 0; --k) {
						if (array[k][j] != array[i][j]) {
							k++;
							break;
						}
						++count;
					}
					for (m = i + 1; m < hang; ++m) {
						if (array[m][j] != array[i][j]) {
							m--;
							break;
						}
						++count;
					}
					if (count >= 5) {
						tmp_score = tmp_score + count;
						for (int q = k; q <= m; ++q) {
							array[q][j] = 0;
							if (gongnenghao == 8) {
								cct_showstr(4 * j + 2, 2 * q + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
							}
						}
						count = 0;
					}
					else {
						count = 0;
					}
				}
			}
		}
	}
	*sum_score = *sum_score + tmp_score;
	if (gongnenghao == 8 && tmp_score != 0) {
		cct_showstr(47, 9, "○", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << ':' << setw(2) << cal_number(array, hang, lie, 0) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, 0)) / hang / lie * 100 << "%)" << "  消除-0";
		for (int i = 1; i < 8; ++i) {
			cct_showstr(47, 9 + i, "○", i, COLOR_HWHITE, 1, -1);
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			int x, y;
			cct_getxy(x, y);
			cct_gotoxy(x, y);
			cout << ':' << setw(2) << cal_number(array, hang, lie, i) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)" << "  消除-" << setw(2) << number1[i] - cal_number(array, hang, lie, i) << "  ";
		}
	}
	if (tmp_score == 0) {
		while (tmp < 3 && !judge_full(array, hang, lie)) {
			x = int(fabs(rand() % hang));
			y = int(fabs(rand() % lie));
			if (array[x][y] == 0) {
				array[x][y] = ball[tmp];
				if (gongnenghao == 8) {
					cct_showstr(4 * y + 2, 2 * x + 1, "○", array[x][y], COLOR_HWHITE, 1, -1);
				}
				++tmp;
			}
		}
	}
	return tmp_score;
}
//判断array满否
bool judge_full(int array[][9], int hang, int lie)
{
	int flag = 0;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] == 0) {
				flag++;
			}
		}
	}
	if (flag == 0) {//说明全是非零，即满
		return 1;
	}
	else {
		return 0;
	}
}
//输入行、列
void Input(int* hang, int* lie)
{
	cct_cls();
	while (1) {
		cout << "请输入行数(7-9)：" << endl;
		cin >> *hang;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
		}
		else {
			cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
			if (*hang >= 7 && *hang <= 9) {
				while (1) {
					cout << "请输入列数(7-9)：" << endl;
					cin >> *lie;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
					}
					else {
						cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
						if (*lie >= 7 && *lie <= 9) {
							break;
						}
					}
				}
				break;
			}
		}
	}
	return;
}
//衔接--输入end进入下一小题
void print()
{
	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(0, y + 1);
	cout << "本小题结束，请输入End继续...";
	char str[4] = { 0 };
	cct_getxy(x, y);
	while (1) {
		cin.getline(str, 4);
		if (str[0] == 'e' || str[0] == 'E') {
			if (str[1] == 'n' || str[1] == 'N') {
				if (str[2] == 'd' || str[2] == 'D') {
					break;
				}
			}
		}
		cct_gotoxy(0, y+1);
		cout << "输入错误，请重新输入";
		cin.clear();
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 4); // 擦除
		cct_gotoxy(x, y);
	}
	return;
}
//初始化彩球数组，全归为0
void chushihua_array(int array[][9],int hang,int lie)//初始化
{
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			array[i][j] = 0;
		}
	}
	return;
}
//路径搜索
void search_for_path(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int hang, int lie, int visited[][9], int* result, int gongnenghao, int x, int y)//起始array[str[0] - 'A'][str[1] - '0' - 1]
{
	visited[src_x][src_y] = int('*' - '0');//表示已经访问过
	if (src_x == dst_x && src_y == dst_y) {
		*result = 1;
		if (gongnenghao == 2) {
			cout << "查找结果数组：" << endl;//cout << "找到了";
			print_array(hang, lie, visited, visited, 2);
			cout << "移动路径(不同色标识)：" << endl;
			print_array(hang, lie, array, visited, 3);
		}
		else if(gongnenghao==3){
			cout << "移动后的数组(不同色标识)：" << endl;
		}
		return;
	}
	if (array[src_x + 1][src_y] == 0 && src_x + 1 < hang && visited[src_x + 1][src_y] == 0) {//向下搜索g=9
		movement_ball(array, src_x, src_y, src_x+1, src_y,*result,gongnenghao,x,y);                 //!!
		search_for_path(array, src_x + 1, src_y, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x+1, src_y, src_x, src_y, *result, gongnenghao+1,x,y);// 可能的回溯
	}
	if (array[src_x - 1][src_y] == 0 && src_x - 1 >= 0 && visited[src_x - 1][src_y] == 0) {//向上搜索g=10
		movement_ball(array, src_x, src_y, src_x - 1, src_y, *result, gongnenghao+1,x,y);
		search_for_path(array, src_x - 1, src_y, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x-1, src_y, src_x, src_y, *result, gongnenghao,x,y);
	}
	if (array[src_x][src_y + 1] == 0 && src_y + 1 < lie && visited[src_x][src_y + 1] == 0) {//向右搜索g=11
		movement_ball(array, src_x, src_y, src_x , src_y+1, *result, gongnenghao+2,x,y);
		search_for_path(array, src_x, src_y + 1, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x, src_y+1, src_x, src_y, *result, gongnenghao+3,x,y);
	}
	if (array[src_x][src_y - 1] == 0 && src_y - 1 >= 0 && visited[src_x][src_y - 1] == 0) {//向左搜索g=12
		movement_ball(array, src_x, src_y, src_x, src_y - 1, *result, gongnenghao+3,x,y);
		search_for_path(array, src_x, src_y - 1, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x, src_y-1, src_x, src_y, *result, gongnenghao+2,x,y);
	}
	//每次回溯就会到这里
	if (src_x == x && src_y == y && *result == 0) {
		int tmpx,tmpy;
		cct_getxy(tmpx, tmpy);
		cct_gotoxy(0, tmpy + 1);
		cout << "找不到相关路径" << endl;
	}
	return;
}