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
放内部数组方式实现的个函数 功能ABC*/


//数组内彩球生成
void array_A(int hang, int lie, int array[][9], int number_ball)
{
	int x, y, count = 0, color;
	//随机分布5个随机颜色的球，数字就代表球的颜色1-7，7种颜色
	while (1) {
		color = rand() % 7 + 1;
		x = rand() % hang;
		y = rand() % lie;
		if (array[x][y] == 0) {
			array[x][y] = color;
			count++;
		}
		if (count == number_ball) {
			break;
		}
	}
	return;
}
//打印数组
void print_array(int hang, int lie, int array[][9], int visited[][9], int gongnenghao)
{
	//先打印第一行
	cout << "  |  ";
	for (int i = 1; i <= lie; ++i) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 1; i <= lie; ++i) {
		cout << "---";
	}
	cout << endl;
	for (int i = 0; i < hang; ++i) {
		cout << char('A' + i) << " |  ";
		for (int j = 0; j < lie; j++) {
			if (array[i][j] != 0 && gongnenghao != 3 || visited[i][j] != 0 && gongnenghao == 3) {//功能号3是为移动路径0显色用的/功能号1&2等价哈
				int x, y;
				cct_getxy(x, y);
				cct_showch(x, y, char('0' + array[i][j]), COLOR_HYELLOW, array[i][j]);
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "  ";
			}
			else {
				cout << array[i][j] << "  ";
			}
		}
		cout << endl;
	}
	return;
}
//接下来三个彩球的生成
void generation_of_3_ball(int ball[])
{
	//cout << endl;
	//cout << "接下来3个彩球的颜色分别是: ";
	for (int i = 0; i < 3; ++i) {
		ball[i]=rand() % 7 + 1;
		cout << ball[i] << ' ';
	}
	cout << endl;
	return;
}
//移动后数组的更新、修改
void change_array_and_print(int src_x, int src_y, int dst_x, int dst_y,int array[][9],int hang,int lie,int ball[],int*sum_score)
{
	int tmp,count=0, tmp_score;
	tmp=array[src_x][src_y];
	array[src_x][src_y] = 0;
	array[dst_x][dst_y] = tmp;
	tmp_score=get_score(array, sum_score, hang, lie,ball,1);//再写一个累计得分的函数
	print_array(hang, lie, array, array, 1);
	cout << "本次得分：" << tmp_score << "  总得分：" << *sum_score << endl;
	
	return;
}
//彩球移动指令
void input_move_instruction(int src, int dst, int array[][9], int hang, int lie, int gongnenghao, int* sum_score)
{
	int x, y, ball[3] = { 0 };
	char str1[3] = { 0 }, str2[3] = { 0 };
	cout << endl;
	cout << "接下来3个彩球的颜色分别是: ";
	generation_of_3_ball(ball);
	while (1) {
		cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
		cct_getxy(x, y);
		judge_input(str1, hang, lie, x, y);
		if (array[str1[0] - 'A'][str1[1] - '0' - 1] == 0) {
			cout << "起始位置为空，请重新输入. " << endl;
		}
		else {
			cout << "输入为" << str1[0] << "行" << str1[1] << "列 " << endl;
			break;
		}
	}
	while (1) {
		cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
		cct_getxy(x, y);
		judge_input(str2, hang, lie, x, y);
		if (array[str2[0] - 'A'][str2[1] - '0' - 1] != 0) {
			cout << "目标位置非空，请重新输入. " << endl;
		}
		else {
			cout << "输入为" << str2[0] << "行" << str2[1] << "列 " << endl;
			break;
		}
	}
	//寻找路径函数
	int visited[9][9] = { 0 };
	int result = 0;
	search_for_path(array, int(str1[0] - 'A'), int(str1[1] - '0' - 1), int(str2[0] - 'A'), int(str2[1] - '0' - 1), hang, lie, visited, &result, gongnenghao, int(str1[0] - 'A'), int(str1[1] - '0' - 1));
	if (gongnenghao != 2 && result != 0) {
		change_array_and_print(int(str1[0] - 'A'), int(str1[1] - '0' - 1), int(str2[0] - 'A'), int(str2[1] - '0' - 1), array, hang, lie, ball, sum_score);
	}
	result = 0;
	return;
}
//判断移动输入指令
void judge_input(char str[], int hang, int lie, int x, int y)
{
	while (1) {
		cin.getline(str, 3);
		if ((str[0] - 'A' >= 0 && str[0] - 'A' < hang) || (str[0] - 'a' >= 0 && str[0] - 'a' < hang)) {
			if (str[0] >= 'a' && str[0] <= 'z') {
				str[0] = str[0] - 32;
			}//转大写存储
			if (str[1] - '0' >= 1 && str[1] - '0' <= lie) {
				break;
			}
		}
		cct_gotoxy(0, y + 1);
		cout << "输入错误，请重新输入";
		cin.clear();
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 8); // 擦除
		cct_gotoxy(x, y);
	}
	return;
}
