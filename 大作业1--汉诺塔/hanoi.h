/* 计科 2353761 王皙晶 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

const char ch = ' ';
const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
const int LENGTH = 23;
const int SPACE = 9;
const int Y = 2;


int  hanoi_menu (void); //函数声明里必须加上void，否则报错
void shuru(char* src, char* tmp, char* dst,int*n,int gongnenghao);
void hanoi(int n, char src, char tmp, char dst, int gongnenghao);
void print(int x, int y);
void draw_column(char src,char dst,int gongnenghao,int n);
void draw_original(char src,int n,int gongnenghao);
void print_column(int n, char src, char dst, int gongnenghao);
void chushihua(char src, int n);
void movement(char src, char dst, int n);
void set_sudu(char src, char dst, int layers,int gongnenghao);
void mark_number(int n, char src, char dst);
int game_9_shuru (void);
void game_9_control (char dst,int layers);
void print_title(int gongnenghao, char src, char dst, int n);
void print_shu();
void yanshipanduan(int gongnenghao, char src, char dst, int n);
void panduan_function(int gongnenghao, int n, char src, char dst);
void chushihua2 (int gongnenghao);
void game_9_yidong(char srcc1, char dstt1, int m);
