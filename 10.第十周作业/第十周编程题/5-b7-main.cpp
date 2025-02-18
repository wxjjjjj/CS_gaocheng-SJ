/*王皙晶 2353761 计科*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include"5-b7.h"

using namespace std;
int bushu = 1;
int a[10], b[10], c[10];  //存储盘号
int d, e, f;            //存储a，b，c柱的盘数
static int sudushijian;//移动延时的时间

void sudushijianshezhi(int sudu,int xianshi)
{  //延时设置sudu；显示内部数组xianshi;sudushijianshezhi(速度时间设置）
	if (sudu == 1) {
		sudushijian = 1000;
	}
	else if (sudu == 2) {
		sudushijian = 500;
	}
	else if (sudu == 3) {
		sudushijian = 200;
	}
	else if (sudu == 4) {
		sudushijian = 50;
	}
	else {
		sudushijian = 0;
	}
	return;
}

void chushihua(char src, int n)
{
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

void print(int n, char src, char dst,int xianshi)
{
	int i, j, m;
	
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


	if (xianshi) {
		cout << "A:";
	for (m = 0; m < 10; ++m) {
		if (a[m] > 0) {
			cout << setw(2) << a[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "B:";
	for (m = 0; m < 10; ++m) {
		if (b[m] > 0) {
			cout << setw(2) << b[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "C:";
	for (m = 0; m < 10; ++m) {
		if (c[m] > 0) {
			cout << setw(2) << c[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << endl;
	}
	
	int x = 11, y = 26;
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
	y = 26;
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
	y = 26;
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


void hanoi(int n, char src, char tmp, char dst,int xianshi)  //n是盘号(也是层数) 从上到下为1，2，3...
{
	if (n == 1) {
		cct_gotoxy(20, 32);
		cout << "第" << setw(4) << bushu << "步(" <<  n << "#: " << src << "-->" << dst<<") ";
		
		print(n, src, dst, xianshi);
		if(sudushijian)
			Sleep(sudushijian);
		else {
			int huiche;
			while(1){
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
		++bushu;
		return;
	}
	hanoi(n - 1, src, dst, tmp,xianshi);
	cct_gotoxy(20, 32);
	cout << "第" << setw(4) << bushu << "步(" << n << "#: " << src << "-->" << dst << ") ";
	
	print(n, src, dst, xianshi);
	if (sudushijian)
		Sleep(sudushijian);
	else {
		int huiche;
		while (1) {
			huiche = _getch();
			if (huiche == 13) {
				break;
			}
		}
	}
	++bushu;
	hanoi(n - 1, tmp, src, dst,xianshi);
	return;

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int layers;
	char src, dst, tmp;//layers是层，src是起始柱,dst是目标柱,tmp是辅助柱

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
										if (src == dst || src == dst + 32 || src == dst - 32) {
											if (src >= 'a' && src <= 'c') {
												src = src - 32;
											}
											if (dst >= 'a' && dst <= 'c') {
												dst = dst - 32;
											}
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
	}                //输入部分处理完毕

	if (src >= 'a' && src <= 'c') {
		src = src - 32;
	}
	if (dst >= 'a' && dst <= 'c') {
		dst = dst - 32;
	}//src,dst转大写

	tmp = 'A' + 'B' + 'C' - src - dst;  //巧妙

	int sudu,xianshi;//显示
	
	while (1) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
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
	while (1) {
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> xianshi;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
		}
		else {
			if (xianshi==0 || xianshi == 1)
				break;
		}
	}
	
	cct_cls();//清屏
	cout << "从 " << src << " 移动到 " << dst << " ,共 " << layers << " 层，延时设置为 " << sudu << ", ";
	if (xianshi == 0) {
		cout << "不显示内部数组值" << endl;
	}
	else {
		cout<< "显示内部数组值" << endl;
	}
	
	chushihua(src, layers);
	sudushijianshezhi(sudu, xianshi);
	if (xianshi) {
		cct_gotoxy(20, 32);
		cout << "初始:                ";

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
		if (sudushijian)
			Sleep(sudushijian);
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
	cct_gotoxy(9, 27);
	cout << "=========================" << endl;
	cct_gotoxy(9, 28);
	cout << "  A         B         C" << endl;
	int x = 11, y = 26;
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
	y = 26;
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
	y = 26;
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
	if (sudushijian)
		Sleep(sudushijian);
	else {
		int huiche;
		while (1) {
			huiche = _getch();
			if (huiche == 13) {
				break;
			}
		}
	}
	hanoi(layers, src, tmp, dst,xianshi);
	

	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
