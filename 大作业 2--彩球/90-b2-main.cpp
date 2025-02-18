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
存放main函数和菜单函数*/

int color_linez_menu()
{
	cout << "---------------------------------" << endl;
	cout << "A.内部数组，随机生成初始5个球" << endl;
	cout << "B.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "C.内部数组，完整版" << endl;
	cout << "D.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "E.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "F.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "G.cmd图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
	return int(_getche()); //注意 1返回的int值是49
}

int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int i,hang=0,lie=0,sum_score=0;
	int array[9][9] = { 0 };
	/* srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可*/
	cct_setfontsize("新宋体", 24, 0);
	srand((unsigned int)(time(0)));

	while (1) {
		cct_cls();
		i = color_linez_menu();
		if (i >= int('a') && i <= int('g') || i >= int('A') && i <= int('G') || i == int('Q') || i == int('q')) {
			Sleep(150);
			if (i == int('Q') || i == int('q')) {
				return 0;
			}
			Input(&hang, &lie);
			if (i == int('A') || i == int('a') || i == int('D') || i == int('E') || i == int('d') || i == int('e')) {
				array_A(hang, lie, array, 5);
				cout << "初始数组:" << endl;
				print_array(hang, lie, array, array, 1);
				if (i == int('D') || i == int('E') || i == int('d') || i == int('e')) {
					draw_border_pause();
					if (i == int('E') || i == int('e')) {
						draw_border_pro(array, hang, lie);
					}
					else {
						draw_border(array, hang, lie);
					}
				}
			}
			if (i == int('B') || i == int('b')) {
				array_A(hang, lie, array, int(hang * lie * 0.6));
				cout << "当前数组:" << endl;
				print_array(hang, lie, array, array, 1);
				input_move_instruction(0, 0, array, hang, lie, 2, &sum_score);
			}
			if (i == int('C') || i == int('c')) {
				array_A(hang, lie, array, 5);
				while (1) {
					cout << "当前数组:" << endl;
					print_array(hang, lie, array, array, 1);
					input_move_instruction(0, 0, array, hang, lie, 3, &sum_score);
					if (judge_full(array, hang, lie)) {//满，则结束
						break;
					}
				}
				sum_score = 0;
			}
			if (i == int('F') || i == int('f')) {
				array_A(hang, lie, array, int(hang * lie * 0.6));
				draw_border_pro(array, hang, lie);
				move_by_mouse(hang, lie, array, 1);
			}
			if (i == int('G') || i == int('g')) {
				array_A(hang, lie, array, 5);
				draw_border_pro(array, hang, lie);
				move_by_mouse(hang, lie, array, 2);
			}
			chushihua_array(array, hang, lie);
			print();
		}
		else {
			continue;
		}
	}
	return 0;
}