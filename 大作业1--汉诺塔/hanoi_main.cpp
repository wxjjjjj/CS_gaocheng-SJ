/* 计科 2353761 王皙晶 */
#include <iostream>
#include <iomanip>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int i,layers,x,y=0;
	char src,tmp,dst;
	while (1) {
		cct_cls();
		i = hanoi_menu();
		if (i == 48) {//0--直接结束
			return 0;
		}
		cct_getxy(x, y);
		cct_gotoxy(0, y + 3);

		shuru(&src, &tmp, &dst, &layers,i-48);                                                //加功能号 只有5不用
		chushihua(src, layers);
		set_sudu(src, dst, layers,i-48);                                                      //加功能号 只有4&8用
		
		draw_column(src, dst, i - 48, layers);                                                 //加判断条件，只有5/6/7/8/9用
		draw_original(src, layers,i-48);                                                       //加判断条件和功能号，只有6/7/8/9用
		chushihua2(i - 48);                                                                   //判断条件改写，只有4/8/9
		hanoi(layers, src, tmp, dst, i - 48);                                                  //改判断条件，只有5/6/7/9不用
		switch (i) {
			case 55://7
				mark_number(1, src, layers % 2 == 1 ? dst : tmp);
				movement(src, layers % 2 == 1 ? dst : tmp, 1);
				break;
			case 57://9
				game_9_control(dst, layers);
				break;
		}
		if (i - 48 == 1 || i - 48 == 2 || i - 48 == 3) {
			cct_getxy(x, y);
		}
		else {
			y = 39;
		}
		print(0, y + 1);
	}
	return 0;
}
